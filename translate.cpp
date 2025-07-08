#include "translate.h"
#include "utils.h"
#include <iostream>
#include <fstream> // Для работы с файлами

using namespace std;

// Инициализация глобальных словарей
unordered_map<string, string> engToRus;
unordered_map<string, string> rusToEng;

// Перевод с английского на русский
string translateToRussian(string phrase) {
    phrase = toLower(phrase);

    if (engToRus.count(phrase)) {
        return engToRus[phrase];
    }

    string guess = findClosestMatch(phrase, engToRus);
    if (!guess.empty()) {
        cout << "Похожее слово: " << guess << endl;
        return engToRus[guess];
    }

    return "[перевод не найден]";
}

// Перевод с русского на английский
string translateToEnglish(string phrase) {
    phrase = toLower(phrase);

    if (rusToEng.count(phrase)) {
        return rusToEng[phrase];
    }

    string guess = findClosestMatch(phrase, rusToEng);
    if (!guess.empty()) {
        cout << "Похожее слово: " << guess << endl;
        return rusToEng[guess];
    }

    return "[translation not found]";
}

// Поиск самого похожего слова в словаре
string findClosestMatch(const string& phrase, const unordered_map<string, string>& dictionary) {
    int minDistance = numeric_limits<int>::max();
    string bestMatch = "";

    for (const auto& pair : dictionary) {
        int dist = levenshtein(phrase, pair.first);
        if (dist < minDistance) {
            minDistance = dist;
            bestMatch = pair.first;
        }
    }

    return bestMatch;

    // Сохраняет словари в файл формата: eng:hello=привет
    void saveDictionaryToFile(const string & filename) {
        ofstream out(filename);
        if (!out) {
            cerr << "Не удалось открыть файл для записи: " << filename << endl;
            return;
        }

        for (const auto& pair : engToRus) {
            out << "eng:" << pair.first << "=" << pair.second << "\n";
        }

        for (const auto& pair : rusToEng) {
            out << "rus:" << pair.first << "=" << pair.second << "\n";
        }

        out.close();
    }

    // Загружает словари из файла
    void loadDictionaryFromFile(const string & filename) {
        ifstream in(filename);
        if (!in) {
            cerr << "Файл не найден, будет создан новый при сохранении.\n";
            return;
        }

        string line;
        while (getline(in, line)) {
            size_t colonPos = line.find(':');
            size_t equalPos = line.find('=');

            if (colonPos == string::npos || equalPos == string::npos) continue;

            string lang = line.substr(0, colonPos);
            string key = line.substr(colonPos + 1, equalPos - colonPos - 1);
            string value = line.substr(equalPos + 1);

            if (lang == "eng") {
                engToRus[key] = value;
            }
            else if (lang == "rus") {
                rusToEng[key] = value;
            }
        }

        in.close();
    }
}

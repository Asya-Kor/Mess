#include "menu.h"
#include "translate.h"
#include "utils.h"
#include <iostream>

using namespace std;

// Отображение меню пользователю
void showMenu() {
    cout << "\nMess Translate — ОФЛАЙН-ПЕРЕВОДЧИК\n";
    cout << "1. Перевести с английского на русский\n";
    cout << "2. Перевести с русского на английский\n";
    cout << "3. Обучить перевод (добавить слово)\n";
    cout << "0. Выход\n";
    cout << "Выберите опцию: ";
}

// Добавление нового перевода
void addTranslation() {
    string langFrom, wordFrom, wordTo;

    cout << "Введите язык источника (eng/rus): ";
    cin >> langFrom;
    cin.ignore();

    cout << "Введите слово или фразу: ";
    getline(cin, wordFrom);

    cout << "Введите перевод: ";
    getline(cin, wordTo);

    wordFrom = toLower(wordFrom);
    wordTo = toLower(wordTo);

    if (langFrom == "eng") {
        engToRus[wordFrom] = wordTo;
        rusToEng[wordTo] = wordFrom;
    } else {
        rusToEng[wordFrom] = wordTo;
        engToRus[wordTo] = wordFrom;
    }

    cout << "Перевод добавлен!" << endl;
}

// Загрузка начальных переводов
void preloadData() {
    engToRus["hello"] = "привет";
    rusToEng["привет"] = "hello";

    engToRus["world"] = "мир";
    rusToEng["мир"] = "world";

    engToRus["cat"] = "кот";
    rusToEng["кот"] = "cat";

    engToRus["dog"] = "собака";
    rusToEng["собака"] = "dog";

    engToRus["good morning"] = "доброе утро";
    rusToEng["доброе утро"] = "good morning";
}

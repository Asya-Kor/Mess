#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <string>
#include <unordered_map>

// Англо-русский и русско-английский словари
extern std::unordered_map<std::string, std::string> engToRus;
extern std::unordered_map<std::string, std::string> rusToEng;

// Перевод с английского на русский
std::string translateToRussian(std::string phrase);

// Перевод с русского на английский
std::string translateToEnglish(std::string phrase);

// Поиск самого похожего слова в словаре
std::string findClosestMatch(const std::string& phrase, const std::unordered_map<std::string, std::string>& dictionary);

// Сохраняет переводы в файл
void saveDictionaryToFile(const std::string& filename);

// Загружает переводы из файла
void loadDictionaryFromFile(const std::string& filename);

#endif // TRANSLATE_H

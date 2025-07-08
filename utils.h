#ifndef UTILS_H
#define UTILS_H

#include <string>

// Преобразование строки в нижний регистр
std::string toLower(std::string str);

// Расстояние Левенштейна между двумя строками
int levenshtein(const std::string& s1, const std::string& s2);

#endif // UTILS_H

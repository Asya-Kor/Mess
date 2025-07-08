#include <iostream>
#include "menu.h"
#include "translate.h"

using namespace std;

int main() {
    setlocale(LC_ALL, ""); // Поддержка русского языка в консоли
    loadDictionaryFromFile("data.txt"); // Загружаем словарь
    preloadData(); // Добавляем базовые слова

    int choice;
    string input;

    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Введите английскую фразу: ";
                getline(cin, input);
                cout << "Перевод: " << translateToRussian(input) << endl;
                break;

            case 2:
                cout << "Введите русскую фразу: ";
                getline(cin, input);
                cout << "Translation: " << translateToEnglish(input) << endl;
                break;

            case 3:
                addTranslation();
                saveDictionaryToFile("data.txt"); // Сохраняем после добавления
                break;

            case 0:
                cout << "Выход. До свидания!\n";
                saveDictionaryToFile("data.txt"); // Сохраняем перед выходом
                break;

            default:
                cout << "Неверный выбор. Повторите.\n";
        }
    } while (choice != 0);

    return 0;
}

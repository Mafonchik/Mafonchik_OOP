#include <iostream>
#include <string>
#include "header.hpp"
using namespace std;

int main() {
    string text; // строка для модификации
    int n; // номер целевой буквы
    char old_value; // целевой символ
    char new_value; // символ, который следует использовать в качестве замены

    cout << "Введите строку для модификации: ";
    getline(cin, text);
    cout << "Введите номер целевой буквы: ";
    cin >> n;
    cout << "Введите целевой символ: ";
    cin >> old_value;
    cout << "Введите символ, который следует использовать в качестве замены: ";
    cin >> new_value;

    if (validation(n, old_value, text)) {
        cout << "Результат " << text;
    } else {
        string new_text = replace(text, n, old_value, new_value);
        cout << "Результат: " << new_text;
    }
    return 0;
}

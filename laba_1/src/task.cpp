#include "header.hpp"
#include <string>
using namespace std;

bool validation(int n, char old_value, const string& text) {
    // Подсчитываем количество вхождений old_value в текст
    int count = 0;
    for (char c : text) {
        if (c == old_value) {
            count++;
        }
    }

    // Если n <= 0 или n больше количества вхождений
    if (n <= 0 || n > count) {
        return true;
    }
    return false;
}

string replace(string text, int n, char old_value, char new_value) {
    int cnt = 0;
    string new_text = text;
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == old_value) {
            cnt++;
            if (cnt % n == 0) { // Каждый n-ый символ
                new_text[i] = new_value;
            }
        }
    }
    return new_text;
}

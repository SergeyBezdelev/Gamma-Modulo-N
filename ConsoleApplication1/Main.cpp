//Реализовать алгоритм шифрования данных «Шифрование методом гаммирования» По модулю N.
#include <iostream>
#include <string>
using namespace std;

const string alphabet = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

string encrypt(const string& plaintext, const string& key);// Функция для шифрования текста
string decrypt(const string& ciphertext, const string& key); // Функция для дешифрования текста
bool Check_string(string text);

int main() {
    setlocale(LC_ALL, "Russian");
    string plaintext;

    cout << "Введите текст для шифрования: ";
    getline(cin, plaintext);
    while (!Check_string(plaintext)) {
        cin.clear();
        cout << "Неправильно! Повторите ввод!" << endl;
        getline(cin, plaintext);
    }

    string gamma;
    cout << "Введите слово для гаммы: ";
    getline(cin, gamma);
    while (!Check_string(gamma)) {
        cin.clear();
        cout << "Неправильно! Повторите ввод!" << endl;
        getline(cin, gamma);
    }

    string encrypted_text = encrypt(plaintext, gamma);
    string decrypted_text = decrypt(encrypted_text, gamma);
    cout << "Зашифрованный текст: " << encrypted_text << endl;
    cout << "Расшифрованный текст: " << decrypted_text << endl;
    return 0;
}

string encrypt(const string& plaintext, const string& key) {
    string ciphertext;
    int key_length = key.length();                     //длинна гаммы
    int alphabet_size = alphabet.length();             //длинна алфавита
    for (int i = 0; i < plaintext.length(); ++i) {     //число в строке+число алфавите(с учётом ключа) % длинна алфавита
        char encrypted_char = alphabet[(alphabet.find(plaintext[i]) + alphabet.find(key[i % key_length])) % alphabet_size];
        ciphertext.push_back(encrypted_char);          //добавление в конец строки символа 
    }
    return ciphertext;
}

string decrypt(const string& ciphertext, const string& key) {
    string decrypted_text;
    int key_length = key.length();
    int alphabet_size = alphabet.length();
    for (int i = 0; i < ciphertext.length(); ++i) {
        char decrypted_char = alphabet[(alphabet.find(ciphertext[i]) - alphabet.find(key[i % key_length]) + alphabet_size) % alphabet_size];
        decrypted_text.push_back(decrypted_char);
    }
    return decrypted_text;
}

bool Check_string(string text) {          //выполняем проверку, что пользователь ввел строку из текста(пробелы учитываем) через посимвольное сравнение 
    int flag = 0;
    for (int i = 0; i < text.size(); i++)
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z') || (text[i] == ' ')) {
            flag++;
            if (flag == i) return true;
        }
        else return false;
}
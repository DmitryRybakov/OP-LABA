#include <iostream>
#include <string>

using namespace std;

string* get_word_list(string, int*, int&, char = ' ');  //отримання масиву окремих слів

bool contains(string, string*, int);  //визначення приналежності рядка масиву рядків

int find_index(string*, int, string);  //визначення індексу, на якому знаходиться заданий рядок, із заданого масиву рядків

int* replace_array(int*, int);  //заміна одного динамічного масиву новим більш компактним

void display_count(string*, int*, int);  //виведення слова та кількості його повторень

string join_words(string*, int, char = ' ');  //створення рядку із заданого масиву рядків

int main() {

    int size, factual_size;
    string text;
    factual_size = 0;
    setlocale(LC_ALL, "Ukrainian");
    cout << "Введiть рядок символiв: " << endl;
    setlocale(0, "C");
    getline(cin, text);
    cout << endl;
    size = text.length() / 2 + 1;
    int* count_list = new int[size];
    string* words = get_word_list(text, count_list, factual_size);
    int* counts = replace_array(count_list, factual_size);
    delete[] count_list;
    display_count(words, counts, factual_size);
    cout << endl;
    text = join_words(words, factual_size);
    setlocale(LC_ALL, "Ukrainian");
    cout << "Рядок вводу без дубликатiв: " << endl;
    setlocale(0, "C");
    cout << text;
    cout << endl;
    delete[] words;
    delete[] counts;
    return 0;
}

string* get_word_list(string text, int* count_list, int& factual_size, char sep) {
    int size, index;
    size = text.length() / 2 + 1;
    string* word_list = new string[size];
    string word;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] != sep) {
            word += text[i];
        }
        else {
            if (!contains(word, word_list, size) && !word.empty()) {
                word_list[factual_size] = word;
                count_list[factual_size] = 1;
                factual_size++;
            }
            else if (contains(word, word_list, size) && !word.empty()) {
                index = find_index(word_list, size, word);
                count_list[index] += 1;
            }
            word = "";
        }
    }

    if (!contains(word, word_list, size) && !word.empty()) {
        word_list[factual_size] = word;
        count_list[factual_size] = 1;
        factual_size++;
    }
    else if (contains(word, word_list, size) && !word.empty()) {
        index = find_index(word_list, size, word);
        count_list[index] += 1;
    }
    string* words = new string[factual_size];
    for (int i = 0; i < factual_size; i++) {
        words[i] = word_list[i];
    }
    delete[] word_list;
    return words;
}

bool contains(string item, string* list, int size) {
    int i = 0;
    bool found = false;
    while (i < size && !found) {
        if (list[i] == item) {
            found = true;
        }
        i++;
    }
    return found;
}

int find_index(string* list, int size, string item) {
    int index, i;
    i = 0;
    bool found = false;
    while (i < size && !found) {
        if (list[i] == item) {
            index = i;
            found = true;
        }
        i++;
    }
    return index;
}

int* replace_array(int* old_arr, int size) {
    int* new_arr = new int[size];
    for (int i = 0; i < size; ++i) {
        new_arr[i] = old_arr[i];
    }
    return new_arr;
}

void display_count(string* word_list, int* count_list, int size) {
    setlocale(LC_ALL, "Ukrainian");
    char write_Word[] = { "Слово:" };
    setlocale(0, "C");
    for (int i = 0; i < size; ++i) {
        setlocale(LC_ALL, "Ukrainian");
        cout << "Слово: ";
        setlocale(0, "C");
        cout << word_list[i];
        cout << "." << " ";
        setlocale(LC_ALL, "Ukrainian");
        cout << "Кiлькiсть повторень: ";
        setlocale(0, "C");
        cout << count_list[i] << endl;
    }
}

string join_words(string* list, int size, char sep) {
    string text;
    for (int i = 0; i < size; i++) {
        if (i != size - 1) {
            text += list[i] + sep;
        }
        else {
            text += list[i];
        }
    }
    return text;
}
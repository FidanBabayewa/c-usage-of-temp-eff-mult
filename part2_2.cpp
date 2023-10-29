#include <iostream>
#include <string>
using namespace std;
template <typename T, size_t N, typename K = T>
unsigned int count_element(T* array, const K& element) {
    unsigned int count = 0;
    for (size_t i = 0; i < N; ++i) {
        if (array[i] == element) {
            ++count;
        }
    }
    return count;
}

// Specialization for std::string array and char element
template <>
unsigned int count_element<std::string, 5, char>(std::string* array, const char& element) {
    unsigned int count = 0;
    for (size_t i = 0; i < 5; ++i) {
        for (char ch : array[i]) {
            if (ch == element) {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    int arr[5] = {1, 3, 5, 2, 3};
    cout << count_element<int, 5>(arr, 3) << endl;

    string arr2[5] = {" asd ", " bsd ", " asda ", " cccc ", " aaa "};
    cout << count_element<string, 5, char>(arr2, 'a') << endl;

    return 0;
}


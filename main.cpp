#include <iostream>
#include <locale>

int main() {
    setlocale(LC_ALL, "rus");

    unsigned int x;
    std::cout << "Введите целое число без знака: ";
    std::cin >> x;

    const int size = sizeof(unsigned int) * 8;
    unsigned short int X[size];

    for (int i = 0; i < size; i++) {
        unsigned short int bit_i = (x >> i) & 1;
        unsigned short int bit_sym = (x >> (size - 1 - i)) & 1;
        X[i] = bit_i | bit_sym;
    }

    std::cout << "Симметричный битовый массив: [";
    for (int i = 0; i < size; i++) {
        std::cout << X[i];
        if (i != size - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    int first_non_one = -1;
    for (int i = 0; i < size; i++) {
        if ((X[i] & 1) == 0) {
            first_non_one = i;
            break;
        }
    }

    if (first_non_one != -1) {
        std::cout << "Первый неединичный элемент: X[" << first_non_one << "] = " << X[first_non_one] << std::endl;
    }
    else {
        std::cout << "Все элементы массива равны 1" << std::endl;
    }

    return 0;
}

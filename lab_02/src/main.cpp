#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

double calculate_expression(double x) {
    return pow(x, 2) - pow(x, 2) + x * 4 - x * 5 + x + x;
}

int main() {
    while (true) {
        cout << "Введите количество итераций (или 'q' для выхода): ";
        string input;
        cin >> input;

        if (input == "q") break;

        try {
            int n = stoi(input);

            double x = 1.234; // фиксированное значение x
            auto start = high_resolution_clock::now();

            for (int i = 0; i < n; ++i) {
                calculate_expression(x);
            }

            auto end = high_resolution_clock::now();
            duration<double> duration = end - start;

            cout << "Время выполнения: " << duration.count() << " секунд\n\n";

        } catch (invalid_argument&) {
            cout << "Ошибка: введено не число. Завершение программы.\n";
            break;
        }
    }

    return 0;
}

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

double calculate_expression(double x) {
    return x * x - x * x + x * 4 - x * 5 + x + x;
}

int main() {
    while (true) {
        cout << "Введите количество итераций (или 'q' для выхода): ";
        string input_n;
        cin >> input_n;

        if (input_n == "q") break;

        cout << "Введите значение x: ";
        string input_x;
        cin >> input_x;

        try {
            int n = stoi(input_n);
            double x = stod(input_x);

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

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result = result * base;
    }
    return result;
}

int main(int argc, char* argv[]) {
        if (argc != 4) {
        cerr << "Usage: ./calc [+, -, ^] operand1 operand2\n";
        return 1;
    }

    string operation = argv[1];
    double operand1 = atof(argv[2]); 
    double operand2 = atof(argv[3]); 

    double result = 0.0;

    if (operation == "+") {
        result = add(operand1, operand2);
    } else if (operation == "-") {
        result = subtract(operand1, operand2);
    } else if (operation == "^") {
        int intExponent = static_cast<int>(operand2);
        if (operand2 != intExponent || intExponent < 0) {
            cerr << "Error: exponent must be a non-negative integer.\n";
            return 1;
        }
        result = power(operand1, intExponent);
    } else {
        cerr << "Unknown operation. Use +, -, or ^\n";
        return 1;
    }

    cout << "Result: " << result << "\n";
    return 0;
}

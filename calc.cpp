#include <iostream>
using namespace std;
class Calculator {
private:
    double num1, num2;

public:
    Calculator(double a, double b) {
        num1 = a;
        num2 = b;
    }
    double add() {
        return num1 + num2;
    }
    double subtract() {
        return num1 - num2;
    }
    double multiply() {
        return num1 * num2;
    }
    double divide() {
        if (num2 == 0) {
            cout << "Error: Division by zero is not allowed!" << endl;
            return 0;
        }
        return num1 / num2;
    }
};

int main() {
    double a, b;
    char op;
    char choice;

    do {
        cout << "Enter first number: ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b;
        cout << "Enter operator (+, -, *, /): ";
        cin >> op;
        Calculator calc(a, b);
        switch (op) {
            case '+':
                cout << "Result: " << calc.add() << endl;
                break;
            case '-':
                cout << "Result: " << calc.subtract() << endl;
                break;
            case '*':
                cout << "Result: " << calc.multiply() << endl;
                break;
            case '/':
                cout << "Result: " << calc.divide() << endl;
                break;
            default:
                cout << "Invalid operator!" << endl;
        }
        cout << "\nDo you want to perform another calculation? (y/n): ";
        cin >> choice;
        cout << "----------------------------------\n";

    } while (choice == 'y' || choice == 'Y');

    cout << "Calculator closed. Thank you!\n";
    return 0;
}

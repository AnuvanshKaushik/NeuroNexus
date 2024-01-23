
    Calculator:

#include <iostream>
#include <cmath>
using namespace std;

class Calculator {
public:
    void start() {
        char choice = 0;

        while (choice != '7') {
            displayMenu();

            cout << "Enter Your Choice" << endl;
            cin >> choice;

            switch (choice) {
            case '+':
                performBasicOperation('+');
                break;
            case '-':
                performBasicOperation('-');
                break;
            case '*':
                performBasicOperation('*');
                break;
            case '/':
                performBasicOperation('/');
                break;
            case '^':
                performPowerOperation();
                break;
            case '6':
                performAdditionalOperations();
                break;
            case '7':
                cout << "Exiting Calculator. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid Choice" << endl;
                clearInputBuffer();
            }
        }
    }

private:
    void displayMenu() {
        cout << "Calculator Menu" << endl;
        cout << "Press + for Addition" << endl;
        cout << "Press - for Subtraction" << endl;
        cout << "Press * for Multiplication" << endl;
        cout << "Press / for Division" << endl;
        cout << "Press ^ for Power" << endl;
        cout << "Press 6. for Additional Operations on Result" << endl;
        cout << "Press 7. to Exit" << endl;
    }

    double getOperand(const string& prompt) {
        double operand;
        cout << prompt;
        cin >> operand;
        while (cin.fail()) {
            cout << "Invalid input. Please enter a valid number." << endl;
            clearInputBuffer();
            cout << prompt;
            cin >> operand;
        }
        return operand;
    }

    void clearInputBuffer() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void performBasicOperation(char operation) {
        double operand = getOperand("Enter operand: ");

        switch (operation) {
        case '+':
            result += operand;
            break;
        case '-':
            result -= operand;
            break;
        case '*':
            result *= operand;
            break;
        case '/':
            if (operand != 0) {
                result /= operand;
            } else {
                cout << "Cannot Divide By Zero" << endl;
            }
            break;
        }

        cout << "Result: " << result << endl;
    }

    void performPowerOperation() {
        double base = getOperand("Enter the base: ");
        double exponent = getOperand("Enter the exponent: ");
        result = pow(base, exponent);
        cout << "Result: " << result << endl;
    }

    void performAdditionalOperations() {
        char operation;
        double operand;

        cout << "Enter the operation (+, -, *, /) to perform on the result: ";
        cin >> operation;

        operand = getOperand("Enter operand: ");

        switch (operation) {
        case '+':
            result += operand;
            break;
        case '-':
            result -= operand;
            break;
        case '*':
            result *= operand;
            break;
        case '/':
            if (operand != 0) {
                result /= operand;
            } else {
                cout << "Cannot Divide By Zero" << endl;
            }
            break;
        default:
            cout << "Invalid operation" << endl;
        }

        cout << "Result: " << result << endl;
    }

    double result;
};

int main() {
    Calculator realWorldCalculator;
    realWorldCalculator.start();
    return 0;
}

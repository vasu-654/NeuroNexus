#include <iostream>

using namespace std;

double add_numbers(double a, double b) {
    return a + b;
}

double subtract_numbers(double a, double b) {
    return a - b;
}

double multiply_numbers(double a, double b) {
    return a * b;
}

double divide_numbers(double a, double b) {
    if (b == 0) {
        throw "Error: Division by zero!";
    }
    return a / b;
}

int main() {
    char operation;
    double operand_1, operand_2, result;

    do {
        if (operation == '\0') {
            cout << "Enter the first operand: ";
            cin >> operand_1;
        } else {
            // If it's not the first iteration, use the previous result as the first operand
            operand_1 = result;
            cout << "result  = (" << result << ") ." << endl;
        }

        cout << "Enter operator (+, -, *, /) or 'q' to quit: ";
        cin >> operation;

        if (operation == 'q' || operation == 'Q') {
            break; 
        }

        try {
            cout << "Enter the second operand: ";
            cin >> operand_2;

            switch (operation) {
                case '+':
                    result = add_numbers(operand_1, operand_2);
                    break;
                case '-':
                    result = subtract_numbers(operand_1, operand_2);
                    break;
                case '*':
                    result = multiply_numbers
                (operand_1, operand_2);
                    break;
                case '/':
                    result = divide_numbers
                (operand_1, operand_2);
                    break;
                default:
                    cout << " Operation is not valid . !! Please try again." << endl;
                    continue;
            }

            cout << "Result: " << result << endl;

            // Asking the user if they want to use this result for the next calculation
            cout << "Do you want to use this result for the next calculation? (y/n): ";
            char choice;
            cin >> choice;

            if (choice != 'y' && choice != 'Y') {
                break;  // Exit the loop if the user doesn't want to continue
            }

        } catch (const char* error) {
            cout << error << endl;
            cout<<"Please enetr the details again"<<endl;
        }

    } while (true);

    cout << "Thanks . Do visit again" << endl;

    return 0;
}

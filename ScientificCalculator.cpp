#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

// Function to clear input buffer
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function to perform calculation based on operator
double calculate(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? a / b : numeric_limits<double>::quiet_NaN();
        case '^': return pow(a, b);
        default: return 0;
    }
}

int main() {
    double result = 0;
    char operation = '=';
    bool continueCalc = true;

    // ANSI escape codes for color (works in terminals supporting it)
    cout << "\033[36m"; // Cyan text
    cout << "=== Scientific Calculator - C++ Version ===\n";
    cout << "\033[35m"; // Magenta text
    cout << "Enter an expression or function (e.g., 2 + 3, sin(90), log(10), etc.)\n";
    cout << "Use operators: +, -, *, /, ^ | Functions: sin, cos, tan, sqrt, log, ln\n";
    cout << "Type 'exit' to quit or 'clear' to reset\n";
    cout << "\033[0m"; // Reset color

    while (continueCalc) {
        string input;
        cout << "\033[36m"; // Cyan prompt
        cout << ">> ";
        cout << "\033[0m";
        getline(cin, input);

        if (input == "exit") {
            continueCalc = false;
            continue;
        } else if (input == "clear") {
            result = 0;
            operation = '=';
            cout << "\033[35m"; // Magenta text
            cout << "Calculator reset. Enter new expression.\n";
            cout << "\033[0m";
            continue;
        }

        try {
            double value;
            char op;
            string function;

            // Check for scientific functions
            if (input.find("sin(") == 0) {
                size_t end = input.find(')');
                if (end != string::npos) {
                    value = stod(input.substr(4, end - 4));
                    result = sin(value * M_PI / 180); // Convert to radians
                }
            } else if (input.find("cos(") == 0) {
                size_t end = input.find(')');
                if (end != string::npos) {
                    value = stod(input.substr(4, end - 4));
                    result = cos(value * M_PI / 180);
                }
            } else if (input.find("tan(") == 0) {
                size_t end = input.find(')');
                if (end != string::npos) {
                    value = stod(input.substr(4, end - 4));
                    result = tan(value * M_PI / 180);
                }
            } else if (input.find("sqrt(") == 0) {
                size_t end = input.find(')');
                if (end != string::npos) {
                    value = stod(input.substr(5, end - 5));
                    result = (value >= 0) ? sqrt(value) : numeric_limits<double>::quiet_NaN();
                }
            } else if (input.find("log(") == 0) {
                size_t end = input.find(')');
                if (end != string::npos) {
                    value = stod(input.substr(4, end - 4));
                    result = (value > 0) ? log10(value) : numeric_limits<double>::quiet_NaN();
                }
            } else if (input.find("ln(") == 0) {
                size_t end = input.find(')');
                if (end != string::npos) {
                    value = stod(input.substr(3, end - 3));
                    result = (value > 0) ? log(value) : numeric_limits<double>::quiet_NaN();
                }
            } else {
                // Parse arithmetic expression
                size_t opPos = string::npos;
                for (char c : "+-*/^") {
                    opPos = input.find(c);
                    if (opPos != string::npos) {
                        op = c;
                        break;
                    }
                }

                if (opPos != string::npos) {
                    value = stod(input.substr(opPos + 1));
                    result = calculate(result, value, op);
                } else {
                    result = stod(input);
                }
            }

            // Display result
            cout << fixed << setprecision(6);
            if (isnan(result)) {
                cout << "\033[31m"; // Red text for error
                cout << "Error: Invalid input or division by zero\n";
                cout << "\033[0m";
            } else {
                cout << "\033[35m"; // Magenta text
                cout << "Result: " << result << "\n";
                cout << "\033[0m";
            }
        } catch (const invalid_argument& e) {
            cout << "\033[31m"; // Red text for error
            cout << "Error: Invalid number format\n";
            cout << "\033[0m";
        } catch (const out_of_range& e) {
            cout << "\033[31m"; // Red text for error
            cout << "Error: Number out of range\n";
            cout << "\033[0m";
        }
    }

    cout << "\033[36m"; // Cyan text
    cout << "Calculator closed. Goodbye!\n";
    cout << "\033[0m";

    return 0;
}
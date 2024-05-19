#include <bits/stdc++.h>
#include <math.h>
#include <sstream>
#define ll long long
#define all(c) c.begin(),c.end()
#define sz(c) int(c.size())
#define tr(a,it) for(auto it=a.begin(); it!=a.end(); it++)
#define present(c, x)(c.find(x) != c.end())
#define cpresent(c, x)(find(all(c), x) != c.end())
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define inf 10e9
#define MOD %(1000000007)
#define loop(i,s,e) for(int i=s; i<e; i++)
#define revloop(i,s,e) for(int i=s; i>=e; i--)

using namespace std;

double performOperation(double firstNum, double secondNum, char operation) {
    double result = 0.0;
    switch (operation) {
        case '+':
            result = firstNum + secondNum;
            break;
        case '-':
            result = firstNum - secondNum;
            break;
        case '*':
            result = firstNum * secondNum;
            break;
        case '/':
            if (secondNum == 0) {
                cout << "Error: Division by zero is not allowed." << endl;
                return 0;
            }
            result = firstNum / secondNum;
            break;
        case '%':
            if (secondNum == 0) {
                cout << "Error: Modulus with zero is not allowed." << endl;
                return 0;
            }
            result = fmod(firstNum, secondNum);
            break;
        default:
            cout << "Invalid operator." << endl;
            break;
    }
    return result;
}

double evaluateTrigFunction(double num, string function) {
    if (function == "sin") {
        return sin(num);
    } else if (function == "cos") {
        return cos(num);
    } else if (function == "tan") {
        return tan(num);
    } else {
        cout << "Invalid trigonometric function." << endl;
        return 0;
    }
}

double evaluateExpFunction(double num, string function) {
    if (function == "exp") {
        return exp(num);
    } else if (function == "log") {
        double base;
        cout << "Enter the base for the logarithm: ";
        cin >> base;
        return log(num) / log(base);
    } else {
        cout << "Invalid exponential function." << endl;
        return 0;
    }
}

int main() {
    double firstNum, secondNum;
    char operation;
    string trigFunction, expFunction;
    bool continueCalculation = true;

    while (continueCalculation) {
        cout << "Welcome to the Calculator!" << endl;
        cout << "Enter the first number: ";
        cin >> firstNum;

        cout << "Enter the operation (+, -, *, /, %, sin, cos, tan, exp, log): ";
        cin >> operation;

        if (operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '%') {
            cout << "Enter the second number: ";
            cin >> secondNum;
            double result = performOperation(firstNum, secondNum, operation);
            cout << "Result: " << firstNum << " " << operation << " " << secondNum << " = " << result << endl;
        } else if (operation == 's' || operation == 'c' || operation == 't') {
            cout << "Enter the trigonometric function (sin, cos, tan): ";
            cin >> trigFunction;
            double result = evaluateTrigFunction(firstNum, trigFunction);
            cout << "Result: " << trigFunction << "(" << firstNum << ") = " << result << endl;
        } else if (operation == 'e' || operation == 'l') {
            cout << "Enter the exponential function (exp, log): ";
            cin >> expFunction;
            double result = evaluateExpFunction(firstNum, expFunction);
            if (expFunction == "exp") {
                cout << "Result: exp(" << firstNum << ") = " << result << endl;
            } else {
                cout << "Result: log(" << firstNum << ") = " << result << endl;
            }
        } else {
            cout << "Invalid operation." << endl;
        }

        char choice;
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            continueCalculation = false;
        }
    }

    cout << "Thank you for using the Calculator!" << endl;
    return 0;
}
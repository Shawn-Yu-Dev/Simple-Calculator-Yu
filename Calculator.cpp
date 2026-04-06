#include <iostream>
#include <string>
#include <limits>
using namespace std;
int main() 
{
    char a;
    cout << "Hello! Welcome to this calculator. Would you like a tutorial? (Y/n)\n";
    cin >> a;
    if (a=='Y' || a=='y')
    {
        cout << "1. Please do not enter any letters (otherwise it will crash).\n";
        cout << "2. Please use the format [number][operator][number].\n";
    }
    cout << "So, press any key to start the calculation!   ";
    string b;
    cin >> b;
    while (true)
    {
        cout << "Calculation:";
        long double num1,num2 ;
        char op;
        if (!(cin >> num1 >> op >> num2)) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "\033[A\rInvalid input format. Please try again." << endl;
            continue;
        }
        cout << "\033[A\rCalculation:" << num1 << " " << op << " " << num2 << " = ";
        switch (op) 
        {
            case '+': cout << num1 + num2; break;
            case '-': cout << num1 - num2; break;
            case '*': cout << num1 * num2; break;
            case '/': 
                if (num2 == 0) cout << "\033[A\rError: Division by zero!";
                else cout << num1 / num2;
                break;
            default: cout << "\033[A\rError: Unknown operator '" << op << "'";
        }
        cout << "\n";
    }
    return 0;
}
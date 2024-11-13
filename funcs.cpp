#include <iostream>

using namespace std;

int readIntegerInLine() {
    int number;
    if (!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        return 0;
    }
    
    return number;
}

long double readDoubleInLine() {
    long double number;
    if (!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        return 0;
    }
    
    return number;
}
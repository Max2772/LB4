#include <iostream>
#include "head.h"

using namespace std;

long long readIntegerInLine() {
    long long number;
    while (!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Ошибка ввода. Введите заново: ";
    }
    
    return number;
}

long double readDoubleInLine() {
    long double number;
    while (!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Ошибка ввода. Введите заново: ";
    }
    
    return number;
}

int main(){
    cout << "Программа, для подсчета суммы отрицательных элементов массива M на N, расположенных выше побочной диагонали матрицы\n";
    cout << "Выполнил Бибиков Максим, группа 453502\n";
    while(true){
        cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы\n";
        int type = readIntegerInLine();
        if(type == 2)
            break;
        else if(type != 1 && type != 2)
            continue;
        
        cout << "Введите M(Количество строк массива): ";
        int M;
        while(true){
            M = readIntegerInLine();
            if(M < 0){
                cout << "Некорректный ввод, введие M: ";
                continue;;
            }
            break;
        }

        cout << "Введите N(Количество столбцов массива): ";
        int N;
        while(true){
            N = readIntegerInLine();
            if(N < 0){
                cout << "Некорректный ввод, введие N: ";
                continue;
            }
            break;
        }

        long long arr[M][N];

        for(int i = 0; i < M; i++){
            cout << "Введите элементы " << i+1 << " строки\n";
            for(int j = 0; j < N; j++){
                cout << "Введите первый " << j+1 << " элемент: ";
                arr[i][j] = readIntegerInLine();
            }
            cout << '\n';
        }

        long long sum = 0;
        int t = 0;
        for(int i = t; i < N; i++){
            for(int j = 0; j < M-t-1; j++){
                if(arr[j][i] < 0)
                    sum += arr[j][i];
            }
            t++;
        }

        cout << "Полученный массив:\n";
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                cout << arr[i][j] << " ";
            }
            cout << '\n';
        }
        cout << "\nПолученная сумма отрицательных элементов выше побочной диагонали: " << sum << "\n\n";

    }
    return 0;
}
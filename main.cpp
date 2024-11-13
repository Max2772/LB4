#include <iostream>
#include "head.h"

using namespace std;

int readIntegerInLine() {
    int number;
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
    cout << "Программа, для вывода массива k элементов, заменяющего местами минимальный и максимальный элемент\n";
    cout << "Выполнил Бибиков Максим, группа 453502\n";
    while(true){
        cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы\n";
        int type = readIntegerInLine();
        if(type == 2)
            break;
        else if(type != 1 && type != 2)
            continue;
        
        cout << "Введите k(Количесвто элементов массива): ";
        int k;
        while(true){
            k = readIntegerInLine();
            if(k < 0){
                cout << "Некорректный ввод, введие k: ";
                continue;
            }
            break;
        }

        long double arr[k];
        for(int i = 0; i < k; i++){
            cout << "Введите " << i+1 << " элемент массива: ";
            arr[i] = readDoubleInLine();
        }

        int ind_max = 0, ind_min = 0;
        for(int i = 0; i < k; i++){
            if(arr[i] <= arr[ind_min])
                ind_min = i;
            
            if(arr[i] >= arr[ind_max])
                ind_max = i;
        }

        for(int i = 0; i < k; i++){
            if(i == ind_max){
                std::cout << arr[ind_min] << " ";
            }
            else if(i == ind_min){
                std::cout << arr[ind_max] << " ";
            }
            else{
                std::cout << arr[i] << " ";
            }
        }

        cout << endl;

    }
    return 0;
}


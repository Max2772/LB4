#include <iostream>

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
    cout << "Программа, для смещения максимального элемента к левому углу, используя перестановки строк и столбцов\n";
    cout << "Выполнил Бибиков Максим, группа 453502\n";
    while(true){
        cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы\n";
        int type = readIntegerInLine();
        if(type == 2)
            break;
        else if(type != 1 && type != 2)
            continue;
        
        cout << "Введите N(Количество строк массива): ";
        int N;
        while(true){
            N = readIntegerInLine();
            if(N < 0){
                cout << "Некорректный ввод, введие M: ";
                continue;;
            }
            break;
        }

        cout << "Введите M(Количество столбцов массива): ";
        int M;
        while(true){
            M = readIntegerInLine();
            if(M < 0){
                cout << "Некорректный ввод, введие N: ";
                continue;
            }
            break;
        }

        long double **arr = new long double* [N];

        for(int i = 0; i < N; i++){
            arr[i] = new long double[M];
        }

        for(int i = 0; i < M; i++){
            cout << "Введите элементы " << i+1 << " строки\n";
            for(int j = 0; j < M; j++){
                cout << "Введите первый " << j+1 << " элемент: ";
                arr[i][j] = readDoubleInLine();
            }
            cout << '\n';
        }

        cout << "Введенный массив:\n";
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                cout << arr[i][j] << " ";
            }
            cout << '\n';
        }

        int max_i, max_j;
        long double max_num = arr[0][0];
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(arr[i][j] > max_num){
                    max_num = arr[i][j];
                    max_i = i; max_j = j;
                }
            }
        }

        if(max_j != 0){ // Смещение по столбцам
            long double *max_temp = new long double[N];
            long double *temp = new long double[N];
            for(int i = 0; i < N; i++){
                max_temp[i] = arr[i][max_j];            
            }
            for(int i = 0; i < N; i++){
                temp[i] = arr[i][0];            
            }

            for(int i = 0; i < N; i++){
                arr[i][0] = max_temp[i];           
            }

            for(int i = 0; i < N; i++){
                arr[i][max_j] = temp[i];           
            }

            delete [] max_temp;
            delete [] temp;
    }

    if(max_i != 0 && max_i != (N-1)){ // Смещение по строкам
        long double* buff = *(arr);
        arr[0] = arr[max_i];
        arr[max_i] = buff;
    }

        cout << "Полученный массив:\n";
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                cout << arr[i][j] << " ";
            }
            cout << '\n';
        }
        
        for(int i = 0; i < N; i++){
            delete [] arr[i];
        }

        delete [] arr;
    }
    return 0;
}
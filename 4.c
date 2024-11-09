#include <stdio.h>

int inputOutputNaturalNumber() {
    int number;

    printf("Введите натуральное число: ");
    scanf("%u", &number);

    if (number > 0) {
        return number;
    } else {
        printf("Введено не натуральное число.\n");
    }
}

int main(){
    printf("Программа, для определения маскимальной диагонали куба размером n^3\n");
    printf("Выполнил Бибиков Максим, группа 453502\n");
    while(1){
        printf("Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы\n");
        int type = inputOutputNaturalNumber();
        if(type == 2)
            break;
        else if(type != 1 && type != 2)
            continue;
        
        printf("Введите N(Сторона куба): ");
        int N;
        while(1){
            N = inputOutputNaturalNumber();
            if(N < 0){
                printf("Некорректный ввод, введие M: ");
                continue;
            }
            break;
        }

        int ***arr = new int**[N];

        for(int i = 0; i < N; i++){
            arr[i] = new int*[N];
            for(int j = 0; j < N; j++){
                arr[i][j] = new int[N];
                }
        }

        for(int i = 0; i < N; i++){
            printf("%d", i+1);
            printf(" слой\n");
            for(int j = 0; j < N; j++){
                printf("Введите элементы " << j+1 << " строки:\n");
                for(int k = 0; k < N; k++){
                    printf("Введите " << k+1 << " элемент: ");
                    cin >> arr[i][j][k];
                }
            }
        }

        printf("Введенный массив:\n");
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                printf(arr[i][j] << " ";
            }
            printf('\n');
        }


        printf("Полученный массив:\n");
        for(int i = 0; i < N; i++){
            printf(i+1 << " слой:\n");
            for(int j = 0; j < N; j++){
                for(int k = 0; k < N; k++){
                    printf(arr[i][j][k] << ' ');
                }
                printf('\n');
            }
            printf('\n');
        }
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                free(arr[i][j])
            }
        }

        free(arr);
    }
    return 0;
}

/*













*/
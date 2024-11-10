#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define BUFFER_SIZE 4096

bool parse_int(char *string, int *integer);
int countBombs(char **field, int n, int m, int x, int y);
int StringToInteger();

int main(){
    printf("Программа, для составления игрового поля игры Сапёр\n");
    printf("Выполнил Бибиков Максим, группа 453502\n");
    while(1){
        printf("Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы\n");
        int type = StringToInteger();

        if(type == 2)
            break;
        else if(type != 1 && type != 2)
            continue;
        
        
        printf("Введите N(длина поля): ");
        int N;
        while(1){
            N = StringToInteger();
            if(N < 1){
                printf("Некорректный ввод, введите N(Целое неотрицательное число): ");
                continue;
            }
            break;
        }
        printf("Введите M(ширина поля): ");
        int M;
        while(1){
            M = StringToInteger();
            if(M < 1){
                printf("Некорректный ввод, введите M(Целое неотрицательное число): ");
                continue;
            }
            break;
        }
    //
    char **arr = (char**)malloc(sizeof(char*) * N);
    for(int i = 0; i < N; i++){
        arr[i] = (char*)malloc(sizeof(char) * M);
    }        

        for(int i = 0; i < N; i++){
            printf("%d строка:\n", i+1);
            for(int j = 0; j < M; j++){
                printf("Введите символ: ");
                arr[i][j] = getchar(); 
                while(arr[i][j] != '.' && arr[i][j] != '*'){
                    printf("Некорректный ввод! Введите *(бомба) или .(пустая ячейка): ");
                    while (getchar() != '\n');
                    arr[i][j] = getchar();
                }
                while (getchar() != '\n'); 
            }
        }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(arr[i][j] == '*')
                printf("* ");
            else{
                int bombs = countBombs(arr, N, M, i, j);
                arr[i][j] = '0' + bombs;
                printf("%c ", arr[i][j]);
            }
        }
        printf("\n");
    }


        for(int i = 0; i < N; i++){
            free(arr[i]);
        }
        free(arr);
    //
    }

    return 0;
}



int countBombs(char** field, int N, int M, int x, int y){
    int bombs = 0;
    for(int dx = -1; dx <= 1; dx++){
        for(int dy = -1; dy <= 1; dy++){
            int nx = dx + x;
            int ny = dy + y;
            
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && field[nx][ny] == '*')
            bombs++;
        }
    }
    
    return bombs;
}




bool parse_int(char *string, int *integer){
    int i = 0;
    while(isspace(string[i])) i++; // while(isspace([string[i]])) i++;
    int length = strlen(string);
    if(length == i) return false; 

    char int_buffer[BUFFER_SIZE];
    int int_chars = 0;

    if(string[i] == '-'){
        int_buffer[int_chars] = '-';
        int_chars++; i++;

        if(!isdigit(string[i])) return false;
    }
    
    while(i < length && !isspace(string[i])){ // isspace can't be modifed, fck
        if(!isdigit(string[i])) return false;
        
        int_buffer[int_chars] = string[i];
        int_chars++;
        i++;
    }
    int_buffer[int_chars] = '\0';

    while(isspace(string[i])) i++; // isspace cmon

    if(string[i] != '\0') return false;

    *integer = atoi(int_buffer);

    return true;
}

int StringToInteger(){
        int type;
        bool parsed_correct = true;
        do{
        char buffer[BUFFER_SIZE];
        fgets(buffer, BUFFER_SIZE, stdin);
        parsed_correct = parse_int(buffer, &type);
        if(!parsed_correct)
            printf("Некорректный ввод, введите ещё раз!\n");
        }while(!parsed_correct);

        return type;
}
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <gtest/gtest.h>
#define BUFFER_SIZE 4096

int parse_int(char *string, int *integer);

long long max_diagonal(int*** arr, int N);

int StringToInteger();







TEST(ReadIntegerTest, INT_ValidInput1) {
    char testString[] = "777\n";  
    int integer;
    
    EXPECT_EQ(parse_int(testString, &integer), 1); 
    EXPECT_EQ(integer, 777); 
}

TEST(ReadIntegerTest, INT_ValidInput2) {
    char testString[] = "3.1415\n";  
    int integer;
    
    EXPECT_EQ(parse_int(testString, &integer), 0);
}

TEST(ReadIntegerTest, INT_ValidInput3) {
    char testString[] = "abc\nkdskosmgomsongonsdgn\n";  
    int integer;
    
    EXPECT_EQ(parse_int(testString, &integer), 0);
}








int main(){
    printf("Программа, для определения маскимальной диагонали куба размером n^3\n");
    printf("Выполнил Бибиков Максим, группа 453502\n");
    while(1){
        printf("Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы\n");
        int type = StringToInteger();

        if(type == 2)
            break;
        else if(type != 1 && type != 2)
            continue;
        
        
        printf("Введите N(Сторона куба): ");
        int N;
        while(1){
            N = StringToInteger();
            if(N < 1){
                printf("Некорректный ввод, введие N(Целое неотрицательное число): ");
                continue;
            }
            break;
        }
        
        int ***arr = (int ***)malloc(N * sizeof(int **));
        for(int i = 0; i < N; i++){
            arr[i] = (int **)malloc(N * sizeof(int *));
            for(int j = 0; j < N; j++){
                arr[i][j] = (int *)malloc(N * sizeof(int));
            }
        }
        

        for(int i = 0; i < N; i++){
            printf("%d слой:\n", i+1);
            for(int j = 0; j < N; j++){
                printf("%d строка:\n", j+1);
                for(int k = 0; k < N; k++){
                    printf("Введите %d элемент строки: ", k+1);
                    scanf("%d", &arr[i][j][k]);
                }
            }
        }
        while (getchar() != '\n'); // Очистка буфера от \n  
        max_diagonal(arr, N);    
        

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                free(arr[i][j]);
            }
            free(arr[i]);
        }
        free(arr);
    }

    return RUN_ALL_TESTS();
}


long long max_diagonal(int*** arr, int N){
    int sum1 = 0; int sum2 = 0; int sum3 = 0; int sum4 = 0;
    for(int i = 0; i < N; i++){
        sum1 += arr[i][i][i];
        sum2 += arr[i][N - 1 - i][i];
        sum3 += arr[i][i][N - 1 - i];
        sum4 += arr[i][N - 1 - i][N -1 - i];
    }
    if(sum1 >= sum1 && sum1 >= sum3 && sum1 >= sum4){
        printf("Сумма максимальной диагонали: %d\n", sum1);
        printf("Элементы диагонали: ");
        for(int i = 0; i < N; i++){
            printf("%d ", arr[i][i][i]);
        }
        printf("\n");
    }else if(sum2 >= sum1 && sum2 >= sum3 && sum2 >= sum4){
        printf("Сумма максимальной диагонали: %d\n", sum2);
        printf("Элементы диагонали: ");
        for(int i = 0; i < N; i++){
            printf("%d ", arr[i][N -1 - i][i]);
        }
        printf("\n");
    }else if(sum3 >= sum1 && sum3 >= sum2 && sum3 >= sum4){
        printf("Сумма максимальной диагонали: %d\n", sum3);
        printf("Элементы диагонали: ");
        for(int i = 0; i < N; i++){
            printf("%d ", arr[i][i][N - 1 - i]);
        }
        printf("\n");
    }else{
        printf("Сумма максимальной диагонали: %d\n", sum4);
        printf("Элементы диагонали: ");
        for(int i = 0; i < N; i++){
            printf("%d ", arr[i][N - 1 - i][N - 1 - i]);
        }
        printf("\n");
    }
    return 0;
}


int parse_int(char *string, int *integer){
    int i = 0;
    while(isspace(string[i])) i++; // while(isspace([string[i]])) i++;
    int length = strlen(string);
    if(length == i) return false; 

    char int_buffer[BUFFER_SIZE];
    int int_chars = 0;

    if(string[i] == '-'){
        int_buffer[int_chars] = '-';
        int_chars++; i++;

        if(!isdigit(string[i])) return 0;
    }
    
    while(i < length && !isspace(string[i])){ // isspace can't be modifed, fck
        if(!isdigit(string[i])) return 0;
        
        int_buffer[int_chars] = string[i];
        int_chars++;
        i++;
    }
    int_buffer[int_chars] = '\0';

    while(isspace(string[i])) i++; // isspace cmon

    if(string[i] != '\0') return 0;

    *integer = atoi(int_buffer);

    return 1;
}

int StringToInteger(){
        int type;
        int parsed_correct = 1;
        do{
        char buffer[BUFFER_SIZE];
        fgets(buffer, BUFFER_SIZE, stdin);
        parsed_correct = parse_int(buffer, &type);
        if(parsed_correct == 0)
            printf("Некорректный ввод, введите ещё раз!\n");
        }while(parsed_correct == 0);

        return type;
}
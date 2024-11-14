#include <gtest/gtest.h>

extern "C" {
    #include "../funcs.c"
    #include "../head.h"
}

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


TEST(ReadIntegerTest, max_diagonal1){
    int N = 3;

    int ***arr = (int ***)malloc(N * sizeof(int **));
    for(int i = 0; i < N; i++){
        arr[i] = (int **)malloc(N * sizeof(int *));
        for(int j = 0; j < N; j++){
            arr[i][j] = (int *)malloc(N * sizeof(int));
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                arr[i][j][k] = 1;
            }
        }
    }
        
    EXPECT_EQ(max_diagonal(arr, N), 3);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);
}


int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
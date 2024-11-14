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


TEST(ReadIntegerTest, countBombs1){
    int N = 3;
    int M = 3;
    char **field = (char**)malloc(sizeof(char*) * N);
    for(int i = 0; i < N; i++){
        field[i] = (char*)malloc(sizeof(char) * M);
    }
    
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(cnt == 0){
                field[i][j] = ' ';
                cnt++;
            }else{
                field[i][j] = '*';
                cnt--;
            }
        }
    }
        
    EXPECT_EQ(countBombs(field, N, M, 1, 1), 4);

    for(int i = 0; i < N; i++){
        free(field[i]);
    }
    free(field);
}


int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
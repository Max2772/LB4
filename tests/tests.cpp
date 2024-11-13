#include <gtest/gtest.h>
#include <sstream> 
#include "../head.h"
#include "../funcs.cpp"

auto cinBuf = std::cin.rdbuf(); 

TEST(ReadIntegerTest, INT_ValidInput){
    std::istringstream input("777\n"); 
    std::cin.rdbuf(input.rdbuf());
    EXPECT_EQ(readIntegerInLine(), 777); 
    std::cin.rdbuf(cinBuf);
}

TEST(ReadIntegerTest, INT_ValidInput2){
    std::istringstream input("3.1415\n");
    std::cin.rdbuf(input.rdbuf()); 
    EXPECT_EQ(readIntegerInLine(), 0);
    std::cin.rdbuf(cinBuf);
}

TEST(ReadIntegerTest, INT_InvalidInput){
    std::istringstream input("abc\nkdskosmgomsongonsdgn\n");
    std::cin.rdbuf(input.rdbuf()); 
    EXPECT_EQ(readIntegerInLine(), 0);
    std::cin.rdbuf(cinBuf);
}

TEST(ReadDoubleTest, DOUBLE_ValidInput){
    std::istringstream input("2.718281828459045\n"); 
    std::cin.rdbuf(input.rdbuf());
    EXPECT_NEAR(readDoubleInLine(), 2.71828, 0.00001); 
    std::cin.rdbuf(cinBuf);
}

TEST(ReadDoubleTest, DOUBLE_InvalidInput){  
    std::istringstream input("dsonndsfondfjiiufbodfioidfwoeijl4s654g\n");
    std::cin.rdbuf(input.rdbuf()); 
    EXPECT_EQ(readDoubleInLine(), 0);
    std::cin.rdbuf(cinBuf);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
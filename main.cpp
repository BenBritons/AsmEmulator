
#include "Realization.h"
#include "gtest/gtest.h"


TEST (AsmTest, Test1) {
    EXPECT_EQ (281, MakeLab("..\\test1.txt"));
}

TEST (AsmTest, Test2) {
    EXPECT_EQ (1134, MakeLab("..\\test2.txt"));
}

TEST (AsmTest, Test3) {
    EXPECT_EQ (0, MakeLab("..\\test3.txt"));
}

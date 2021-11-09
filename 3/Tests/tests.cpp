#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "funSearchProblem.h"

using testing::Eq;

TEST(test, facingsun){
    FunSearchProblem Test;
    vector<int> temp = {2,4,5,6,6,6,6,4,3,2,7,8,9,10,9,8,7,6,7,8,9,10,11};
    vector<int> temp1 = {};
    vector<int> temp2 = {21};
    EXPECT_EQ(9,Test.facingSun(temp));
    EXPECT_EQ(0,Test.facingSun(temp1));
    EXPECT_EQ(1,Test.facingSun(temp2));
}

TEST(test, squareR){
    FunSearchProblem random;
    EXPECT_EQ(5,random.squareR(25));
    EXPECT_EQ(5,random.squareR(26));
    EXPECT_EQ(2,random.squareR(8));
    EXPECT_EQ(0,random.squareR(0));
    EXPECT_EQ(16,random.squareR(266));
}

TEST(test, missingvalue){
    FunSearchProblem random;
    vector<int> temp = {-1,-2,-3,6,5,7,3,1};
    vector<int> temp1 = {-1,-2,-3,6,5,7,3,1,0,2,3,4,5,6,7,8,9,10};
    vector<int> temp2 = {-1,-2,-3,-4,-5};
    EXPECT_EQ(0,random.smallestMissingValue(temp));
    EXPECT_EQ(11,random.smallestMissingValue(temp1));
    EXPECT_EQ(0,random.smallestMissingValue(temp2));
}


TEST(test, minPages){

}

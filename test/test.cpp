#include <gtest/gtest.h>
#include <iostream>

using namespace std;

class BuildTest : public ::testing::Test {
    void SetUp() final {
        cout << "SetUp() invoked." << endl;
    }
};

TEST_F(BuildTest, FirstFixtureExample) {
    cout << "FirstFixtureExample test invoked." << endl;
    EXPECT_TRUE(true);
}
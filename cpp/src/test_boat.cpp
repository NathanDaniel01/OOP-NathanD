#include "boat.h"
#include "gtest/gtest.h"

using namespace std;
using namespace water;
TEST(Boat,constructedOn) {
    double length = 13.0;
    string brand = "Hyside";
    int capacity = 7;
    
    Boat boat(__LINE__,length, brand, capacity);

    ASSERT_EQ(boat.length(), length);
    
}
TEST(Boat, Length) {
    double length = 13.0;
    string brand = "Hyside";
    int capacity = 7;
    
    Boat boat(__LINE__,length, brand, capacity);

    ASSERT_EQ(boat.length(), length);

    double newLength = 14.0;
    boat.length(newLength);

    ASSERT_EQ(boat.length(), newLength);
}

TEST(Boat, BadLength) {
    double length = 13.0;
    string brand = "Hyside";
    int capacity = 7;
    
    Boat boat(__LINE__,length, brand, capacity);

    ASSERT_EQ(boat.length(), length);

    double newLength = -20.0;
    EXPECT_THROW({
       boat.length(newLength);
    }, std::out_of_range);
    

    ASSERT_EQ(boat.length(), length);
}
// https://github.com/google/googletest/blob/main/googletest/include/gtest/gtest.h

#include <stdexcept>
#include "Range.h"
#include <gtest/gtest.h>

TEST(RangeTests, HandleDoubleInputs) {
    double max = 12.4, min = -2, default_val = 4;
    Range range(max, min, default_val);
    EXPECT_EQ(range.getMax(), max);
    EXPECT_EQ(range.getMin(), min);
    EXPECT_EQ(range.getDefault(), default_val);
}

TEST(RangeTests, HandleJsonInput) {
    json rangeData = {
        {"max", 12.5}, 
        {"min", 4}, 
        {"default", 5}
    };
    Range range(rangeData);
    EXPECT_EQ(rangeData["max"], range.getMax());
    EXPECT_EQ(rangeData["min"], range.getMin());
    EXPECT_EQ(rangeData["default"], range.getDefault());
}

TEST(RangeTests, HandleDefaultOutOfRange) {
    double max = 12.4, min = -2, default_val = 100;
    
        EXPECT_THROW(Range(max, min, default_val), std::invalid_argument);
    
}
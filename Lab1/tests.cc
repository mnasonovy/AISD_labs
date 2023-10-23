#include <gtest/gtest.h>
#include "vector.cc"


TEST(VectorTest, Constructors) {
    Vector<int> a(4, 6);
    EXPECT_EQ(a.GetDimension(), 4);
    for (size_t i = 0; i < a.GetDimension(); ++i) {
        EXPECT_EQ(a[i], 6);
    }

    Vector<int> b(a);
    EXPECT_EQ(b.GetDimension(), 4);
    for (size_t i = 0; i < b.GetDimension(); ++i) {
        EXPECT_EQ(b[i], a[i]);
    }
}

TEST(VectorTest, AssignmentOperator) {
    Vector<int> a(3, 2);
    Vector<int> b(2, 1);
    b = a;
    EXPECT_EQ(b.GetDimension(), a.GetDimension());
    for (size_t i = 0; i < b.GetDimension(); ++i) {
        EXPECT_EQ(b[i], a[i]);
    }
}

TEST(VectorTest, PlusOperator) {
    Vector<int> a(3, 2);
    Vector<int> b(3, 1);
    Vector<int> c = a + b;
    EXPECT_EQ(c.GetDimension(), 3);
    for (size_t i = 0; i < c.GetDimension(); ++i) {
        EXPECT_EQ(c[i], 3);
    }
}

TEST(VectorTest, MinusOperator) {
    Vector<int> a(3, 2);
    Vector<int> b(3, 1);
    Vector<int> c = a - b;
    EXPECT_EQ(c.GetDimension(), 3);
    for (size_t i = 0; i < c.GetDimension(); ++i) {
        EXPECT_EQ(c[i], 1);
    }
}

TEST(VectorTest, MultiplicationOperator) {
    Vector<int> a(3, 2);
    Vector<int> b = a * 3;
    EXPECT_EQ(b.GetDimension(), 3);
    for (size_t i = 0; i < b.GetDimension(); ++i) {
        EXPECT_EQ(b[i], 6);
    }

    Vector<int> c(3, 3);
    int dot = a * c;
    EXPECT_EQ(dot, 18);
}

TEST(VectorTest, DivisionOperator) {
    Vector<int> a(3, 6);
    Vector<int> b = a / 3;
    EXPECT_EQ(b.GetDimension(), 3);
    for (size_t i = 0; i < b.GetDimension(); ++i) {
        EXPECT_EQ(b[i], 2);
    }
}

TEST(CalculateAngleTest, NonZeroVectors) {
    Vector<double> vec1(4, 0);
    Vector<double> vec2(4, 0);
    vec1[0] = 17;
    vec1[1] = 35;
    vec1[2] = -13;
    vec1[3] = 7;

    vec2[0] = 1;
    vec2[1] = 14;
    vec2[2] = -5;
    vec2[3] = 9;

    double result = CalculateAngle(vec1, vec2);
    EXPECT_NEAR(28.7706, result, 1e-4);
}

TEST(CalculateAngleTest, ZeroVector) {
    Vector<double> vec1(4,0);
    Vector<double> vec2(4,7);

    ASSERT_THROW(CalculateAngle(vec1, vec2), std::invalid_argument);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#include <iostream>
#include <gtest/gtest.h>

#include "complex.h"


TEST(ConstructorTests, DefaultConstructor) {
    Complex complex;

    EXPECT_EQ(complex.real, 0) << "Complex's real value is not 0 in default constructor!";
    EXPECT_EQ(complex.complex, 0) << "Complex's complex value is not 0 in default constructor!";
}

TEST(ConstructorTests, FullConstructor) {
    double long real_value = 3;
    double long complex_value = 4;
    Complex complex(real_value, complex_value);

    EXPECT_EQ(complex.real, real_value) << "Complex's real value is not expected in full constructor!";
    EXPECT_EQ(complex.complex, complex_value) << "Complex's default value is not expected in full constructor!";
}

TEST(ConstructorTests, CopyConstructor) {
    double long real_value = 3;
    double long complex_value = 4;
    Complex complex(real_value, complex_value);
    Complex copied_complex(complex);

    EXPECT_EQ(copied_complex.real, real_value) << "Complex's real value is not expected in copy constructor!";
    EXPECT_EQ(copied_complex.complex, complex_value) << "Complex's default value is not expected in copy constructor!";
}

TEST(OperatorTests, Assignment) {
    double long real_value = 3;
    double long complex_value = 4;
    Complex complex(real_value, complex_value);
    Complex copied_complex;

    copied_complex = complex;

    EXPECT_EQ(copied_complex.real, real_value) << "Complex's real value is not expected in assignment!";
    EXPECT_EQ(copied_complex.complex, complex_value) << "Complex's default value is not expected in assignment!";
}

TEST(OperatorTests, AddComplexes) {
    Complex complex1(1, 2);
    Complex complex2(5, 5);

    Complex combined_complex = complex1 + complex2;

    EXPECT_EQ(combined_complex.real, complex1.real + complex2.real) << "Complex's real value is unexpected in Complexes addition!";
    EXPECT_EQ(combined_complex.complex, complex1.complex + complex2.complex) << "Complex's complex value is unexpected in Complexes addition!";
}

TEST(OperatorTests, AddReal) {
    double long real_addition = 3;
    Complex complex(1, 2);

    Complex combined_complex = complex + real_addition;

    EXPECT_EQ(combined_complex.real, complex.real + real_addition) << "Complex's real value is unexpected in number addition!";
    EXPECT_EQ(combined_complex.complex, complex.complex) << "Complex's complex value is unexpected in number addition!";
}

TEST(OperatorTests, iAddComplexes) {
    double long initial_real = 5;
    double long inital_complex = 5;

    Complex complex1(1, 2);
    Complex complex2(initial_real, inital_complex);

    complex2 += complex1;

    EXPECT_EQ(complex2.real, complex1.real + initial_real) << "Complex's real value is unexpected in in-place Complexes addition!";
    EXPECT_EQ(complex2.complex, complex1.complex + inital_complex) << "Complex's complex value is unexpected in in-place Complexes addition!";
}

TEST(OperatorTests, iAddReal) {
    double long initial_real = 5;
    double long inital_complex = 5;
    double long real_addition = 3;

    Complex complex(initial_real, inital_complex);
    complex += real_addition;

    EXPECT_EQ(complex.real, initial_real + real_addition) << "Complex's real value is unexpected in in-place number addition!";
    EXPECT_EQ(complex.complex, inital_complex) << "Complex's complex value is unexpected in in-place number addition!";
}

TEST(OperatorTests, SubtractComplexes) {
    Complex complex1(1, 2);
    Complex complex2(5, 5);

    Complex subtracted_complex = complex1 - complex2;

    EXPECT_EQ(subtracted_complex.real, complex1.real - complex2.real) << "Complex's real value is unexpected in Complexes subtraction!";
    EXPECT_EQ(subtracted_complex.complex, complex1.complex - complex2.complex) << "Complex's complex value is unexpected in Complexes subtraction!";
}

TEST(OperatorTests, SubtractReal) {
    double long real_addition = 3;
    Complex complex(1, 2);

    Complex subtracted_complex = complex - real_addition;

    EXPECT_EQ(subtracted_complex.real, complex.real - real_addition) << "Complex's real value is unexpected in number subtraction!";
    EXPECT_EQ(subtracted_complex.complex, complex.complex) << "Complex's complex value is unexpected in number subtraction!";
}

TEST(OperatorTests, iSubtractComplexes) {
    double long initial_real = 5;
    double long inital_complex = 5;

    Complex complex1(1, 2);
    Complex complex2(initial_real, inital_complex);

    complex2 -= complex1;

    EXPECT_EQ(complex2.real, initial_real - complex1.real) << "Complex's real value is unexpected in in-place Complexes addition!";
    EXPECT_EQ(complex2.complex, inital_complex - complex1.complex) << "Complex's complex value is unexpected in in-place Complexes addition!";
}

TEST(OperatorTests, iSubtractReal) {
    double long initial_real = 5;
    double long inital_complex = 5;
    double long real_addition = 3;

    Complex complex(initial_real, inital_complex);
    complex -= real_addition;

    EXPECT_EQ(complex.real, initial_real - real_addition) << "Complex's real value is unexpected in in-place number subtraction!";
    EXPECT_EQ(complex.complex, inital_complex) << "Complex's complex value is unexpected in in-place number subtraction!";
}

TEST(OperatorTests, MultiplyScalar) {
    double long scalar = 3;
    Complex complex(1, 2);

    Complex multiplied_complex = complex * scalar;

    EXPECT_EQ(multiplied_complex.real, complex.real * scalar) << "Complex's real value is unexpected in scalar multiplication!";
    EXPECT_EQ(multiplied_complex.complex, complex.complex * scalar) << "Complex's complex value is unexpected in scalar multiplication!";
}

TEST(OperatorTests, iMultiplyScalar) {
    double long initial_real = 5;
    double long inital_complex = 5;
    double long scalar = 3;

    Complex complex(initial_real, inital_complex);
    complex *= scalar;

    EXPECT_EQ(complex.real, initial_real * scalar) << "Complex's real value is unexpected in in-place scalar multiplication!";
    EXPECT_EQ(complex.complex, inital_complex * scalar) << "Complex's complex value is unexpected in in-place scalar multiplication!";
}

TEST(OperatorTests, OutputToOStream) {
    testing::internal::CaptureStdout();
    Complex complex(4,3);
    std::cout << complex;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, std::to_string(complex.real) + " + " + std::to_string(complex.complex) + "i");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
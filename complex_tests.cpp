#include <iostream>
#include <gtest/gtest.h>

#include "complex.h"


TEST(ConstructorTests, DefaultConstructor) {
    Complex<double> complex;

    EXPECT_EQ(complex.real, 0);
    EXPECT_EQ(complex.complex, 0);
}

TEST(ConstructorTests, FullConstructor) {
    double real_value = 3;
    double complex_value = 4;
    Complex<double> complex(real_value, complex_value);

    EXPECT_EQ(complex.real, real_value);
    EXPECT_EQ(complex.complex, complex_value);
}

TEST(ConstructorTests, CopyConstructor) {
    double real_value = 3;
    double complex_value = 4;
    Complex<double> complex(real_value, complex_value);
    Complex<double> copied_complex(complex);

    EXPECT_EQ(copied_complex.real, real_value);
    EXPECT_EQ(copied_complex.complex, complex_value);
}

TEST(OperatorTests, Assignment) {
    double real_value = 3;
    double complex_value = 4;
    Complex<double> complex(real_value, complex_value);
    Complex<double> copied_complex;
    copied_complex = complex;

    EXPECT_EQ(copied_complex.real, real_value);
    EXPECT_EQ(copied_complex.complex, complex_value);
}

TEST(OperatorTests, AddComplexes) {
    Complex<double> complex1(1, 2);
    Complex<double> complex2(5, 5);
    Complex<double> combined_complex = complex1 + complex2;

    EXPECT_EQ(combined_complex.real, complex1.real + complex2.real);
    EXPECT_EQ(combined_complex.complex, complex1.complex + complex2.complex);
}

TEST(OperatorTests, AddReal) {
    double real_addition = 3;
    Complex<double> complex(1, 2);
    Complex<double> combined_complex = complex + real_addition;

    EXPECT_EQ(combined_complex.real, complex.real + real_addition);
    EXPECT_EQ(combined_complex.complex, complex.complex);
}

TEST(OperatorTests, iAddComplexes) {
    double initial_real = 5;
    double inital_complex = 5;
    Complex<double> complex1(1, 2);
    Complex<double> complex2(initial_real, inital_complex);
    complex2 += complex1;

    EXPECT_EQ(complex2.real, complex1.real + initial_real);
    EXPECT_EQ(complex2.complex, complex1.complex + inital_complex);
}

TEST(OperatorTests, iAddReal) {
    double initial_real = 5;
    double inital_complex = 5;
    double real_addition = 3;
    Complex<double> complex(initial_real, inital_complex);
    complex += real_addition;

    EXPECT_EQ(complex.real, initial_real + real_addition);
    EXPECT_EQ(complex.complex, inital_complex);
}

TEST(OperatorTests, SubtractComplexes) {
    Complex<double> complex1(1, 2);
    Complex<double> complex2(5, 5);
    Complex<double> subtracted_complex = complex1 - complex2;

    EXPECT_EQ(subtracted_complex.real, complex1.real - complex2.real);
    EXPECT_EQ(subtracted_complex.complex, complex1.complex - complex2.complex);
}

TEST(OperatorTests, SubtractReal) {
    double real_addition = 3;
    Complex<double> complex(1, 2);
    Complex<double> subtracted_complex = complex - real_addition;

    EXPECT_EQ(subtracted_complex.real, complex.real - real_addition);
    EXPECT_EQ(subtracted_complex.complex, complex.complex);
}

TEST(OperatorTests, iSubtractComplexes) {
    double initial_real = 5;
    double inital_complex = 5;
    Complex<double> complex1(1, 2);
    Complex<double> complex2(initial_real, inital_complex);
    complex2 -= complex1;

    EXPECT_EQ(complex2.real, initial_real - complex1.real);
    EXPECT_EQ(complex2.complex, inital_complex - complex1.complex);
}

TEST(OperatorTests, iSubtractReal) {
    double initial_real = 5;
    double inital_complex = 5;
    double real_addition = 3;
    Complex<double> complex(initial_real, inital_complex);
    complex -= real_addition;

    EXPECT_EQ(complex.real, initial_real - real_addition);
    EXPECT_EQ(complex.complex, inital_complex);
}

TEST(OperatorTests, MultiplyScalar) {
    double scalar = 3;
    Complex<double> complex(1, 2);
    Complex<double> multiplied_complex = complex * scalar;

    EXPECT_EQ(multiplied_complex.real, complex.real * scalar);
    EXPECT_EQ(multiplied_complex.complex, complex.complex * scalar);
}

TEST(OperatorTests, iMultiplyScalar) {
    double initial_real = 5;
    double inital_complex = 5;
    double scalar = 3;
    Complex<double> complex(initial_real, inital_complex);
    complex *= scalar;

    EXPECT_EQ(complex.real, initial_real * scalar);
    EXPECT_EQ(complex.complex, inital_complex * scalar);
}

TEST(OperatorTests, OutputToOStream) {
    Complex<double> complex(4,3);
    std::stringstream output;
    output << complex;

    EXPECT_EQ(output.str(), std::to_string(complex.real) + " + " + std::to_string(complex.complex) + "i");
}
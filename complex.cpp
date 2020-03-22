#include "complex.h"


Complex::Complex() : real(0), complex(0) {}
Complex::Complex(double real, double complex) : real(real), complex(complex) {}
Complex::Complex(const Complex& complex) : real(complex.real), complex(complex.complex) {}

Complex& Complex::operator=(const Complex &other_complex) {
    this->real = other_complex.real;
    this->complex = other_complex.complex;
    return *this;
}

Complex Complex::operator+(const Complex& other_complex) const {
    return Complex(this->real+other_complex.real, this->complex+other_complex.complex);
}

Complex Complex::operator+(double added_real) const {
    return Complex(this->real+added_real, this->complex);
}

Complex& Complex::operator+=(const Complex& other_complex) {
    this->real += other_complex.real;
    this->complex += other_complex.complex;
    return *this;
}

Complex& Complex::operator+=(double added_real) {
    this->real += added_real;
    return *this;
}

Complex Complex::operator-(const Complex& other_complex) const {
    return Complex(this->real-other_complex.real, this->complex-other_complex.complex);
}

Complex Complex::operator-(double subtracted_real) const {
    return Complex(this->real-subtracted_real, this->complex);
}

Complex& Complex::operator-=(const Complex& other_complex) {
    this->real -= other_complex.real;
    this->complex -= other_complex.complex;
    return *this;
}

Complex& Complex::operator-=(double subtracted_real) {
    this->real -= subtracted_real;
    return *this;
}

Complex Complex::operator*(double scalar) const {
    return Complex(this->real*scalar, this->complex*scalar);
}

Complex& Complex::operator*=(double scalar) {
    this->real *= scalar;
    this->complex *= scalar;
    return *this;
}

std::ostream& operator<< (std::ostream &out, const Complex& complex) {
    out << std::to_string(complex.real) << " + " << std::to_string(complex.complex) << "i";
    return out;
}
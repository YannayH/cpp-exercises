#ifndef CPP_EXERCISES_COMPLEX_H
#define CPP_EXERCISES_COMPLEX_H

#include <ostream>

class Complex {
public:
    Complex();
    Complex(double real, double complex);
    Complex(const Complex& complex);

    Complex& operator=(const Complex& other_complex);

    Complex operator+(const Complex& other_complex) const;
    Complex operator+(double real) const;

    Complex& operator+=(const Complex& other_complex);
    Complex& operator+=(double real);

    Complex operator-(const Complex& other_complex) const;
    Complex operator-(double real) const;

    Complex& operator-=(const Complex& other_complex);
    Complex& operator-=(double real);

    Complex operator*(double scalar) const;
    Complex& operator*=(double scalar);


    double real;
    double complex;
};

std::ostream& operator<< (std::ostream &out, const Complex& complex);
#endif //CPP_EXERCISES_COMPLEX_H

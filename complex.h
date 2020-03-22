#ifndef CPP_EXERCISES_COMPLEX_H
#define CPP_EXERCISES_COMPLEX_H

#include <ostream>

class Complex {
public:
    Complex();
    Complex(double long real, double long complex);
    Complex(const Complex& complex);

    Complex& operator=(const Complex& other_complex);

    Complex operator+(const Complex& other_complex);
    Complex operator+(double long real);

    Complex& operator+=(const Complex& other_complex);
    Complex& operator+=(double long real);

    Complex operator-(const Complex& other_complex);
    Complex operator-(double long real);

    Complex& operator-=(const Complex& other_complex);
    Complex& operator-=(double long real);

    Complex operator*(double long scalar);
    Complex& operator*=(double long scalar);


    double long real;
    double long complex;
};

std::ostream& operator<< (std::ostream &out, const Complex& complex);
#endif //CPP_EXERCISES_COMPLEX_H

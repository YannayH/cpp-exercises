#include "complex.h"


template < class T >Complex< T >::Complex() : real(0), complex(0) {};
template < class T > Complex< T >::Complex(T real, T complex) : real(real), complex(complex) {};
template < class T > Complex< T >::Complex(const Complex< T >& complex) : real(complex.real), complex(complex.complex) {};

template < class T > Complex< T >& Complex< T >::operator=(const Complex& other_complex) {
    this->real = other_complex.real;
    this->complex = other_complex.complex;

    return *this;
}

template < class T > Complex< T >& Complex< T >::operator+=(const Complex& other_complex) {
    this->real += other_complex.real;
    this->complex += other_complex.complex;

    return *this;
}

template < class T > Complex< T >& Complex< T >::operator+=(T added_real) {
    this->real += added_real;

    return *this;
}

template < class T > Complex< T >& Complex< T >::operator-=(const Complex& other_complex) {
    this->real -= other_complex.real;
    this->complex -= other_complex.complex;

    return *this;
}

template < class T > Complex< T >& Complex< T >::operator-=(T subtracted_real) {
    this->real -= subtracted_real;

    return *this;
}

template < class T > Complex< T >& Complex< T >::operator*=(T scalar) {
    this->real *= scalar;
    this->complex *= scalar;

    return *this;
}

template < class T > std::ostream& operator<< (std::ostream &out, const Complex< T >& complex) {
    out << std::to_string(complex.real) << " + " << std::to_string(complex.complex) << "i";
    return out;
}
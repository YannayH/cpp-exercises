#include "complex.h"


template < class T > Complex< T >::Complex() : m_real(0), m_complex(0) {}
template < class T > Complex< T >::Complex(T real, T complex) : m_real(real), m_complex(complex) {}
template < class T > Complex< T >::Complex(const Complex< T >& complex) : m_real(complex.m_real), m_complex(complex.m_complex) {}

template < class T > Complex< T >& Complex< T >::operator=(const Complex& other_complex) {
    m_real = other_complex.m_real;
    m_complex = other_complex.m_complex;
    return *this;
}

template < class T > Complex< T >& Complex< T >::operator+=(const Complex& other_complex) {
    m_real += other_complex.m_real;
    m_complex += other_complex.m_complex;
    return *this;
}

template < class T > Complex< T >& Complex< T >::operator+=(T added_real) {
    m_real += added_real;
    return *this;
}

template < class T > Complex< T >& Complex< T >::operator-=(const Complex& other_complex) {
    m_real -= other_complex.m_real;
    m_complex -= other_complex.m_complex;
    return *this;
}

template < class T > Complex< T >& Complex< T >::operator-=(T subtracted_real) {
    m_real -= subtracted_real;
    return *this;
}

template < class T > Complex< T >& Complex< T >::operator*=(T scalar) {
    m_real *= scalar;
    m_complex *= scalar;
    return *this;
}

template < class T > std::ostream& operator<< (std::ostream &out, const Complex< T >& complex) {
    out << std::to_string(complex.m_real) << " + " << std::to_string(complex.m_complex) << "i";
    return out;
}
#ifndef CPP_EXERCISES_COMPLEX_H
#define CPP_EXERCISES_COMPLEX_H

#include <ostream>
#include <boost/operators.hpp>

template < class T >
class Complex :
        boost::addable< Complex< T > >,
        boost::addable< Complex< T >, T >,
        boost::subtractable< Complex< T > >,
        boost::subtractable< Complex< T >, T >,
        boost::multipliable< Complex< T >, T > {
public:
    Complex();
    Complex(T real, T complex);
    Complex(const Complex< T >& complex);

    Complex& operator=(const Complex< T >& other_complex);

    Complex& operator+=(const Complex< T >& other_complex);
    Complex& operator+=(T real);
    Complex& operator-=(const Complex< T >& other_complex);
    Complex& operator-=(T real);
    Complex& operator*=(T scalar);


    T real;
    T complex;
};

template < class T > std::ostream& operator<< (std::ostream &out, const Complex< T >& complex);

#include "complex.inl"

#endif //CPP_EXERCISES_COMPLEX_H

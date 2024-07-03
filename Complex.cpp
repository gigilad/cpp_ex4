#include "Complex.hpp"


Complex::Complex(double r, double i) : real(r), image(i) {}


bool Complex::operator>(const Complex &other) const
{
    return (real * real + image * image) > (other.real * real + other.image * other.image);
}

bool Complex::operator<(const Complex &other) const
{
    return (real * real + image * image) < (other.real * real + other.image * other.image);

}

bool Complex::operator==(const Complex& other) const {
    return this->real == other.real && this->image == other.image;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Complex& other) {
  out << other.real << " + " << other.image << "i";
  return out ;

}
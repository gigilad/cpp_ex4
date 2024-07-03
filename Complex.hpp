#include <iostream>
#include <stdexcept>

class Complex{

private:
    double real;
    double image;

public:

Complex(double r, double i);
double getReal() const { return real; }
double getImage() const { return image; }

void setReal(double r) { real = r; }
void setImage(double i) { image = i; }

bool operator>(const Complex& other) const;
bool operator<(const Complex &other) const;
bool operator==(const Complex &other) const;
bool operator!=(const Complex &other) const;

friend std::ostream& operator<<(std::ostream& out, const Complex& other);

};
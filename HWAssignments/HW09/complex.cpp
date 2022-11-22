// Colin Matz, Nov 13 2022, CSCI 207, HW09
#include <cmath>
#include <iostream>
#include <stdio.h>

std::string format = "rect";
std::string angle = "deg";

void setFPolar() {
    format = "polar";
}
void setFRect() {
    format = "rect";
}
void setADeg() {
    angle = "deg";
}
void setARad() {
    angle = "rad";
}

class Complex {
public:
  Complex(double r, double i) {
    this->r = r;
    this->i = i;
  }
  Complex(double r) {
    this->r = r;
    this->i = 0;
  }
  void print() {
    if (::format == "rect") {
      char const * imaginarySign = "\u0069";
      if (this->i < 0){
        printf("%.3lf - %.3lf %s\n", this->r, this->i * -1, imaginarySign);
        return;
      }
      else {
        printf("%.3lf + %.3lf %s\n", this->r, this->i, imaginarySign);
        return;
      }
    }
    if (::format == "polar") {
      char const * angleSign = "\u2220";
      char const * degreeSign = "\u00B0";
      char const * radianSign = "\u33AD";
      double theta = atan(this->i / this->r);
      double mag = sqrt(pow(this->r, 2) + pow(this->i, 2));
      if (::angle == "deg") {
        printf("%.3lf %s %.2lf %s\n", mag, angleSign, theta * 180.0 / 3.141592654, degreeSign);
        return;
      }
      if (::angle =="rad") {
        printf("%.3lf %s %.2lf %s\n", mag, angleSign, theta, radianSign);
        return;
      }
    }
    else {
      printf("ERROR\n");
      return;
    }
  }
  double abs() { 
    return (sqrt((this->r) * (this->r) + (this->i) * (this->i))); 
  }

  Complex operator+(Complex &B) {
    return Complex(this->r + B.r, this->i + B.i);
  }

  Complex operator-(Complex &B) {
    return Complex(this->r - B.r, this->i - B.i);
  }

  Complex operator*(Complex &B) {
    return Complex(((this->r * B.r) - (this->i * B.i)), ((this->r * B.i) + (this->i * B.r)));
  }

  Complex operator/(Complex &B) {
    return Complex((((this->r * B.r) + (this->i * B.i)) / ((B.r * B.r) + (B.i * B.i))),(((this->i * B.r) - (this->r * B.i)) / ((B.r * B.r) + (B.i * B.i))));
  }

  Complex conjugateComplex() {
    return Complex(this->r, (this->i * -1));
  }

  void isEqual(Complex B) {
    if (this->r == B.r && this->i == B.i) {
      printf("The two complex numbers are the same!\n");
      return;
    }
    if (this->r != B.r || this->i != B.i) {
      printf("The two complex numbers are not the same!\n");
      return;
    }
    else {
      printf("ERROR\n");
      return;
    }
  }

private:
  double r, i;
};

using namespace std;

int main() { 
  /* Function calls */
  Complex c1(3.0, 4.0);
  Complex c2(5.0, 6.0);
  c1.print();
  setFPolar();
  c2.print();

  Complex c3 = c1 + c2;
  setARad();
  c3.print();
  Complex c4 = c1 - c2;
  c4.print();
  
  Complex c5 = c1 * c2;
  Complex c6 = c2 * c1;
  c5.print();
  setFRect();
  c6.print();
  
  c5.isEqual(c6);

  printf("abs(c1) = %.2lf \n", c1.abs());

  Complex c7(3.14);
  c7.print();

  setFPolar();
  setADeg();

  Complex c8(6.0, 7.9);
  c8.print();

  setFRect();

  c8.print();

  Complex c9 = c8.conjugateComplex();
  c9.print();
  
  Complex c10 = c1 / c2;
  c10.print();

  Complex c11 = c6 / c7;
  c11.print();

}


#include <iostream>
using namespace std;

// operator overloading -> make operators polymorphic

class Complex{
  public:
    int real;
    int imag;

    Complex(){
        real = imag = -1;
    }

    Complex(int r, int i) : real(r), imag(i){};

    // syntax
    // Return_type operator <op> (args){
    //     // logic
    //     return <>
    // }

    Complex operator+(const Complex &B){ // const -> B ko change na kar pao
        /// this -> A instance
        Complex temp;
        temp.real = this->real + B.real;
        temp.imag = this->imag + B.imag;
        return temp;
    }

    Complex operator-(const Complex &B){
        /// this -> A instance
        Complex temp;
        temp.real = this->real - B.real;
        temp.imag = this->imag - B.imag;
        return temp;
    }

    bool operator==(const Complex &B){
        /// this -> A instance
        return (this->real == B.real) && (this->imag == B.imag);
    }

    void print(){
        printf("[%d + i%d]\n", this->real, this->imag);
    }
};

int main(){
    Complex A(2, 5);
    A.print();
    Complex B(3, 3);
    B.print();

    Complex C = A + B; // will give error(without operator overloading)
    C.print();
    Complex D = A - B;
    D.print();

    bool a = A == B;
    cout << a << endl;

    return 0;
}

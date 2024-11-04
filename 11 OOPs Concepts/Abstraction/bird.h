// ifnd    : start header file
#if !defined(BIRD_H)
#define BIRD_H
#include<iostream>

class Bird{
public:
    // this is interface
    virtual void eat() = 0; //pure virtual function
    virtual void fly() = 0;
    // classes that inherits this class has to implement pure virtual functions
};

class Sparrow : public Bird{
  public:
    void eat(){
        std::cout << "Sparrow is eating\n";
    }
    void fly(){
        std::cout << "Sparrow is flying \n";
    }
};

class Eagle : public Bird{
  public:
    void eat(){
        std::cout << "Eagle is eating\n";
    }
    void fly(){
        std::cout << "Eagle is flying faster\n";
    }
};

class Pigeion : public Bird{
  public:
    void eat(){
        std::cout << "Pigeion is eating\n";
    }
    void fly(){
        std::cout << "Pigeion is flying \n";
    }
};
#endif // BIRD_H
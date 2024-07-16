#include<iostream>
#include<string>
using namespace std;

class Student{
    public:
    //Attributes
    int id;
    int age;
    string name;
    int nos;

    // constructor-> ctor: default ctor
    Student(){
        cout<<"Student Default constructor called"<<endl;
    }

    //Behaviors/Methods/Functions
    void study(){
        cout << this->name << "Studying" << endl;
    }
    void sleep(){
        cout << this->name << "Sleeping" << endl;
    }
    void bunk(){
        cout << this->name << "Bunking" << endl;
    }

    //dtor
    ~Student(){
        cout<<"Student Default destructor called"<<endl;
    }

};

int main(){
    // Using Default Constructor
    Student A;
    A.id=1;
    A.age=15;
    A.name="Raano";
    A.nos=6;
    A.study();

    Student B;
    B.id=2;
    B.age=15;
    B.name="Rahul";
    B.nos=5;
    B.bunk();

    return 0;
}
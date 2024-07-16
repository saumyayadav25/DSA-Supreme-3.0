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

    // Parameterised ctor
    Student(int id, int age, string name, int nos){
        cout<<"Student Parameterised constructor called"<<endl;
        this->id=id;
        this->age=age;
        this->name=name;
        this->nos=nos;
    }

    // copy ctor
    Student(const Student &srcobj){     //srcobj=>A
        cout<<"Student copy constructor called"<<endl;
        this->id=srcobj.id;
        this->age=srcobj.age;
        this->name=srcobj.name;
        this->nos=srcobj.nos;
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

    Student A(1,15,"Raano",6);    //Stack
    Student B(2,13,"Rahul",4);
    Student C(3,11,"Reena",6);
    Student D(4,17,"raman",5);

    cout<<A.name<<" "<<A.age<<endl;
    A.bunk();
    B.sleep();

    // copy ctor
    // Student E = A;
    Student E(A);
    cout<<E.name<<" "<<A.name<<endl;

    
    return 0;
}
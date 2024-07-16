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
    int *gpa;
    // constructor-> ctor: default ctor
    Student(){
        cout<<"Student Default constructor called"<<endl;
    }

    // Parameterised ctor
    Student(int id, int age, string name, int nos,float gpa){
        cout<<"Student Parameterised constructor called"<<endl;
        this->id=id;
        this->age=age;
        this->name=name;
        this->nos=nos;
        this->gpa= new int(gpa);
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
        delete this->gpa;
    }

};

int main(){

    // dynamic memory allocation, or student pointer
    Student *A = new Student(1,14,"Saumya",7,9.45);
    cout<< A->name <<endl;
    cout<< A->age <<endl;
    A->study();
    delete A;
    return 0;
}
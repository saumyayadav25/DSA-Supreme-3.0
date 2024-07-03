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

private:
    int *gpa;
    string bf;

public:
    // constructor-> ctor: default ctor
    Student(){
        cout<<"Student Default constructor called"<<endl;
    }

    // Parameterised ctor
    Student(int id, int age, string name, int nos,float gpa, string bf){
        cout<<"Student Parameterised constructor called"<<endl;
        this->id=id;
        this->age=age;
        this->name=name;
        this->nos=nos;
        this->gpa= new int(gpa);
        this->bf=bf;
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
        delete this->gpa;
    }
private:
void bfchatting(){
    cout << this->name << "Chatting" <<endl;
}
};

int main(){
    Student A(1,12,"Ranu",5,7.8,"Manoj");
    cout<<A.age<<endl;
    // cout<<A.bf<<endl;   //error
    A.sleep();
    return 0;
}
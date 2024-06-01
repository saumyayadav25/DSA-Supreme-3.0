#include<iostream>
using namespace std;
class Student{
    public:
        int marks;
        string name;
        Student(){

        }
        Student(int m, string n){
            this->marks = m;
            this->name = n;
        }
};
//functor
class StudentComparator{
    public:
        bool operator()(Student a, Student b){
            return a.marks < b.marks;
        }
};
int main() {

    Student s1;
    Student s2;
    s1.marks = 95;
    s1.name = "saumya";
    s2.marks = 93;
    s2.name = "babbar";

    StudentComparator cmp;
    if(cmp(s1,s2)){
        cout<<" saumya has lesser marks";
    }
    else{
        cout<<"saumya has more marks"<<endl;
    }
    return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
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
class Comparator{
    public:
        bool operator()(Student a, Student b){
            //criteria: max marks-> high priority
            return a.marks < b.marks;
        }
};
int main() {
    priority_queue<Student, vector<Student>, Comparator> pq;
    pq.push(Student(90,"saumya"));
    pq.push(Student(67,"yadav"));
    pq.push(Student(89,"lakshay"));
    pq.push(Student(72,"love"));
    cout<<pq.top().marks <<" "<<pq.top().name<<endl;
    
    //max-heap
    // priority_queue<int> pq;
    // priority_queue<int, vector<int>, less<int> > pq2;
    //min-heap
    // priority_queue<int, vector<int>, greater<int> > pq3;

    return 0;
}

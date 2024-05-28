#include<iostream>
#include<vector>
using namespace std;
int main(){
    //creation
    vector<int> marks; 
    vector<int> miles(10); //size: 10
    vector<int> distances(15,5); //size: 15 and insert value 5
    //begin()
    cout<<*(miles.begin())<<endl;
    //push_back()
    marks.push_back(10);
    marks.push_back(20);
    marks.push_back(30);
    marks.push_back(40);
    marks.push_back(50);
    //reserve()
    marks.reserve(10);
    //size()
    cout<<"size: "<< marks.size()<<endl;
    //capacity()
    cout<<"capacity: "<< marks.capacity()<<endl;
    //pop_back()
    marks.pop_back();
    //front()
    cout<<marks.front()<<endl;
    //back()
    cout<<marks.back()<<endl;
    //empty()
    if(marks.empty()==true){
        cout<<"vector is empty"<<endl;
    }
    else{
        cout<<"vector is not empty"<<endl;
    }
    //operator[]
    marks[0] = 100;
    cout<<marks[0]<<endl;
    //at()
    cout<<marks.at(0)<<endl;
    return 0;
}

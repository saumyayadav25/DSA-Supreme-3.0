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

    //clear()
    //marks.clear();

    //insert()
    marks.insert(marks.begin(),50);
    cout<<marks[0]<<endl;

    //erase()
    marks.erase(marks.begin());
    cout<<marks[0]<<endl;

    //reserve()
    marks.reserve(10);

    //size()
    cout<<"size: "<< marks.size()<<endl;

    //capacity()
    cout<<"capacity: "<< marks.capacity()<<endl;

    //max_size()
    cout<<marks.max_size()<<endl;
    
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

    //swap()
    marks.swap(distances);
    
    //for-each loop
    for(int i: distances){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i:marks){
        cout<<i<<" ";
    }
    cout<<endl;
    
    //loop using iterator
    //create and iterator
    vector<int>::iterator it = distances.begin();
    while(it !=distances.end()){
        cout<<*it<<" ";
        it++;
    }
    return 0;
}

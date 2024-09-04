#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

int main(){
    // creation
    unordered_map<int,string> uMap;
    map<int,string> oMap;

    // insertion
    // insert() and []
    uMap[2] = "Scorpio";
    uMap[3] = "Fortuner";
    uMap[1] = "Creta";

    oMap[2] = "Scorpio";
    oMap[3] = "Fortuner";
    oMap[1] = "Creta";

    cout<< "Printing ordered map: "<<endl;
    for(auto i: oMap){
        cout << i.first << "-> " << i.second << endl;
    }
    cout << endl;

    cout<< "Printing unordered map: "<<endl; // prints randomly
    for(auto i: uMap){
        cout << i.first << "-> " << i.second << endl;
    }

    // search or find
    // count() and find()
    if(uMap.find(1) == uMap.end()){
        cout << "1 nhi mila " << endl;
    }
    else{
        cout << "found 1" << endl;
    }

    if(uMap.count(30) == 0){
        cout << "30 nhi mila"<<endl;
    }
    else{
        cout << " found 30" <<endl;
    }
    return 0;
}
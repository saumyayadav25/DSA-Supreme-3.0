#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;

int main(){
    //creation
    unordered_set<int> st;

    //insertion
    st.insert(10);
    st.insert(15);
    st.insert(8);
    st.insert(4);

    //traverse
    unordered_set<int>:: iterator it = st.begin();
    while(it != st.end()){
        cout<< *it <<endl;
        it++;
    }

    //size()
    cout<<"size: "<<st.size()<<endl;

    //find()
    if(st.find(15) != st.end()){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found"<<endl;    
    }

    //count()
    if(st.count(105) == 1){
        cout<<"found";
    }
    else{
        cout<<"not found"<<endl;
    }
    //clear()
    st.clear();
    //erase
    st.erase(st.begin(), st.end());

    //empty()
    if(st.empty()==true){
        cout<<"set is empty"<<endl;
    }
    else{
        cout<<"set is noty empty"<<endl;
    }
    return 0;
}

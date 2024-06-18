#include<iostream>
#include<vector>
using namespace std;
void solve(int* ar, int size){
    cout<<sizeof(ar)<<endl;
}
void solvev(vector<int>v){
    cout<<sizeof(v)<<endl;
}
int main(){
    int ar[]={10,20,30,40,50};
    int size=5;
    solve(ar,size);

    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    solvev(v);

    // MEMORY ALLOCATION
    //integer->stack memory
    int a=5;
    cout<<a<<endl;
    //integer->heap memory
    int*p=new int;
    *p=5;
    cout<<*p<<endl;
    //deallocate->delete
    delete p;

    //arrar->stack memory
    int arr[5]={0};
    cout<<arr[0]<<arr[1]<<arr[2]<<endl;
    //array->heap memory
    int* brr=new int[5];
    cout<<brr[0]<<brr[1]<<brr[2];

    //2D array->stack memory
    int arr2[2][4]={
        {2,4,6,8},
        {1,2,3,4}
    };
    //2D array->heap memory
    //4->row count; 3->col count
    int**prr= new int*[4];
    for(int i=0;i<4;i++){
        // har pointer ke liye ek 1D array create krna hai
        prr[i]=new int[3];
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cin>>prr[i][j];
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cout<<prr[i][j]<<' ';
        }
        cout<<endl;
    }
    for(int i=0;i<4;i++){
        delete[] prr[i];
    }
    return 0;
}
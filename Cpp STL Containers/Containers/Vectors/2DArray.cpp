#include<iostream>
#include<vector>
using namespace std;
//2d array using vector
int main(){
    //creation
    vector<vector<int> > arr(5, vector<int>(4,0));
    int totalRows = arr.size();
    int totalColumns = arr[0].size();
    //Jagged array
    vector<vector<int>> brr(4);
    brr[0]= vector<int>(4);
    brr[1]=vector<int>(2);
    brr[2]=vector<int>(5);
    brr[3]=vector<int>(3);
    int totalRowCount = brr.size();
    //int totalColumnCount = brr[i].size();
    return 0;
}

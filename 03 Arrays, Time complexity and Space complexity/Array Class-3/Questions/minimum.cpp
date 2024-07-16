#include<iostream>
#include<vector>
using namespace std;
//minimum Value
int findMinimum(int arr[][4],int rowSize, int colSize){
    int minValue = INT_MAX;
    for(int i=0; i<rowSize; i++){
        for( int j=0; j<colSize;j++){
            minValue=min(arr[i][j], minValue);
        }
    }
    return minValue;
}
int main(){
    int arr[3][4]={{10,11,12,13},
                    {20,21,22,23},
                    {31,32,44,5}};
    int rowSize=3;
    int colSize=4;
    int ans= findMinimum(arr, rowSize, colSize);
    cout<<ans<<endl;
    return 0;
} 

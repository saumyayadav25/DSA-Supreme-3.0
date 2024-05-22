#include<iostream>
#include<vector>
using namespace std;
//maximum Value
int findMaximum(int arr[][4],int rowSize, int colSize){
    int maxValue = INT_MIN;
    for(int i=0; i<rowSize; i++){
        for( int j=0; j<colSize;j++){
            maxValue=max(arr[i][j], maxValue);
        }
    }
    return maxValue;
}
int main(){
    int arr[3][4]={{10,11,12,13},
                    {20,21,100,23},
                    {31,32,44,5}};
    int rowSize=3;
    int colSize=4;
    int ans= findMaximum(arr, rowSize, colSize);
    cout<<ans<<endl;
    return 0;
} 

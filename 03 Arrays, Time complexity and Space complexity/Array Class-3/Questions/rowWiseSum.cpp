#include<iostream>
using namespace std;
//row-wise sum
void rowWiseSum(int arr[][4],int rowSize, int colSize){
    
    for(int i=0; i<rowSize; i++){
        int sum=0;
        for( int j=0; j<colSize;j++){
            sum=sum+arr[i][j];
        }
        cout<< sum << endl;
    }
}
int main(){
    int arr[3][4]={{10,10,10,10},
                    {20,20,20,20},
                    {30,30,30,30}};
    int rowSize=3;
    int colSize=4;
    rowWiseSum(arr,rowSize,colSize);
    return 0;
} 

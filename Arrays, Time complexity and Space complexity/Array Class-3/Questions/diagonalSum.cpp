#include<iostream>
using namespace std;
//diagonal sum
void diagonalSum(int arr[][4],int rowSize, int colSize){
    int sum=0;
    for(int i=0; i<rowSize; i++){
        sum=sum+arr[i][i];
    }
    cout<<"sum: "<< sum << endl;
}
int main(){
    int arr[3][4]={{10,20,30},
                    {40,80,20},
                    {20,40,30}};
    int rowSize=3;
    int colSize=3;
    diagonalSum(arr,rowSize,colSize);
    return 0;
} 

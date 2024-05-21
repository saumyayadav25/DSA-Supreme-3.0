#include<iostream>
using namespace std;
//three sum
void checkThreeSum(int arr[], int n, int target){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+ arr[j]+ arr[k] == target){
                    //asnwer found
                    cout<<arr[i]<<", "<<arr[j]<<", "<<arr[k]<<endl;
                }
            }
        }
    }
}
int main(){
    int arr[]={10,20,30,40};
    int size=4;
    checkThreeSum(arr,size,70);
    return 0;
} 

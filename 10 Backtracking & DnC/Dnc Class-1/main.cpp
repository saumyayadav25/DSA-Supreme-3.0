#include<iostream>
#include<vector>
using namespace std;

void mergeSortedArrays(int arr[], int sizeArr, int brr[], int sizeBrr, vector<int>& ans){
    int i=0;
    int j=0;
    //i->arr; j->brr
    //jab tk i and j arrays ke bounds ke andar hai
    while(i<sizeArr && j<sizeBrr){
        if(arr[i]<brr[j]){
            ans.push_back(arr[i]);
            i++;
        }
        else{
            ans.push_back(brr[j]);
            j++;
        }
    }
    //2 cases
    //1. elements still left in arr
    while(i<sizeArr){
        ans.push_back(arr[i]);
        i++;
    }
    //2. elements still left in brr
    while(j<sizeBrr){
        ans.push_back(brr[j]);
        j++;
    }
}

void merge(int arr[], int s, int e, int mid){
    //creating left and right arrays
    int leftLength = mid - s + 1;
    int rightLength = e - mid;
    int *leftArr = new int[leftLength];
    int *rightArr = new int[rightLength];

    //fill or copy the left and right arrays
    //copy values of original array
    //original array ka starting index
    int index = s;
    //copying into left array
    for(int i=0; i<leftLength; i++){
        leftArr[i] = arr[index];
        index++;
    }
    //copying into right array
    index = mid+1;
    for(int i=0; i<rightLength; i++){
        rightArr[i] = arr[index];
        index++;
    }

    //merge logic
    int i = 0;
    int j = 0;
    int mainArrayIndex = s;

    while(i < leftLength && j < rightLength){
        if(leftArr[i]<rightArr[j]){
            arr[mainArrayIndex]=leftArr[i];
            i++;
            mainArrayIndex++;
        }
        else{
            arr[mainArrayIndex]=rightArr[j];
            j++;
            mainArrayIndex++;
        }
    }

    //handle 2 cases discussed above in merge 2sorted arrays question
    while(i<leftLength){
        arr[mainArrayIndex]=leftArr[i];
            i++;
            mainArrayIndex++;
    }
    while(j<rightLength){
        arr[mainArrayIndex]=rightArr[j];
            j++;
            mainArrayIndex++;
    }

    //delete heap memory
    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int arr[], int s, int e){
    //base case
    //single element(s==e): already sorted
    if(s>=e) return;
    int mid = (s+e)/2;
    //left part: solve by recursion
    mergeSort(arr,s,mid);
    //right part: solve by recursion
    mergeSort(arr,mid+1,e);
    //merge both left and right parts
    merge(arr,s,e,mid);
}

int main(){
    //merge 2 sorted arrays
    // int arr[]={10,30,50,70};
    // int sizeArr=4;
    // int brr[]={20,40,60,80,90,100};
    // int sizeBrr=6;
    // vector<int>ans;
    // mergeSortedArrays(arr, sizeArr, brr, sizeBrr, ans);
    // for(int num: ans){
    //     cout<<num<<" ";
    // } 

    int arr[] = {10,80,110,90,50,30,40,20};
    int size = 8;
    int s=0;
    int e=size-1;
    mergeSort(arr,s,e);
    for( int i=0; i<size;i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
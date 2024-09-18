// HackerRank: Merge Sort: Count Inversions

/*
 * Complete the 'countInversions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

// Method - 1: TC:(N^2) and SC:O(1)
long countInversions(vector<int> arr) {
    long count = 0;
    for(int i = 0; i < arr.size(); i++){
        for(int j = i+1; j<arr.size();j++){
            count = arr[i]>arr[j] ? count + 1 : count;
        }
    }
    return count;
}

// Method - 2: Merge Sort
long merge(vector<int>&arr, vector<int>&temp, int start, int mid, int end){
    int i = start, j = mid + 1, k = start;
    long c = 0;
    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else{
            //arr[i]>arr[j]: inversion count case
            temp[k++] = arr[j++]; 
            c += mid - i + 1;
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=end){
        temp[k++] = arr[j++];
    }
    while(start<=end){
        arr[start] = temp[start];
        start++;
    }
    return c;
}
long mergeSort(vector<int>&arr, vector<int>&temp, int start, int end){
    if(start>=end) return 0;
    int mid = start + (end-start)/2;
    long c = 0;
    c += mergeSort(arr,temp,start,mid);
    c += mergeSort(arr,temp,mid+1,end);
    c += merge(arr,temp,start,mid,end);
    return c;
}
long countInversions(vector<int> arr) {
    long c = 0; // inversion counts
    vector<int>temp(arr.size(),0);
    c = mergeSort(arr,temp,0,arr.size()-1);
    return c;
}
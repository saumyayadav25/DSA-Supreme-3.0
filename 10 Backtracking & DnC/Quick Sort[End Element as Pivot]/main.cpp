// gfg
class Solution{
    public:
    void quickSort(int a[], int start, int end){
        if(start >= end) return;
        int pivot = end;
        int i = start - 1;
        int j = start;
        while(j<pivot){
            if(a[j]<a[pivot]){
                ++i;
                swap(a[i], a[j]);
            }
            j++;
        }
        ++i;
        //i is the right position for the pivot element.
        swap(a[i], a[pivot]);
        quickSort(a,start,i-1);
        quickSort(a, i+1, end);
    }
};
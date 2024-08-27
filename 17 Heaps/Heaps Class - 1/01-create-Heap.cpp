#include<iostream>
using namespace std;

class Heap{
    public:
        int *arr;
        int capacity; // total number of elements that heap can hold
        int size; // current number of elements inside heap
        Heap(int capacity){
            this->capacity = capacity;
            arr = new int[capacity];
            size = 0;
        }
        // TC : O(logn)
        void insert(int val){
            // STEP 1: insert the element normally into the first empty position inside the array
            // STEP 2: then compare the element with the parent and put the element at the right place
            // also make sure that you are handling the overflow case
            if(size==capacity){
                cout<<"OVERFLOW<<"<<endl;
                return;
            }
            // it means new element ke liye space hai
            // STEP 1: 
            size++:
            int index = size;
            arr[index] = val;
            // STEP 2: HEAPIFY
            while(index>1){
                int parentIndex = index/2;
                if(arr[index]> arr[parentIndex]){
                    swap(arr[index],arr[parentIndex]);
                    index = parentIndex;
                }
                else{
                    break;
                }
            }
        }
        
        // TC : O(logn)
        int deleteFromHeap(){
            int answer = arr[1];
            // replace
            swap(arr[1],arr[size]);
            // remove
            size--;
            // updated root node is at index 1 now
            int index = 1;
            while(index < size){
                int i = index;
                int parent = i;
                int left = 2 * i;
                int right = 2 * i + 1;

                // let's find out sbse bada element
                int largestElementIndex = parent;
                if(left <= size && arr[largestElementIndex] < arr[left]){
                    largestElementIndex = left;
                }
                if(right<= size && arr[largestElementIndex] < arr[right]){
                    largestElementIndex = right;
                }
                // check whether we found a new largest element or not
                if(largestElementIndex == parent){
                    // no change-> parent hi largest hai: kuch nhi krna iska mtlb
                    break;
                }
                else{
                    // we found a new largestElement other than parent
                    swap(arr[parent], arr[largestElementIndex]);
                    index = largestElementIndex;
                }
            }
            return answer;
        }
        // another way to delete

        int deleteFromHeap(){
            int answer = arr[1];
            // replace
            swap(arr[1],arr[size]);
            size--;
            int i = 1;
            while(i<size){
                int currentIndex = i;
                int leftChildIndex = 2*i;
                int rightChildIndex = 2*i+1;

                int currVal = arr[current];
                int leftVal = arr[leftChildIndex];
                int rightVal = arr[rightChildIndex];

                int sabseBadaElementKaIndex = current;
                if(currVal > leftVal && currVal >rightVal){
                    sabseBadaElementKaIndex = currentIndex;
                }
                if(leftVal > currVal && leftVal >rightVal){
                    sabseBadaElementKaIndex = leftChildIndex;
                }
                if(rightVal > currVal && rightVal >leftVal){
                    sabseBadaElementKaIndex = rightChildIndex;
                }
                if(sabseBadaElementKaIndex == currentIndex){
                    break;
                }
                else{
                    swap(arr[currentIndex], arr[sabseBadaElementKaIndex]);
                    i = sabseBadaElementKaIndex; //nhi kroge toh infinite loop me fas jaoge
                }
            }
            return answer;
        }
        
        void printHeap(){
            for(int i =0; i<capacity;i++){
                cout << arr[i]<<" ";
            }
            cout<<endl;
        }
};


// aapke pass koi element hai 'index' par, usko right position par place krna hai[downwards]
void heapify(int *arr, int n, int index){
    int currentIndex = index;
    int leftIndex = 2*index;
    int rightIndex = 2*index + 1;

    int currVal = arr[currentIndex];
    int leftVal = arr[leftIndex];
    int rightVal = arr[rightIndex];

    int sabseBadaElementKaIndex = currentIndex;

    if(currVal > leftVal && currVal >rightVal){
        sabseBadaElementKaIndex = currentIndex;
    }
    if(leftVal > currVal && leftVal >rightVal){
        sabseBadaElementKaIndex = leftIndex;
    }
    if(rightVal > currVal && rightVal >leftVal){
        sabseBadaElementKaIndex = rightIndex;
    }
    if(sabseBadaElementKaIndex != currentIndex){
        swap(arr[currentIndex], arr[sabseBadaElementKaIndex]);
        currentIndex = sabseBadaElementKaIndex;
        // heapify(arr,n,sabseBadaElementKaIndex);
        heapify(arr,n,current);
    }
}

void buildHeap(int){
    // n/2-> 1 index
    for(int i = n/2; i>0;i--){
        heapify(arr,n,i);
    }
}

int main(){

    return 0;
}
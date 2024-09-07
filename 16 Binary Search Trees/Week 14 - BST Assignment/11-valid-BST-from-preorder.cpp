// Valid BST From Preorder

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */

void build(int &i,int min, int max, vector<int>&A){
    if(i>=A.size()) return;
    if(A[i]> min && A[i]<max){
        int rootData = A[i++];
        build(i,min,rootData,A);
        build(i,rootData,max,A);
    }
}
// int solve(int* A, int n1) { 
// }

int Solution::solve(vector<int>&A){
    int min = INT_MIN, max = INT_MAX;
    int i = 0;
    build(i,min,max,A);
    return i == A.size();
}
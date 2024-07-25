// Hackerrank: Get Node Value

#include <bits/stdc++.h>
using namespace std;
/*
 * Complete the 'getNode' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER positionFromTail
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

void fun(SinglyLinkedListNode* head, int &positionFromTail, int&ans){
    // base case
    if(head==NULL) return;
    fun(head->next, positionFromTail, ans);
    if(positionFromTail==0){
        ans = head->data;
    }
    positionFromTail--;
}
int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    int ans = -1;
    fun(llist,positionFromTail,ans);
    return ans;
}
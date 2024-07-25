// gfg
class Solution {
    public:
    void linkdelete(struct Node **head, int N, int M) {
        Node* temp=*head;
        while(true){
            int m=M,n=N;
            m--;
            while(m>0 && temp!=NULL){
                temp=temp->next;
                m--;
            }
            if(temp==NULL) break;
            n++;
            Node* temp2=temp;
            while(n>0 &&temp2!=NULL){
                temp2=temp2->next;
                n--;
            }
            temp->next=temp2;
            temp=temp->next;
        }
    }
};
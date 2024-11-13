// gfg: Union of Two Linked Lists

class Solution {
  public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        map<int,Node*>map;
        Node*curr = head1;
        // L1 hashed
        while(curr){
            map[curr->data] = curr;
            curr = curr->next;
        }
        curr = head2;
        // L2 hashed
        while(curr){
            map[curr->data] = curr;
            curr = curr->next;
        }
        Node* UL = NULL;
        curr = 0;
        // iterate on map and make final union list
        for(auto it = map.begin(); it != map.end(); it++){
            if(!UL){
                UL = it->second;
                curr = UL;
            }
            else{
                curr->next = it->second;
                curr = curr->next;
            }
        }
        curr->next = NULL;
        return UL;
    }
};
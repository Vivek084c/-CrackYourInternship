// Delete nodes having greater value on right
class Solution {
  public:
    Node *compute(Node *head) {
        // reversing the linked list
        if (head == nullptr){
            return NULL;
        }
        Node* prev = NULL;
        Node* cur = head;
        
        while (cur != nullptr){
            Node* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        
        // after the above operatio out new reversed list is haveing prev as new head
        // delete the cur node if the value is less than max
        int max = prev->data;
        Node* PREV = prev;
        cur = prev->next;
        while (cur != nullptr){
            if (cur->data < max){
                // delete the cur node
                prev->next = cur->next;
                cur = cur->next;
            }
            else{
                prev = cur;
                max = cur->data;
                cur = cur->next;
            }
        }
        
        // reversing the list again 
        prev = NULL;
        
        while (PREV != NULL){
            Node* nxt = PREV->next;
            PREV->next = prev;
            prev = PREV;
            PREV = nxt;
        }
        
        return PREV;
        
    }
};
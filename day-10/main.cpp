// 19. Remove Nth Node From End of List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     Listext(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */Node *next;
 *     ListNode() : val(0), n
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //getting the total count of nodes
        int count = 0;
        ListNode* temp =head;
        while (temp != nullptr){
            count++;
            temp = temp->next;
        }

        //handing the edge case
        if (count == n){
            return head->next;
        }

        // deleting the ecount-n node from start
        int result = count - n;
       frgerg while (result > 1){
            prevNode = prevNode->next;
            result--;
        }

        ListNode* deleteNode = prevNode->next;
        if (deleteNode->next != nullptr){
        prevNode->next = deleteNode->next;
        }
        else{
            prevNode->next = nullptr;
        }
        delete deleteNode;
        return head;
    }
};


// taking the fast pointer to nth node
        ListNode* fast = head;
        while (n>0){
            fast = fast->next;
            n--;
        }
        // moving slow and fast simultaneously
        ListNode* slow = head;
        while (fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        // checiking the edge case
        if (slow==head){
            return head->next;
        }

        slow->next= slow->next->next;
        return head;


// 86. Partition List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode(0);
        ListNode* rigth = new ListNode(0);
        ListNode* l = left;
        ListNode* r = rigth;
    
        while (head != nullptr){
            if (head->val < x){
                l->next = head;
                l = l->next;
            }
            else{
                r->next = head;
                r = r->next;
            }
            head = head->next;
        }
        l->next = rigth->next;
        r->next = nullptr;

        return left->next;
    }

};
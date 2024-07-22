// 203. Remove Linked List Elements

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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val){
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }


        ListNode* cur = head;
        ListNode* prev=NULL;
        while (cur != nullptr){
            if (cur->val == val){
                // getting the pointer next to cur
                ListNode* temp = cur->next;
                delete cur;
                if (prev != nullptr){
                    prev->next = temp;
                }
                cur = temp;
            }
            else{
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

// Multiply two linked lists
#define MOD 1000000007
class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        // converting list to long
        long long a = 0;
        while (first != nullptr){
            a = (a * 10 + first->data) % MOD;
            first = first -> next;
        }
        
        long long b = 0;
        while (second != nullptr){
            b = (b * 10 + second->data) % MOD;
            second = second -> next;
        }
       return (a*b) % MOD;
    }
};



// 206. Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        while (head != NULL){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;

        }
        return prev;
    }
};
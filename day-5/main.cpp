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


// 234. Palindrome Linked List


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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next){
            return true;
        }

        // finding midle of linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        //reversing the second half
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        while (curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode* revNode = prev;

        //comparing first and second half
        ListNode* p1 = head;
        ListNode* p2 = revNode;
        bool ispalin = true;
        while (p2){
            if (p1->val != p2->val){
                ispalin = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return ispalin;

    }
};



// Convert Binary number in a linked list to integer


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
    int getDecimalValue(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = NULL;
        while (cur != nullptr){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        // the new reversed linked list has its head at prev
        double ans=0;
        int c=0;
        while (prev != nullptr){
            ans = ans + (pow(2,c++) * (prev->val));
            prev = prev->next;
        }
        return ans;
    }
};
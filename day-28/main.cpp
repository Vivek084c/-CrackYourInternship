// Merge Two Sorted Lists

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // creating a dummy node
        ListNode* dummy = new ListNode(-1);
        // creating a pointer pointing at dummy node
        ListNode* temp = dummy;
        while (list1 != NULL && list2 != NULL){
            if (list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }
                temp = temp->next;
        }
        if (list1 != NULL){
            temp->next = list1;
        }
        else if (list2 != NULL){
            temp->next = list2;
        }
        return dummy->next;
    }
};

// Intersection of Two Linked Lists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // interger to store the number of nodes
        int a=0;
        int b=0;

        // initialising two pointer
        ListNode* l1 = headA;
        ListNode* l2 = headB;

        // traversing and couting the number of total list ndoe
        while (l1 != NULL){
            a++;
            l1 = l1->next;
        }
        while (l2 != NULL){
            b++;
            l2 = l2->next;
        }

        // setting up two pointer and making it stand at same level
        l1 = headA;
        l2 = headB;
        if ((a-b)>0){
            // list a is longer list
            while ((a-b)>0){
                l1 = l1->next;
                a--;
            }
        }
        else if ((b-a)>0){
            // list b is longer list
            while ((b-a)>0){
                l2 = l2->next;
                b--;
            }
        }

        // moving both the pointer simultaneously
        while (l1 != NULL){
            if (l1 == l2){
                return l1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return NULL;

    }
};
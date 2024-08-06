class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        while (head != nullptr){
            if (head->next != nullptr && head->val == head->next->val){
                // skip the equal nodes whoes value are equal
                while (head->next != nullptr && head->val == head->next->val){
                    head=head->next;
                }
                prev->next = head->next;
            }
            else{
                prev = prev->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};
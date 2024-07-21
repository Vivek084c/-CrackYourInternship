// question -4
// 1. Two Sum


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i =0; i<nums.size(); i++){
            int a = nums[i];
            if (map.find(target - a) != map.end()){
                std::vector<int> v;
                v.push_back(map[target - a]);
                v.push_back(i);
                return v;
            }
            map[a] = i;
        }
     return {};
    }
};


//question - 5
// 88. Merge Sorted Array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int insertPointer = m + n -1;

    
    while (m>0 && n>0){
        if (nums1[m-1]>nums2[n-1]){
            nums1[insertPointer--] = nums1[m-1];
            --m;
        }
        else{
            nums1[insertPointer--] = nums2[n-1];
            --n;
        }
    }
    // filling nums1
    while (n>0){
        nums1[insertPointer--] = nums2[n-1];
        --n;
    }

    }
};


// Question -6
// 876. Middle of the Linked List

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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next!= nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


// Question - 7
// 141. Linked List Cycle

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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        if(fast == slow){
            return true;
        }
        }
        return false;
    }
};

// quetion - 8
// 83. Remove Duplicates from Sorted List


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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* cur = head;

        while (cur->next != nullptr){
            if (cur->val == cur->next->val){
                ListNode* temp = cur->next;
                cur->next = temp ->next;
                delete temp;
            }
            else{
                cur = cur->next;
            }

        }
        return head;
    }
};
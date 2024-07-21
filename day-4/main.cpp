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
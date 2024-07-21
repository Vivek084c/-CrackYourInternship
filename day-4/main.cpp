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
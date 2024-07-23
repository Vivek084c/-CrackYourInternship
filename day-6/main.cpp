// 169. Majority Element
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int count = 0;
        int elenment = 0;

        for (int num : nums){
            if (count == 0){
                elenment = num;
            }
            count += (num == elenment ) ? 1 : -1;
        }

        count = 0;
        for (int num : nums){
            if (num == elenment){
                count++;
            }
        }
        return elenment;
        }
    
};


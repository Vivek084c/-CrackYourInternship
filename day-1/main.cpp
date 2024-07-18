// # question -1 
// # 26. Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int k=1; // initialising the unique elenments
        for (int i=1; i < nums.size(); i++){
            if (nums[i] != nums[i-1]){
                nums[k]  = nums[i];
                ++k;
            }
        }
        return k;
    }
};


// question - 2
// 283. Move Zeroes
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=0;

        for (int i=0; i<nums.size(); i++){
            if (nums[i] != 0){
                nums[n++] = nums[i];
            }
        }
        for (int i=n;i<nums.size(); i++){
            nums[i] = 0;
        }
    }
};

//question -3
// 121. Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int buy=0;
        int sell=1;
        while (sell < prices.size()){
            if (prices[buy]<prices[sell]){
                int assumesProfit = prices[sell] - prices[buy];
                if (assumesProfit>max_profit){
                    max_profit = assumesProfit;
                }
            }
            else{
                buy=sell;
            }
            sell++;
        }
        return max_profit;

    }
};

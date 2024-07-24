// 287. Find the Duplicate Number
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // using floyd cycle detection
        int slow, fast;
        slow = 0;
        fast = 0;
        while (true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast){
                break;
            }
        }
        int newslow = 0;
        while (true){
            slow = nums[slow];
            newslow = nums[newslow];
            if (slow == newslow){
                return slow;
            }
        }
    }
};

//75. Sort Colors

class Solution {
public:
    void swap(int i,int j,vector<int>& nums){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void sortColors(vector<int>& nums) {
        int l,r,i;
        i=0;
        l=0;
        r=nums.size() - 1;
        while (i<=r){
            if (nums[i] == 0){
                swap(i,l,nums);
                l+=1;
            }
            else if (nums[i] == 2){
                swap(i,r,nums);
                r-=1;
                i-=1;
            }
            i+=1;

        }
        
    }
};


// 122. Best Time to Buy and Sell Stock II
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i=1;i<prices.size(); i++){
            if (prices[i]>prices[i-1]){
                profit+= prices[i] - prices[i-1];
            }
        }
        return profit;
    }
};
//https://leetcode-cn.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxNum=nums[0];
        int prevMax=nums[0];
        vector<int> maxSize;
        for(int i=1;i<nums.size();i++){
            int cur=prevMax+nums[i];
            int tmp=cur>nums[i]?cur:nums[i];
            prevMax=tmp;
            maxNum=maxNum>prevMax?maxNum:prevMax;
            
        }

        return maxNum;
    }
};
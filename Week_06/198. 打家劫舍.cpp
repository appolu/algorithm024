//https://leetcode-cn.com/problems/house-robber/
class Solution {
public:
    int rob(vector<int>& nums) {
        int max1,max0;
        max1=nums[0];
        max0=0;
        int result;
        for(int i=1;i<nums.size();i++){
            int tmp1=max0+nums[i];
            int tmp0=max(max0,max1);
            max1=tmp1;
            max0=tmp0;
        }
        result=max(max0,max1);
        return result;
    }
};
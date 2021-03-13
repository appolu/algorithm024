//https://leetcode-cn.com/problems/house-robber-ii/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<2){
            return nums[0];
        }
        int max1=nums[0],max0=0;
        int result=0;
        bool first=false;
        for(int i=1;i<nums.size()-1;i++){
            int tmp1,tmp0;
            tmp1=max0+nums[i];
            tmp0=max(max0,max1);
            max0=tmp0;
            max1=tmp1;
        }
        result=max(max0,max1);
        max1=nums[1],max0=0;
        for(int i=2;i<nums.size();i++){
            int tmp1,tmp0;
            tmp1=max0+nums[i];
            tmp0=max(max0,max1);
            max0=tmp0;
            max1=tmp1;
        }
        int tmp=max(max0,max1);
        result=max(result,tmp);
        return result;
    }
};
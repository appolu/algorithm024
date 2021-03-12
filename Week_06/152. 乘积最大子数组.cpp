//https://leetcode-cn.com/problems/maximum-product-subarray/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int xmax=nums[0];
        int xmin=nums[0];
        int result=xmax;
        
        for(int i=1;i<nums.size();i++){
            int mi=xmin,mx=xmax;
            xmax=max(mx*nums[i],max(nums[i],nums[i]*mi));
            xmin=min(mi*nums[i],min(nums[i],mx*nums[i]));
            result=max(result,xmax);
        }
        return result;
    }
};
//https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int min;
    int findMin(vector<int>& nums) {
        find(nums,0,nums.size()-1);
        return min;
    }

    void find(vector<int>& nums,int l, int r){
        int mid=(l+r)/2;
        if(l>r){
            return;
        }
        if(l==r || l+1==r){
            min=nums[l]>nums[r]?nums[r]:nums[l];
            return;
        }
        if(nums[mid]>nums[r]){
            l=mid;
        }else if(nums[mid]<nums[l]){
            r=mid;
        }else if(nums[l]<nums[r]){
            r=mid;
        }else if(nums[l]>nums[r]){
            l=mid;
        }
        
        find(nums,l,r);
    }
};
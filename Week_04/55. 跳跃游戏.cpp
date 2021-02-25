//https://leetcode-cn.com/problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]+i>=end){
                end=i;
            }
        }
        return end==0;
    }
};
//https://leetcode-cn.com/problems/climbing-stairs/description/
class Solution {
public:
    map<int,int> dict;
    int climbStairs(int n) {
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(dict.count(n)){
            return dict[n];
        }
        int steps=climbStairs(n-1)+climbStairs(n-2);
        dict.insert(pair<int,int>(n,steps));
        return steps;
    }
};
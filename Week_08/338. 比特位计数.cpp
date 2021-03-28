//https://leetcode-cn.com/problems/counting-bits/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> size;
        for(int i=0;i<=num;i++){
            int x=calculate(i);
            size.push_back(x);
        }
        return size;
    }

    int calculate(int num){
        if(num==0){
            return 0;
        }
        int sum=0;
        while(num>0){
            sum++;
            num&=num-1;
        }
        return sum;
    }
};
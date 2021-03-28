//https://leetcode-cn.com/problems/reverse-bits/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int size=sizeof(n)*8;
        int x=0;
        uint32_t result=0;
        while(n!=0){
            uint32_t tmp=n;
            n&=n-1;
            uint32_t x= n^tmp;
            int bnum= sums(x);
            uint32_t cal=1<<(size-bnum-1);
            result+=cal;
        }
        return result;
    }

    int sums(uint32_t x){
        int sum=0;
        uint32_t tmp=1;
        while(x-tmp!=0){
            sum++;
            tmp= tmp<<1;
        }
        return sum;
    }

};
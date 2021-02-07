//https://leetcode-cn.com/problems/chou-shu-lcof/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> out(n,0);
        int a=0,b=0,c=0;
        out[0]=1;
        for(int i=1;i<n;i++){
            int r1=min(min(out[a]*2,out[b]*3),out[c]*5);
            out[i]=r1;
            if(out[a]*2==r1){
                a++;
            }
            if(out[b]*3==r1){
                b++;
            }
            if(out[c]*5==r1){
                c++;
            }
        }
        return out[n-1];
    }
};
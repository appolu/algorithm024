//https://leetcode-cn.com/problems/valid-perfect-square/
class Solution {
public:
    bool isc=false;
    bool isPerfectSquare(int num) {
        find(num,0,num);
        return isc;
    }
    
    bool findi(int num){
        int l1=1;
        while(num>0){
            num-=l1;
            l1+=2;
        }
        return num==0;

    }
    void find(long long num,long long left,long long right){
        long long mid=(left+right)/2;
        if(num>right*right){
            return;
        }
        if(left>right){
            return;
        }
        if(num==mid*mid){
            isc=true;
            return;
        }
        if(num>mid*mid){
            left=mid+1;
        }
        if(num<mid*mid){
            right=mid-1;
        }
        find(num,left,right);

    }
};
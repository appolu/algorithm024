//https://leetcode-cn.com/problems/sqrtx/
class Solution {
public:
    int result=0;
    int mySqrt(int x) {
        long long u=x;

        // find(u,0,u);
        findi(x);
        return result;
    }
    void findi(int x){
        if(x==0){

            result=0;
            return;
        }
        double c=x,x0=x;
        
        while(true){
            double xi=0.5*(x0+c/x0);
            if(fabs(x0-xi)<1e-7){
                break;
            }
            x0=xi;
        }
        result=(int)x0;
    }
    //recursion
    void find(long long x,long long l,long long r){
        if(l>r){
            result=r;
            return;
        }
        long long mid=(l+r)/2;
        if(x>=r*r){
            result=r;
            return;
        }
        if(x==mid*mid){
            result=mid;
            return;
        }
        if(x>mid*mid){
            l=mid+1;
        }
        if(x<mid*mid){
            r=mid-1;
        }
        find(x,l,r);
    }
};
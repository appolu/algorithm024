//https://leetcode-cn.com/problems/string-to-integer-atoi/
class Solution {
public:
    int myAtoi(string s) {
        vector<char> nums;
        int negative=0;
        int hasZero=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' ' && negative==0 && nums.size()==0 && hasZero==0){
                continue;
            }
            if(s[i]=='-' && negative==0 && nums.size()==0 && hasZero==0){

                negative=1;
                continue;
            }
            if(s[i]=='+' && negative==0 && nums.size()==0 && hasZero==0){
                negative=2;
                continue;
            }
            if(s[i]>='0' && s[i]<='9'){
                if(nums.size()==0 && s[i]=='0'){
                    hasZero=1;
                    continue;
                }
                nums.push_back(s[i]-'0');
            }else{
                break;
            }
        }
        int size=nums.size();
        if(size>10){
            if(negative==1){
                return INT_MIN;
            }else{
                return INT_MAX;
            }
        }
        long long  num=0,tmp=0;
        for(int i=nums.size()-1;i>=0;i--){
            tmp+=nums[i]*pow(10,size-i-1);
            if(tmp>2147483648){
                break;
            }
        }
        if(negative==1){
                if(tmp>2147483648){
                    num=INT_MIN;
                }
                else{
                    num=-tmp;

                }
        }else{
            if(tmp>=2147483647){
                num=2147483647;
            }else{
                num=tmp;
            }
        }
        return num;
    }

};
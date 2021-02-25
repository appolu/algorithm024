//https://leetcode-cn.com/problems/lemonade-change/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // sort(bills.begin(),bills.end());
        int five=0,ten=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                five++;
            }
            if(bills[i]==10){
                five--;
                ten++;
            }
            if(bills[i]==20){
                if(ten>0){
                    ten--;
                    five--;
                }else{
                    five-=3;;

                }
            }
            if(five<0){
                return false;
            }
        }
        return true;
    }
};
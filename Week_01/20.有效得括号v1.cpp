//利用栈得方式进行模拟pop，复杂度O（N）。
class Solution {
public:
    bool isValid(string s) {
        vector<char> vp;
        for(int i=0;i<s.length();i++){
            char x=s.at(i);
            vp.push_back(x);
            if(vp.size()>=2){
                int count=vp.size();
                if(isPair(vp[count-2],vp[count-1])){
                    vp.pop_back();
                    vp.pop_back();
                }
            }
        }

        if(vp.size()==0){
            return true;
        }else{
            return false;
        }
    }

    bool isPair(char x,char y){
        if(x=='(' && y==')'){
            return true;
        }
        if(x=='[' && y==']'){
            return true;
        }
        if(x=='{' && y=='}'){
            return true;
        }
        return false;
    }
};
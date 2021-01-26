class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> numKey(100);
        int pair=0;
        for(int i=0;i<dominoes.size();i++){
            int key=dominoes[i][0]>dominoes[i][1]?dominoes[i][0]*10+dominoes[i][1]:dominoes[i][0]+dominoes[i][1]*10;
            numKey[key]++;
        }
        for(int i=11;i<100;i++){
            if(numKey[i]>=2)
                pair+=getNum(numKey[i]);
        }
        return pair;
    }

    int getNum(int n){
        return n*(n-1)/2;
    }
};
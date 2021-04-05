//https://leetcode-cn.com/problems/relative-sort-array/
class Solution {
public:
    struct nums{
        int num,count;
    };
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int x=arr2.size();
        map<int,int> indice;
        for(int i=0;i<arr2.size();i++){
            indice.insert(pair<int,int>(arr2[i],i));
        }
        vector<nums*> poin(x);
        vector<nums*> poout;
        vector<int> ps;
        for(int i=0;i<arr1.size();i++){
            if(indice.count(arr1[i])){
                int index=indice[arr1[i]];
                nums *tmp=poin[index];
                if(tmp!=NULL){
                    tmp->count++;
                }else{
                    nums *n=new nums();
                    n->num=arr1[i];
                    n->count=1;
                    poin[index]=n;
                }
            }else{
                nums *n=new nums();
                n->num=arr1[i];
                n->count=1;
                poout.push_back(n);
                ps.push_back(arr1[i]);
            }
        }
        sort(ps.begin(),ps.end());

        vector<int> tm;
        for(int i=0;i<poin.size();i++){
            nums *x=poin[i];
            for(int i=0;i<x->count;i++){
                tm.push_back(x->num);
            }
        }
        for(int i=0;i<ps.size();i++){
            tm.push_back(ps[i]);
        }
        return tm;
    }
};
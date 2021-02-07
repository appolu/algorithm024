//https://leetcode-cn.com/problems/top-k-frequent-elements/
struct PP{
    int nums,numsVal;
    bool operator()(PP& pp1,PP& pp2){
        return pp1.numsVal<pp2.numsVal;
    }

};

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<PP,vector<PP>,PP> m_queue;
        map<int,int> m_map;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            m_map[nums[i]]++;
        }
        for(auto k=m_map.begin();k!=m_map.end();k++){
            PP pp;
            pp.nums=k->first;
            pp.numsVal=k->second;
            m_queue.push(pp);
        }
        for(int i=0;i<k;i++){
            int num=m_queue.top().nums;
            m_queue.pop();
            result.push_back(num);
        }
        return result;
    }
};
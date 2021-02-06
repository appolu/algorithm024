//https://leetcode-cn.com/problems/sliding-window-maximum/
template<typename T>
class cpriority_queue{
    public:
    priority_queue<T> Q,D;
    void push(T x) {Q.push(x);}
    void erase(T x) {D.push(x);}
    bool empty() {
        return Q.empty();
    }
    T top() {
        while(!D.empty()&&Q.top()==D.top()) {Q.pop();D.pop();}
        return Q.empty()?0:Q.top();
    }};

class Solution {
public:
    //优先队列法
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        cpriority_queue<int> que;
        vector<int> result;
        if(nums.size()<k){
            return result;
        }
        for(int i=0;i<k;i++){
            que.push(nums[i]);
        }
        result.push_back(que.top());
        for(int i=k;i<nums.size();i++){
            que.erase(nums[i-k]);
            que.push(nums[i]);
            result.push_back(que.top());
        }
        return result;
    }

    //双端队列法
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        vector<int> result;
        if(nums.size()<k){
            return result;
        }
        deque<int> stack;
        stack.push_back(0);
        for(int i=1;i<k;i++){
            while(!stack.empty() && nums[stack.back()]<nums[i]){
                stack.pop_back();
            }
            stack.push_back(i);

        }

        result.push_back(nums[stack[0]]);
        for(int i=k;i<nums.size();i++){
            while(!stack.empty() && nums[stack.back()]<nums[i]){
                stack.pop_back();
            }
            stack.push_back(i);
            int index=stack[0];
            if(i-index+1>k){
                stack.pop_front();
            }
            index=stack[0];
            result.push_back(nums[stack[0]]);
        }

        return result;
        

    }
};
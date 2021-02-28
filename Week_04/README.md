单词接龙
构建出单词树结构，利用广度优先算法，进行层级遍历获取最优得路径长度。
分发饼干
首先排序好序列，进行递归查找对应得胃口和饼干，最后输出结果。
寻找无序的节点，利用二分法
 void find(vector<int>& nums,int l,int r){
        int mid=(l+r)/2;
        if(l==r){
            result=nums[r];
            
            return;
        }
        if(l+1==r){
            result=nums[r];
            return;
        }
        if(nums[l]>nums[mid]){
            find(nums,l,mid);
        }
        if(nums[r]<nums[mid]){
            find(nums,mid,r);
        }
    }

TBD：529,874
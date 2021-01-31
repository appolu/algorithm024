//https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //return getMaxArea(0,heights.size(),heights);
		int n = heights.size();
		vector<int> ko;
		ko.push_back(0);
		for (int i = 1; i < n; i++) {
			ko.push_back(heights[i - 1]);
		}
		ko.push_back(0);
		n += 2;
		heights = ko;
		vector<int> stack;
		int areaMax = 0;
		for (int i = 1; i < n; i++) {
			while (heights[stack.back()] > heights[i]) {
				int index = stack.back();
				int h = heights[stack.back];
				stack.pop_back();
				index = stack.back();
				int area = h*(i - index-1);
				areaMax = areaMax > area ? areaMax : area;
			}
			stack.push_back(i);

		}
		return areaMax;
    }
    ////递归计算获取最大面积
    //int getMaxArea(int startIndex,int EndIndex,vector<int >& heights){
    //    if(startIndex+1==EndIndex || startIndex ==EndIndex){
    //        return heights[startIndex];
    //    }
    //    int index= getAreaMinIndex(startIndex,EndIndex,heights);
    //    int h= heights[index];
    //    int avArea=h*(EndIndex-startIndex);
    //    int avMin=getMaxArea(startIndex,index,heights);
    //    int avMax=0;
    //    if(index+1<EndIndex){
    //        avMax=getMaxArea(index+1,EndIndex,heights);
    //    }
    //    avArea= avArea>avMin?avArea:avMin;
    //    avArea=avArea>avMax?avArea:avMax;
    //    return avArea;
    //}
    ////获取最小值索引
    //int getAreaMinIndex(int startIndex,int EndIndex,vector<int>& heights){
    //    int minIndex=startIndex;
    //    int minum=heights[startIndex];
    //    for(int i=startIndex;i<EndIndex;i++){
    //        if(minum>heights[i]){
    //            minum=heights[i];
    //            minIndex=i;
    //        }
    //    }
    //    return minIndex;
    //}
};
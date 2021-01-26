#include <vector>
//夹逼法
class solution
{
public:
	int maxArea(vector<int > heights) {
		int max = 0;
		for (int i = 0, j = heights.size() - 1; i < j;) {
			int w = j - i;
			int h = heights[j] > heights[i] ? heights[i++] : heights[j--];//判断首尾高度，低得一方，往中间缩进。
			int area = w * h;
			if (area > max) {
				max = area;
			}
		}
		return max;
	}

};
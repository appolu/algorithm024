#include <map>
//https://leetcode-cn.com/problems/3sum/
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> results;
		//异常处理返回
		if (nums.empty() || nums.size() < 3) {
			return results;
		}
		sort(nums.begin(), nums.end());//排序
		int n = nums.size() - 1;
		vector<int> result(3);
		for (int i = 0; i < nums.size() - 2; i++) {
			int l = nums[i];
			if (l > 0) {
				break;
			}
			if (i > 0 && nums[i - 1] == nums[i]) {
				continue;
			}
			int j = i + 1;
			int k = n;
			while (j < k) {
				int add = nums[j] + nums[k] + l;
				if (add == 0) {
					result[0] = l; result[1] = nums[j]; result[2] = nums[k];
					results.push_back(result);
					while (j < k && nums[j] == nums[++j]) {}
					while (j < k && nums[k] == nums[--k]) {}
				}
				if (add > 0) {
					k--;
				}
				if (add < 0) {
					j++;
				}
			}
		}
		return results;
	}

};
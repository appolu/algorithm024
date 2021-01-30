//https://leetcode-cn.com/problems/two-sum/
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> values;
		vector<int> elements;

		for (int i = 0; i < nums.size(); i++) {
			int key = nums[i];
			int num = find(target - key, values);

			if (num >= 0) {
				elements.push_back(num);
				elements.push_back(i);
				return elements;

			}
			values.insert(pair<int, int>(key, i));
		}
		return elements;

	}

	int find(int x, map<int, int> &values) {
		map<int, int>::iterator iter = values.find(x);
		if (iter != values.end()) {
			return iter->second;
		}
		return -1;
	}
};
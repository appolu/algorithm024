//https://leetcode-cn.com/problems/group-anagrams/
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<string> tmpstr;
		for (int i = 0; i < strs.size(); i++) {
			tmpstr.push_back(strs[i]);
		}
		map<string, vector<string>> index;
		for (int i = 0; i < tmpstr.size(); i++) {
			sort(tmpstr[i].begin(), tmpstr[i].end());
			if (index.count(tmpstr[i])) {
				vector<string> tmp = index[tmpstr[i]];
				tmp.push_back(strs[i]);
				index[tmpstr[i]] = tmp;
			}
			else {
				vector<string> tmp;
				tmp.push_back(strs[i]);
				index.insert(pair<string, vector<string>>(tmpstr[i], tmp));
			}
		}
		map<string, vector<string>>::iterator mit;
		vector<vector<string>> result;
		for (mit = index.begin(); mit != index.end(); mit++) {
			result.push_back(mit->second);
		}
		return result;
	}
};
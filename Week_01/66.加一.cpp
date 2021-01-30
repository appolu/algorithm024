//https://leetcode-cn.com/problems/plus-one/
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int n = digits.size() - 1;
		digits[n] += 1;
		while (digits[n] > 9) {
			int x = digits[n];
			digits[n] %= 10;
			n--;
			if (n < 0) {
				vector<int>::iterator iter = digits.begin();
				digits.insert(iter, x / 10);
				break;
			}
			else {
				digits[n] += 1;
			}
		}
		return digits;
	}
};
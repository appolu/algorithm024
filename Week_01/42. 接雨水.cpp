//https://leetcode-cn.com/problems/trapping-rain-water/
class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() < 3) {
			return 0;
		}
		int water = 0;
		deque<int> wc;
		int curIndexWater = -1;
		vector<int> lh, rh;
		lh.push_back(height[0]);
		for (int i = 1; i < height.size(); i++) {
			if (lh.back() < height[i]) {
				lh.push_back(height[i]);
			}
			else {
				lh.push_back(lh.back());
			}
		}
		int n = height.size() - 1;
		rh.push_back(height[n]);
		for (int i = height.size() - 2; i >= 0; i--) {
			if (rh.back() < height[i]) {
				rh.push_back(height[i]);
			}
			else {
				rh.push_back(rh.back());
			}
		}
		int result = 0;
		for (int i = 1; i < n; i++) {
			int lfv = lh[i];
			int rfv = rh[n - i];
			int val = lfv > rfv ? rfv : lfv;
			result += val - height[i];
		}
		return result;
	}
	//栈方法求解
	int trap1(vector<int>& height) {
		if (height.size() < 3) {
			return 0;
		}
		int n = height.size();
		int i = 0, j = n;
		vector<int> h;
		int result = 0;
		while (i < j) {
			while (!h.empty() && height[h.back()] < height[i]) {
				int ch = height[h.back()];
				h.pop_back();
				if (h.empty()) {
					break;
				}
				int left = h.back();
				int w = i - left - 1;
				int th = height[h.back()] - ch;
				int fh = height[i] - ch;
				th = th > fh ? fh : th;
				result += w * (th);
			}
			h.push_back(i++);
		}
		return result;
	}

};
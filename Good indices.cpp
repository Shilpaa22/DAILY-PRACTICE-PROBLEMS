class Solution {
public:
	vector<int> goodIndices(vector<int> &nums, int k) {
		int n = nums.size();
		vector<int> res, left(n), right(n);
		left[n - 1] = 1, right[0] = 1;
		for (int i = n - 2; i >= 0; i--) {
			if (nums[i] > nums[i + 1]) left[i] = 1;
			else left[i] = left[i + 1] + 1;
		}
		for (int i = 1; i < n; i++) {
			if (nums[i] > nums[i - 1]) right[i] = 1;
			else right[i] = right[i - 1] + 1;
		}
		for (int i = 1; i < n - 1; i++) {
			if (left[i + 1] >= k && right[i - 1] >= k) {
				res.push_back(i);
			}
		}
		return res;
	}
};
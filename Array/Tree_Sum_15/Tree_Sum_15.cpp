//O(n^2) time

#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
		std::vector<std::vector<int>> res_vec;

		std::sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			
			if (i > 0 && nums[i] == nums[i - 1]) continue;

			int first_el = nums[i];
			int l = i + 1;
			int r = nums.size() - 1;
			int sum_of_two = 0 - first_el;

			while (l < r) {
				int left = nums[l];
				int right = nums[r];
				if (left + right < sum_of_two) l++;
				else if (left + right > sum_of_two) r--;
				else {
					res_vec.push_back(std::vector<int>({ first_el, left, right }));

					while (l < r && nums[l] == left) l++;
					while (l < r && nums[r] == right) r--;
				}
			}
		}
		return res_vec;
	}	
};

int main() {
	Solution sln;
	std::vector<int> v = { -1, 0, 1, 2, -1, -4 };
	std::vector<std::vector<int>> result = sln.threeSum(v);
	for (int i = 0; i < result.size(); i++)
		std::cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << std::endl;
}
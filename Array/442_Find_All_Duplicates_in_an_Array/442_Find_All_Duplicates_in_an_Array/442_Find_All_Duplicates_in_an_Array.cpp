#include <vector>
#include <cmath>
#include <iostream>
class Solution {
public:
	std::vector<int> findDuplicates(std::vector<int>& nums) {
		std::vector<int> vec;

		for (int el : nums) {
			int index = abs(el) - 1;
			if (nums[index] < 0)
				vec.push_back(abs(el));
			else
				nums[index] *= -1;
		}
		return vec;
	}
};
int main() {
	Solution sln;
	std::vector<int> elements = { 4,3,2,7,8,2,3,1 };
	std::vector<int> vec = sln.findDuplicates(elements);
	for (int el:vec)
		std::cout << el << " ";
}
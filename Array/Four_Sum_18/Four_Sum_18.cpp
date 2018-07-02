class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> vec;
		
		for(int i = 0; i < nums.size(); i++){
			for(int j = i; j < nums.size(); j++){
				for(int n = j; n < nums.size(); n++){
					for(int m = n; m < nums.size(); m++){
						if(nums[i]+nums[j]+nums[n]+nums[m]==target){
							std::vector<int> v;
							v.push_back(nums[i]);
							v.push_back(nums[j]);
							v.push_back(nums[n]);
							v.push_back(nums[m]);
							vec.push_back(v);
						}
					}
				}
			}
		}
		return vec;
    }
};
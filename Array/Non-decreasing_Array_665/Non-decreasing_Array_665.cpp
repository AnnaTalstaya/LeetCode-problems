class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int number = 0;
		if(nums.size()==1) return true;
		for(int i = 0; i < nums.size()-1 && number <=1; i++){
			if(nums[i] > nums[i+1]){
				number++;
                if(nums[i-1] > nums[i+1] && i!=0)
                    nums[i+1] = nums[i];
                else if(i==0)
                    nums[i]=nums[i+1];
              
            }
		}
		return number <=1;
    }
};
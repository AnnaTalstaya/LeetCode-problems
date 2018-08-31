#include <vector>
#include <iosream>

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        std::vector<int> vec = {3,4,5,799,1};
		int index = -1;
		int sum;
		
		if(vec.size() == 1)
			return vec[0];
		if(vec.size() == 2){
			if(vec[0] >= vec[1])
				return vec[1];
			else return vec[0];
		}
		else{
			for(int i = 0; i < vec.size(); i++){
				if(index+2 < vec.size()){
					if(vec[index+1] > vec[index+2]){
						sum+= vec[index+2];
						index += 2;
					}
					else{
						sum+= vec[index+1];
						index++;
					}
						
				}				
			}
		}
		
		std::cout << sum;
		
    }
};
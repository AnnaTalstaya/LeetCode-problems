class Solution(){
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
		int index = m + n - 1;
		int i = m - 1;
		int j = n - 1;
		while(j >= 0){
			nums1[index--] = (i >=0 && nums1[i] > nums2[j]) ? nums1[i--]:nums2[j--];
		}
			
	}
}

int main(){
	
}
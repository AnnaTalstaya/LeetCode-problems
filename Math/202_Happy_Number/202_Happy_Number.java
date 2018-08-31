class Solution {
    public boolean isHappy(int n) {
        if (n <= 0)
			return false;
        Set<Integer> my_set = new HashSet();

		int number = n;
        my_set.add(n);
		while (n != 1) {
			int x = 0;
			while (n!=0) {
				x += Math.pow(n % 10, 2);
				n /= 10;
			}
			n = x;
			
		    if(!my_set.add(n))
                return false;
		}
		return true;
    }
}
/*
Difficulty: easy

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:
Input: 121
Output: true

Example 2:
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Follow up:
Could you solve it without converting the integer to a string?

*/

//my solution of this task
#include <cstring>
#include <cmath>
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        else{
            int num = 0;
            int count = -1;
            int copy_x = x;
            while(copy_x){
                count++;
                copy_x /= 10;
            }
            copy_x = x;
            while(copy_x){
                int remainder = copy_x % 10;
                copy_x /= 10;
                num += remainder * pow(10, count);
                count--;
            }
            if(num == x)
                return true;
            else return false;
        }
    }
};

//not mine solution, but it's better one
class Solution {
public:
    bool isPalindrome(int x) {
       if(x < 0 || (x && x%10 == 0))
			return false;
		else{
			int number = 0;
			
			while(x > number){
				number = number*10 + x%10;
				x /= 10;
			}
			return (number == x || x == number/10);
		}
    }
};
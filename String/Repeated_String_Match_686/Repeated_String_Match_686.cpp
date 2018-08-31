/*
Difficulty: easy

Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.
For example, with A = "abcd" and B = "cdabcdab".
Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.

*/
/*
Difficulty: easy

Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.
For example, with A = "abcd" and B = "cdabcdab".
Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.

*/


//mine not very good solution
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	int repeatedStringMatch(string A, string B) {
		string A_original = A;
		int doublications = 1;
		long long hash_B = hash(B);

		while (A.length() <= A_original.length()*2 + B.length()) {
			if (A.length() >= B.length() && rabin_karp_Is_substring(B, A, hash_B)) {
				return doublications;
			}
			else {
				A += A_original;
				doublications++;
			}
		}
		return -1;

	}

	bool rabin_karp_Is_substring(string B, string A, int hash_B) {
		long long hash_A_substr = 0;
		char first_char = A.at(0);
		string A_substr = "";
		for (int i = 0; i < B.length(); i++) {
			A_substr += A.at(i);
		}

		hash_A_substr = hash(A_substr);
		if (hash_A_substr == hash_B && A.find(B) != string::npos)
			return true;

		int i = B.length();
		while (i < A.length()) {
			hash_A_substr = hash_A_substr - code(first_char)*pow(1, B.length() - 1) + code(A.at(i));
			A_substr.erase(0, 1);
			first_char = A_substr.at(0);
			A_substr += A.at(i);
			if (hash_A_substr == hash_B && A_substr.find(B) != string::npos)
				return true;
			else {
				i++;
			}
		}
		return false;
	}

	int code(char ch) {
		return (int)ch;
	}

	long long hash(string str) {
		long long my_hash = 0;
		for (int i = str.length()-1, j = 0; i >= 0; i--, j++) {
			my_hash += code(str.at(i))*pow(1, j);
		}
		return my_hash;
	}

};

int main() {
	Solution sln;
	cout << sln.repeatedStringMatch("aaaaaaaaaaaaaaaaaaaaaab", "ba");
}

//best solutions

/*first
Time Complexity: O(N*(N+M)), where M, N are the lengths of strings A, B. We create two strings A * q, A * (q+1) which have length at most O(M+N). 
When checking whether B is a substring of A, this check takes naively the product of their lengths.

Space complexity: As justified above, we created strings that used O(M+N) space.
*/

class Solution {
public:
	int repeatedStringMatch(string A, string B) {
        int q = 1;
		string str = A;
        for (; str.length() < B.length(); q++) str += A;
		
		if(str.find(B) != string::npos) return q;
  
        if ((str+A).find(B) != string::npos) return q+1;
        return -1;
    }

};


/*second Rabin-Karp
Time Complexity: O(M+N)(at these sizes), where M,N are the lengths of strings A, B. As in Approach #1, we justify that A * (q+1) will be of length O(M + N)O(M+N), 
and computing the rolling hashes was linear work. We will also do a linear O(N) final check of our answer 1+O(M)/M times. 
In total, this is O(M+N+N*(1+M)) work. Since M≤10000<M=10^9+7, we can consider this to be linear behavior.

Space complexity: O(1). Only integers were stored with additional memory.
*/

import java.math.BigInteger;

class Solution {
    public boolean check(int index, String A, String B) {
        for (int i = 0; i < B.length(); i++) {
            if (A.charAt((i + index) % A.length()) != B.charAt(i)) {
                return false;
            }
        }
        return true;
    }
    public int repeatedStringMatch(String A, String B) {
        int q = (B.length() - 1) / A.length() + 1;
        int p = 113, MOD = 1_000_000_007;
        int pInv = BigInteger.valueOf(p).modInverse(BigInteger.valueOf(MOD)).intValue();

        long bHash = 0, power = 1;
        for (int i = 0; i < B.length(); i++) {
            bHash += power * B.codePointAt(i);
            bHash %= MOD;
            power = (power * p) % MOD;
        }

        long aHash = 0; power = 1;
        for (int i = 0; i < B.length(); i++) {
            aHash += power * A.codePointAt(i % A.length());
            aHash %= MOD;
            power = (power * p) % MOD;
        }

        if (aHash == bHash && check(0, A, B)) return q;
        power = (power * pInv) % MOD;

        for (int i = B.length(); i < (q + 1) * A.length(); i++) {
            aHash -= A.codePointAt((i - B.length()) % A.length());
            aHash *= pInv;
            aHash += power * A.codePointAt(i % A.length());
            aHash %= MOD;
            if (aHash == bHash && check(i - B.length() + 1, A, B)) {
                return i < q * A.length() ? q : q + 1;
            }
        }
        return -1;
    }
}
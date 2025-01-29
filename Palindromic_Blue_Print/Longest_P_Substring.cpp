class Solution {
public:
    int t[1001][1001]; // DP Table
    
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        
        memset(t, 0, sizeof(t)); // Initialize the DP table with false
        
        int maxLen = 1;  // Minimum palindrome length is 1
        int start_idx = 0;
        
        // One-length substrings are palindromes
        for (int i = 0; i < n; i++) {
            t[i][i] = true;
        }
        
        // Two-length substrings
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                t[i][i + 1] = true;
                maxLen = 2;
                start_idx = i;
            }
        }

        // Expanding to substrings of length 3 and more
        for (int L = 3; L <= n; L++) {  // L is the length of the substring
            for (int i = 0; i + L - 1 < n; i++) {
                int j = i + L - 1;
                
                if (s[i] == s[j] && t[i + 1][j - 1]) {
                    t[i][j] = true;
                    maxLen = L;
                    start_idx = i;
                }
            }
        }

        return s.substr(start_idx, maxLen);
    }
};

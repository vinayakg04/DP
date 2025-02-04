class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return s;
        
        string rev = s;
        reverse(rev.begin(), rev.end());

        string t = s + "#" + rev;  // Use '#' to separate original and reverse
        int m = t.size();
        vector<int> LPS(m, 0);
        
        // Compute LPS array (KMP preprocessing)
        int i = 1, l = 0;
        while (i < m) {
            if (t[i] == t[l]) {
                l++;
                LPS[i] = l;
                i++;
            } else {
                if (l != 0) {
                    l = LPS[l - 1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }

        int len = LPS[m - 1];  // Length of longest palindromic prefix
        return rev.substr(0, n - len) + s;
    }
};

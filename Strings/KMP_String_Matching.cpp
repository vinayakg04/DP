class Solution {
public:
    int m; 

    void findLPS(vector<int>& LPS, string& pat) {
        int l = 0;
        LPS[0] = 0;
        int i = 1;

        while (i < m) {
            if (pat[i] == pat[l]) {
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
    }

    int strStr(string txt, string pat) {
        int n = txt.size();
        m = pat.size();

        if (m == 0) return 0;  // If pattern is empty, return 0

        vector<int> LPS(m, 0);
        findLPS(LPS, pat);  // Compute LPS array

        int i = 0, j = 0;
        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }

            if (j == m) {
                return i - m;  // Return first occurrence index
            } else if (i < n && txt[i] != pat[j]) { // Avoid out-of-bounds
                if (j != 0) {
                    j = LPS[j - 1];
                } else {
                    i++;
                }
            }
        }

        return -1; // Pattern not found
    }
};


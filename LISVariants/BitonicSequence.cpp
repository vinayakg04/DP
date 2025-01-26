class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
   
    vector<int> inc(n, 1), dec(n, 1); // inc[i]: LIS ending at i, dec[i]: LIS starting at i

    // Compute LIS ending at each index
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                inc[i] = max(inc[i], inc[j] + 1);
            }
        }
    }

    // Compute LIS starting at each index (reverse traversal)
    for (int i = n - 2; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (nums[j] < nums[i]) {
                dec[i] = max(dec[i], dec[j] + 1);
            }
        }
    }

    // Combine LIS and LDS for maximum length
    int maxBitonic = 0;
    for (int i = 0; i < n; ++i) {
        if(inc[i]>1 && dec[i]>1){
            maxBitonic=max(maxBitonic,inc[i]+dec[i]-1);
        }
    }
    return maxBitonic;
    }
};

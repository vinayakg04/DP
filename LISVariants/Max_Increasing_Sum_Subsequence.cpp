class Solution{
  public:
    int maxSumIS(vector<int>& arr) {
        // Your code goes here
      int n = arr.size();
    int maxS = arr[0];  // Initialize to the first element of the array.
    vector<int> t = arr;  // Initialize `t` as a copy of `arr`.

    for (int i = 1; i < n; i++) {  // Start from the second element.
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                t[i] = max(t[i], arr[i] + t[j]);  // Update `t[i]` with the max sum.
            }
        }
        maxS = max(maxS, t[i]);  // Update the maximum sum.
    }

    return maxS;
    }
};

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        int max_so_far=arr[0];
        int max_all=arr[0];
        
        for(int i=1;i<n;i++){
            max_so_far=max(arr[i],arr[i]+max_so_far);
            max_all=max(max_all,max_so_far);
        }
        
        return max_all;
    }
};

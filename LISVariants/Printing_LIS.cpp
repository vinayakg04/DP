 class Solution{
  public:
    
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        
    
         vector<int> dp(n,1);
       vector<int> tracker(n,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i]){
                    if(dp[j]+1>dp[i]){
                        dp[i] = dp[j] +1;
                        tracker[i] = j;
                    }
                }
            }
        }
        int maxi = 0 ,index = -1;
        for(int i = 0 ;i<n;i++){
            if(dp[i]>maxi){
                maxi = dp[i];
                index = i;
            }
        }
        vector<int> ans;
        while(index!=-1){
            ans.push_back(arr[index]);
            index = tracker[index];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

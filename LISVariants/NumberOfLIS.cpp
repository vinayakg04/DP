class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> t(n,1);  //LENGTH OF LIS ENDING AT i
        vector<int> count(n,1); //COUNT OF LIS ENDING AT i

        int numberofLIS=0;

        int maxLength=1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (t[j] + 1 > t[i]) {
                        t[i] = t[j] + 1;
                        count[i] = count[j];  // Reset count[i] to count[j]
                    } else if (t[j] + 1 == t[i]) {
                        count[i] += count[j];  // Add count[j] to count[i]
                    }
                }
            }
            maxLength = max(maxLength, t[i]); // Update maxLength
        }

        for(int i=0;i<n;i++){
            if(t[i]==maxLength){
                numberofLIS+=count[i];
            }
        }
        

        return numberofLIS;

        
    }
};

class Solution{
public:
int t[2501][2501];
    int solve(int i,int p,vector<int> &nums){
        int n=nums.size();
        if(i==n) return 0;

        if(p!=-1 && t[i][p+1]!=-1) return t[i][p+1];

        //take the ith value
        int take=0;
        if(p==-1 || nums[i]>nums[p]){
            take=1+solve(i+1,i,nums);
        }

        //skip the ith value here
        int skip=solve(i+1,p,nums);

        return t[i][p+1]=max(skip,take);
    }


};

class Solution {
public:
    int t[1001][1001];
    int solve(int m,int n,string &s1, string& s2){
        if(m==0 || n==0) return 0;

        if(t[m][n]!=-1){
            return t[m][n];
        }

        if(s1[m-1]==s2[n-1]){
            return t[m][n]=1+solve(m-1,n-1,s1,s2);
        }else{
            return t[m][n]=max(solve(m-1,n,s1,s2),solve(m,n-1,s1,s2));
        }
    }
    int longestCommonSubsequence(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();

        memset(t,0,sizeof(t));
        // return solve(m,n,s1,s2);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }

        return t[m][n];
    }
};

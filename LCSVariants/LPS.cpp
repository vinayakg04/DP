class Solution {
public:
    int t[1001][1001];
    int solve(int m,int n,string& s,string& r){
        if(m==0 || n==0) return 0;

        if(t[m][n]!=-1){
            return t[m][n];
        }
        if(s[m-1]==r[n-1]){
            return t[m][n]=1+solve(m-1,n-1,s,r);
        }

        return t[m][n]=max(solve(m-1,n,s,r),solve(m,n-1,s,r));
    }
    int longestPalindromeSubseq(string s) {
        int m=s.size();
        memset(t,-1,sizeof(t));
        string r=s;
        reverse(r.begin(),r.end());

        int n=r.size();

        // return solve(m,n,s,r);

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==r[j-1]){
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

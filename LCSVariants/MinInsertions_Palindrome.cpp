class Solution {
public:
    int t[501][501];
    int minInsertions(string s) {
        int m=s.size();
        string r=s;
        reverse(r.begin(),r.end());
        int n=r.size();

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

        int LPS_Length=t[m][n];
        return m-LPS_Length;
    }
};

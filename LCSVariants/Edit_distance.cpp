class Solution {
public:
int t[501][501]; // Memoization table

int solve(int m, int n, string &s1, string &s2) {
    // Base Case: If one of the strings is empty
    if (m == 0 || n == 0) {
        return m + n;
    }

    // Memoization: Return cached result if already computed
    if (t[m][n] != -1) {
        return t[m][n];
    }

    // If the last characters are the same, no edit is required for this step
    if (s1[m - 1] == s2[n - 1]) {
        return t[m][n] = solve(m - 1, n - 1, s1, s2);
    }

    // If characters are different, calculate the minimum cost of all operations
    int insertC = 1 + solve(m, n - 1, s1, s2);       // Insert
    int deleteC = 1 + solve(m - 1, n, s1, s2);       // Delete
    int replaceC = 1 + solve(m - 1, n - 1, s1, s2);  // Replace

    return t[m][n] = min({insertC, deleteC, replaceC});
}
    int minDistance(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        memset(t,-1,sizeof(t));

        // return solve(m,n,s1,s2);

        for(int i=0;i<=m;i++) t[i][0]=i;
        for(int j=0;j<=n;j++) t[0][j]=j;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=t[i-1][j-1];
                }else{
                    t[i][j]=1+min({t[i-1][j-1],t[i-1][j],t[i][j-1]});
                }
            }
        }

        return t[m][n];


    }
};

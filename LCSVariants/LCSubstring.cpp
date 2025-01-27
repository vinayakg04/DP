   int t[1001][1001];
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int m=s1.size();
        int n=s2.size();
        
        int result=0;
    
        memset(t,0,sizeof(t));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                    result=max(result,t[i][j]);
                }
                else{
                    t[i][j]=0;
                }
            }
        }
        
        return result;
    }

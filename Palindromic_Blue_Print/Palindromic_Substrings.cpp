class Solution {
public:
    int t[1001][1001];
    bool check(int i,int j,string& s){
        if(i>j) return true;
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(s[i]==s[j]) return t[i][j]=check(i+1,j-1,s);

        return t[i][j]=false;
    }
    int countSubstrings(string s) {
        int m=s.size();
        memset(t,-1,sizeof(t));
        int count_string=0;
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                if(check(i,j,s)){
                    count_string++;
                }
            }
        }

        return count_string;
    }
};

class Solution {
public:
    string longestPrefix(string s) {
        string res;
        int n=s.size();
        vector<int> LPS(n,0);
        LPS[0]=0;

        int i=1;
        int l=0;

        while(i<n){
            if(s[i]==s[l]){
                // res+=s[l];
                l++;
                LPS[i]=l;
                i++;
                
            }
            else{
                if(l!=0){
                    l=LPS[l-1];
                }else{
                    LPS[i]=0;
                    i++;
                }
            }
        }

        return s.substr(0,LPS[n-1]);

    }
};

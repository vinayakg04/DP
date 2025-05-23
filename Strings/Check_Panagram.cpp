class Solution {
public:
    bool checkIfPangram(string sentence) {
        //This method takes O(N) Time Complexity
         int l=sentence.size();
         if(l<26){
            return false;
         }

         bool flag=false;

        set<char> st;

        for(char c: sentence){
            st.insert(c);
        }

        return st.size()==26;
        

    }
};

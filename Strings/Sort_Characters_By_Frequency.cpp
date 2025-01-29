class Solution {
public:
    typedef pair<int,int> tp;
    string frequencySort(string s) {
        string ans;
        map<char,int> mp;
        for(auto i: s){
            mp[i]++;
        }

        // priority_queue<tp,vector<tp>,greater<tp>> maxh;
        priority_queue<pair<int,int>> maxh;
        for(auto it=mp.begin();it!=mp.end();it++){
            maxh.push({it->second,it->first});
        }

        while(maxh.size()>0){
            auto p=maxh.top();
            char c=p.second;
            int freq=p.first;
            while(freq>0){
                ans+=c;
                freq--;
            }
            maxh.pop();
        }

   
        return ans;

        
    }
};

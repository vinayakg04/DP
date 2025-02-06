class Solution {
public:
    int t[50001][2];
    int solve(vector<int>& prices,int day,int n,bool buy){
        if(day>=n) return 0;

        int profit=0;

        if(t[day][buy]!=-1){
            return t[day][buy];
        }

        if(buy){
            int take=solve(prices,day+1,n,false)-prices[day];
            int not_take=solve(prices,day+1,n,true);
            profit=max(take,not_take);
            
        }
        else{
            int sell=prices[day]+solve(prices,day+1,n,true);
            int not_sell=solve(prices,day+1,n,false);
            profit=max(sell,not_sell);
        }

        return t[day][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        bool buy=true;

        // Correct way to initialize a 2D array to -1
        for (int i = 0; i < n; i++) {
            t[i][0] = -1;
            t[i][1] = -1;
        }

        return solve(prices,0,n,buy);
    }
};

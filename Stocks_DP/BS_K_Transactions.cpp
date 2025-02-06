class Solution {
public:
    int t[5001][2][101]; // Adjusted array size (transactions <= 100)

    int solve(vector<int>& prices, int day, int n, bool buy, int k) {
        if (k == 0 || day >= n) return 0; // Base case: No transactions left or out of days

        if (t[day][buy][k] != -1) return t[day][buy][k]; // Check memoization table

        int profit = 0;

        if (buy) {
            // Either buy today (keep k same) or skip buying
            int take = solve(prices, day + 1, n, false, k) - prices[day];
            int not_take = solve(prices, day + 1, n, true, k);
            profit = max(take, not_take);
        } else {
            // Either sell today (reduce k) or skip selling
            int sell = prices[day] + solve(prices, day + 1, n, true, k - 1);
            int not_sell = solve(prices, day + 1, n, false, k);
            profit = max(sell, not_sell);
        }

        return t[day][buy][k] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0; // Edge case: No transactions or prices

        memset(t, -1, sizeof(t)); // Initialize DP table with -1

        return solve(prices, 0, n, true, k);
    }
};


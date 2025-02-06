class Solution {
public:
    int t[100001][2][101]; // Adjusted array size for k ≤ 100

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

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0; // Edge case: No prices or transactions

        memset(t, -1, sizeof(t)); // Correctly initialize the DP table

        return solve(prices, 0, n, true, 2);
    }
};


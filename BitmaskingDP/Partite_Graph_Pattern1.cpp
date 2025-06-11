//There are N ranks and M students in a class. 
//Each student has a happiness value for the rank in the class they get. 
//The i-th student gets happy[i][j] on getting a rank j. It’s okay to not keep all students in the ranks (they get 0 happiness). 
//At most one student can be assigned to a rank.
//The total happiness of the assignment can be calculated as the sum of happiness of each student in the class. 
//Find the best way to calculate the maximum happiness attainable.

//Constraints:
//1 ≤ N ≤ 15
//1 ≤ M ≤ 50
//0 ≤ happy[i][j] ≤ 10⁵

int rec(int level, int mask) {
    if (level == m) {
        return 0;
    }
    if (dp[level][mask] != -1) return dp[level][mask];

    int ans = 0;

    // Case 1: Skip assigning this student to any rank
    ans = max(ans, rec(level + 1, mask));

    // Case 2: Try assigning the student to an available rank
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) { // Check if rank i is available
            ans = max(ans, arr[level][i] + rec(level + 1, (mask | (1 << i))));
        }
    }

    return dp[level][mask] = ans;
}

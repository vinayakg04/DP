//A city is modeled using a graph with N nodes and M edges. The nodes are numbered from 1 to N.
//A person is standing at node 1 and wants to visit a friend at city N. 
//He wants to visit every city exactly once. Find the number of paths that exist of this form.
//Constraints
//N <= 20
int rec(int node, int mask) {
    if (mask == (1 << n) - 1) { 
        // Check if we reached the destination node `n`
        return (node == n) ? 1 : 0;
    }

    if (dp[node][mask] != -1) return dp[node][mask];

    int ans = 0;

    for (auto v : g[node]) {
        // If node `v` is not visited
        if (((mask >> v) & 1) == 0) { 
            ans += rec(v, mask | (1 << v));  
        }
    }
    return dp[node][mask] = ans; 
}


*****************************************************************************************************************************************************************************

//Variant 1: Shortest Hamiltonian Path from Any City

//Similarly, we can use the recursive approach rec(node, mask)
//but instead of counting paths, we now find the shortest Hamiltonian path.

//Key Difference:
//Instead of returning the number of valid paths, rec(node, mask) will return the length of the shortest path that visits all cities exactly once, starting from node and considering mask as the visited status.

int rec(int node, int mask) {
    if (mask == ((1 << n) - 1)) return 0;

    if (dp[node][mask] != -1) return dp[node][mask];

    int ans = 1e9; 
    for (auto v : g[node]) {
        int nextNode = v.first;  
        int weight = v.second;
        if (((mask >> nextNode) & 1) == 0) { 
            ans = min(ans, rec(nextNode, mask | (1 << nextNode))) + weight; 
        }
    }
    
    return dp[node][mask] = ans; 
}

void solve() {
    int sh_path = 1e9;  
    for (int i = 0; i < n; i++) {
        sh_path = min(sh_path, rec(i, (1 << i)));  // Try starting from each node
    }
    cout << sh_path << endl;
}


*****************************************************************************************************************************************************************************

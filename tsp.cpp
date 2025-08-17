#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
vector<vector<int>> dist;
vector<vector<int>> dp;

 int tsp(int mask, int pos)
{
     if (mask == (1 << n) - 1)
    {
        return dist[pos][0];  
     if (dp[mask][pos] != -1)
    {
        return dp[mask][pos];
    }

    int ans = INT_MAX;  

     for (int next = 0; next < n; next++)
    {
         if ((mask & (1 << next)) == 0)
        {
             int newAns = dist[pos][next] + tsp(mask | (1 << next), next);
             ans = min(ans, newAns);
        }
    }
     return dp[mask][pos] = ans;
}
}

int solve()
{
     dp.assign(1 << n, vector<int>(n, -1));
    return tsp(1, 0);
}

int main()
{
    n = 4;  
    dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    cout << "The minimum cost of the TSP tour is: " << solve() << endl;

    return 0;
}
 
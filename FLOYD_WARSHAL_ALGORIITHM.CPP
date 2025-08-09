
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void shortest_ditance(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1)
                { // here -1 is like infinite ..if we can not find a value then go to 1e9.that is a big valu.
                    matrix[i][j] = INT_MAX;
                }
                if (i == j)
                    matrix[i][j] = 0;
            }
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j ++)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == INT_MAX)
                {
                    matrix[i][j] = -1;
                }
            }
        }
    }
}
};
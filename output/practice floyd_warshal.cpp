#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;  

class Solution
{
public:
    void shortest_ditance(vector<vector<int>> & adj_matrix)// use vector<vector<int>> for 2d array. 
    //use & to print the change made in ad_matrix in call function to int main() example_matrix. 
    // if we do not use it then it will compile but output is same as input matrix. use it as d-reference.
    {
        int num_rows_cols = adj_matrix.size();

        for (int i = 0; i < num_rows_cols; i++)
        {
            for (int j = 0; j < num_rows_cols; j++)
            {
                if (adj_matrix[i][j] == -1)
                {
                    adj_matrix[i][j] = INT_MAX;
                }
                if (i == j)
                {
                    adj_matrix[i][j] = 0;
                }
            }
        }

        for (int k = 0; k < num_rows_cols; k++)
        {
            for (int i = 0; i < num_rows_cols; i++)
            {
                for (int j = 0; j < num_rows_cols; j++)
                {
                    if (adj_matrix[i][k] != INT_MAX && adj_matrix[k][j] != INT_MAX)
                    {
                        adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k] + adj_matrix[k][j]);
                    }
                }
            }
        }

        for (int i = 0; i < num_rows_cols; i++)
        {
            for (int j = 0; j < num_rows_cols; j++)
            {
                if (adj_matrix[i][j] == INT_MAX)
                {
                    adj_matrix[i][j] = -1;
                }
            }
        }
    }
};

int main()
{
    Solution solver;

    vector<vector<int>> example_matrix = {
        {0, 3, INT_MAX},
        {INT_MAX, 0, 1},
        {INT_MAX, INT_MAX, 0}
    };
    int n_dims = example_matrix.size();

    cout << "Original Matrix:\n";
    for (int i = 0; i < n_dims; ++i) {
        for (int j = 0; j < n_dims; ++j) {
            cout << example_matrix[i][j] << "\t";
        }
        cout << "\n";
    }

    solver.shortest_ditance(example_matrix);

    cout << "\nShortest Distances Matrix:\n";
    for (int i = 0; i < n_dims; ++i) {
        for (int j = 0; j < n_dims; ++j) {
            cout << example_matrix[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}
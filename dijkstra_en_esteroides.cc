#include <iostream>
#include <vector>
#include <limits>
#include <climits>

using namespace std;

class Graph
{
private:
    vector<vector<long long>> adj_matrix;
    const long long INF = LLONG_MAX; 

public:
    Graph(int n) : adj_matrix(n, vector<long long>(n, INF))
    {
        for (int i = 0; i < n; ++i)
            adj_matrix[i][i] = 0;
    }

    void add_edge(int u, int v, long long weight)
    {
        if (u == v)
            return;
        adj_matrix[u][v] = weight;
    }

    void print_matrix(const vector<vector<long long>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] >= 140227235527248)
                    cout << ". ";
                else
                    cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void print_adj_matrix()
    {
        cout << "Matriz de adyacencia (pesos):\n";
        print_matrix(adj_matrix);
    }

    vector<vector<long long>> min_plus_multiply(const vector<vector<long long>> &A, const vector<vector<long long>> &B)
    {
        int n = A.size();
        vector<vector<long long>> C(n, vector<long long>(n, INF));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                for (int k = 0; k < n; ++k)
                {
                    if (A[i][k] != INF && B[k][j] != INF)
                    {
                        long long sum = A[i][k] + B[k][j];
                        if (sum < C[i][j])
                            C[i][j] = sum;
                    }
                }
            }
        }
        return C;
    }

    void shortest_paths()
    {
        int n = adj_matrix.size();
        vector<vector<long long>> result = adj_matrix;

        for (int i = 1; i < n; ++i)
        {
            result = min_plus_multiply(result, adj_matrix);
        }

        cout << "\nMatriz de costos de caminos más cortos (min.+):\n";
        print_matrix(result);
    }
};

int main()
{
    Graph g(4);
    g.add_edge(0, 1, 2);
    g.add_edge(1, 2, 3);
    g.add_edge(0, 3, 10);
    g.add_edge(3, 2, 1);

    g.print_adj_matrix();
    g.shortest_paths();

    return 0;
}

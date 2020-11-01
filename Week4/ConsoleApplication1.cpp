#include <iostream>
#include <vector>

using namespace std;

int n, m;
long int inf = 99999;
vector <int> dist;

int negative_cycle(vector<vector<int> >& adj, vector<vector<int> >& cost) {

    for (int q = 0; q < n; q++)
    {
        for (int u = 0; u < n; u++)
        {
            for (int k = 0; k < adj[u].size(); k++)
            {
                if (dist[adj[u][k]] > dist[u] + cost[u][k])
                {
                    dist[adj[u][k]] = dist[u] + cost[u][k];
                    if (q == n - 1)
                        return 1;
                }
            }
        }
    }
    return 0;
}

int main() {

    cin >> n >> m;

    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > cost(n, vector<int>());

    dist.assign(n, inf);
    dist[0] = 0;

    for (int i = 0; i < m; i++) 
    {
        int x, y, w;
        cin >> x >> y >> w;

        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }

    cout << negative_cycle(adj, cost);
    return 0;
}

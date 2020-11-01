#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector <int> dist;
queue <int> que;
long double inf;

int distanc(vector<vector<int> >& adj, vector<vector<int> >& cost, int start, int ende) {

    while (!que.empty())
    {
        int u = que.front();
        que.pop();

        for (int i = 0; i < adj[u].size(); i++)
        {
            if (dist[adj[u][i]] > (dist[u] + cost[u][i]))
            {
                que.push(adj[u][i]);
                dist[adj[u][i]] = dist[u] + cost[u][i];
            }
        }
    }

    return 0; 
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > cost(n, vector<int>());

    for (int i = 0; i < m; i++) 
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }

    inf = pow(10, 9)+m;
    dist.assign(n, inf);

    int start, ende;
    cin >> start >> ende;
    start--, ende--;

    dist[start] = 0;
    que.push(start);

    if (start == ende)
    {
        cout << dist[start];
        return 0;
    }

    distanc(adj, cost, start, ende);

    if (dist[ende] != inf)
    {
        cout << dist[ende];
    }

    else
        cout << -1;
}

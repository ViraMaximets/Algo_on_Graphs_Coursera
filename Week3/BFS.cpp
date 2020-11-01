#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using std::vector;
using std::queue;

vector <int> dist;
queue <int> que;
int inf, start, ende;

int distance(int currDist, vector<vector<int> >& adj, int start, int ende) {

    if (start == ende)
        return 0;

    dist[start] = 0;
    que.push(start);

    while (!que.empty())
    {
        int u = que.front();
        que.pop();


        for (int i = 0; i < adj[u].size(); i++)
        {
            if (dist[adj[u][i]] == inf)
            {
                que.push(adj[u][i]);
                dist[adj[u][i]] = dist[u] + 1;

            }
        }


    }

    if (dist[ende] != inf)
    {
        return dist[ende];
    }

    return -1;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    inf = n + n;
    dist.resize(n, inf);


    vector<vector<int> > adj(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }


    cin >> start >> ende;
    start--, ende--;

    int currDist = 0;

    cout << distance(currDist, adj, start, ende);

    return 0;
}


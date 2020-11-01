#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> color;
queue <int> que;
int cases;

int bipartite(vector<vector<int> >& adj, int start, int pred) {

    //white = 1, black = 2
    while (!que.empty())
    {
        int u = que.front();
        que.pop();

        for (int i = 0; i < adj[u].size(); i++)
        {
            if (color[u] == 1)
                cases = 1;
            else
                cases = 2;
            
            
            if (color[adj[u][i]] == 0)
            {
                que.push(adj[u][i]);

                if (cases == 1)
                {
                    color[adj[u][i]] = 2;
                }
                else if (cases == 2)
                {
                    color[adj[u][i]] = 1;
                }
            }

            else if (adj[u][i] != pred)
            {
                if ((cases == 1)&&(color[adj[u][i]] == 1))
                {
                    return 0;
                }
                if ((cases == 2) && (color[adj[u][i]] == 2))
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int main() {
    int n, m;
    cin >> n >> m;

    color.assign(n, 0);

    vector<vector<int> > adj(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }

    color[0] = 1;
    que.push(0);

    cout << bipartite(adj, 0, -1);
}

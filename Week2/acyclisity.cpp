#include <iostream>
#include <vector>
using namespace std;

vector <int> visit;
bool cycle = false;

int acyclic(vector<vector<int> >& adj, int st, int sourse) {
    
    visit[st] = 1;
    for (int j = 0; j < adj[st].size(); j++)
    {
        if (visit[adj[st][j]] == 0) //сусід не відвіданий
            acyclic(adj, adj[st][j], sourse);
        else if (adj[st][j] == sourse)
        {
            cycle = true;
        }
    }
    return 0;
}

int main() {
    size_t n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    visit.resize(n, 0);

    for (size_t i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }

    for (int i = 0; i < adj.size(); i++)
    {
        if (visit[i]==0)
            acyclic(adj, i, i);
    }
    if (cycle==true)
        cout << 1;
    else if (cycle == false)
        cout << 0;

 return 0;
}

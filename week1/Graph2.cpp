#include <iostream>
#include <vector>

using namespace std;
using std::vector;
using std::pair;

int reach(vector<vector<int> >& adj, int start, int n, int visit[]) {

    visit[start] = 1;
    for (int i = 0; i < adj[start].size(); i++)
    {
        if (visit[adj[start][i]] == 0)
        {
            reach(adj, adj[start][i], n, visit);
        }
    }
    return 0;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;

    int* visit = new int[n];
    for (int i = 0; i < n; i++)
    {
        visit[i] = 0;
    }

    vector<vector<int> > adj(n, vector<int>());
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        
        if (visit[i] == 0)
        {
            count++;
            reach(adj, i, n, visit);
        }
    }
    cout << count;
}
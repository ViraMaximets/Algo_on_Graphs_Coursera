#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
using std::vector;
using std::pair;
stack <int> rvrsStack;

int posible;

void dfs(int v, int visit[], vector<vector<int> > adj)
{
    visit[v] = 1;
    for (int j = 0; j < adj[v].size(); j++)
    {
        if (visit[adj[v][j]] == 0)
            dfs(adj[v][j], visit, adj);
    }
    if (posible >= 0)
    {
        rvrsStack.push(v);
        posible--;
    }
}

int main() {
    size_t n, m;
    cin >> n >> m;

    posible = n;

    int* nrmlVisit = new int[n];
    int* RvrsVisit = new int[n];
    for (int i = 0; i < n; i++)
    {
        RvrsVisit[i] = 0;
        nrmlVisit[i] = 0;
    }
    vector<vector<int> > nrmlAdj(n, vector<int>());
    vector<vector<int> > RvrsAdj(n, vector<int>());

    for (size_t i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        nrmlAdj[x - 1].push_back(y - 1);
        RvrsAdj[y - 1].push_back(x - 1);
    }

    for (int i = 0; i < n; i++)
    {
        if (RvrsVisit[i] == 0)
        {  
            dfs(i, RvrsVisit, RvrsAdj);
        }
    }
    int count = 0;

    while (!rvrsStack.empty())
    {
        int x = rvrsStack.top();
        if (nrmlVisit[x] == 0)
        {
            count++;
            dfs(x, nrmlVisit, nrmlAdj);
        }
        rvrsStack.pop();
    }
    cout << count;
}

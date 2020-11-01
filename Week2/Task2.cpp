#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
using std::vector;
using std::pair;
vector <int> color;
stack<int> order;

void toposort(vector<vector<int> >& adj, int v) {
    color[v] = 1;
    bool sink = true;

    for (int i = 0; i < adj[v].size(); i++)
    {
        if (color[adj[v][i]] == 0)
        {
            toposort(adj,adj[v][i]);
        }

        else if ((adj[v].size() == 0) && (color[v]!=2))//is a sink
        {
            order.push(v);
            color[v] = 2; //видалили
        }

        if (color[adj[v][i]] != 2)
            sink = false;
    }

    if (sink == true)
    {
        order.push(v);
        color[v] = 2; //видалили
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    color.resize(n, 0);

    int x, y;
    vector<vector<int> > adj(n, vector<int>());
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);  
    }

    for (int i = 0; i < n; i++)
    {
        if (color[i] == 0)
            toposort(adj, i);
    }
    
    for (int i = 0; i < n; i++) {
        cout << 1+order.top() << " ";
        order.pop();
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

constexpr int N = 100000;
constexpr int M = 200000;

struct Edge {
    int v, nxt;
};

Edge E[M];
int eIdx = 0;
int adj[N];
uint8_t vis[N];

int q[N], front, back;

void addEdge(int u, int v) {
    E[eIdx] = {v, adj[u]};
    adj[u] = eIdx++;
}

void bfs(int k) {
    front = back = 0;
    q[back++] = k;
    vis[k] = 1;

    while (front < back) {
        int u = q[front++];

        for (int idx = adj[u]; idx != -1; idx = E[idx].nxt) {
            int v = E[idx].v;

            if (vis[v])
                continue;

            vis[v] = 1;
            q[back++] = v;
        }
    }
}

vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
    eIdx = 0;

    memset(adj, -1, n * sizeof(int));
    memset(vis, 0, n);

    for (auto &e : invocations) {
        addEdge(e[0], e[1]);
    }

    bfs(k);

    bool connected = false;

    for (auto &e : invocations) {
        int u = e[0];
        int v = e[1];

        if (!vis[u] && vis[v]) {
            connected = true;
            break;
        }
    }

    vector<int> ans;

    if (connected) {
        ans.resize(n);
        iota(ans.begin(), ans.end(), 0);
        return ans;
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i])
            ans.push_back(i);
    }

    return ans;
}

int main() {
    int n, k, m;

    cout << "Enter number of methods: ";
    cin >> n;

    cout << "Enter suspicious method (k): ";
    cin >> k;

    cout << "Enter number of invocations: ";
    cin >> m;

    vector<vector<int>> invocations(m, vector<int>(2));

    cout << "Enter each invocation (u v):\n";
    for (int i = 0; i < m; i++) {
        cin >> invocations[i][0] >> invocations[i][1];
    }

    vector<int> result = remainingMethods(n, k, invocations);

    cout << "Remaining Methods: ";
    for (int x : result)
        cout << x << " ";

    cout << endl;

    return 0;
}
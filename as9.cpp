#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    int w;
};

struct Graph {
    int n; // number of vertices (0..n-1)
    bool directed;
    vector<vector<pair<int,int>>> adj; // (neighbor, weight)
    vector<Edge> edges; // for Kruskal

    Graph(int n, bool directed=false) : n(n), directed(directed) {
        adj.assign(n, {});
    }

    void addEdge(int u, int v, int w=1) {
        adj[u].push_back({v,w});
        edges.push_back({u,v,w});
        if (!directed) {
            adj[v].push_back({u,w});
            // For undirected graph, store both directions in edges for clarity in Kruskal
            edges.push_back({v,u,w});
        }
    }
};

vector<int> bfs(const Graph& g, int src) {
    vector<int> order;
    vector<int> dist(g.n, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (auto [v,w] : g.adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return order;
}

void dfsUtil(const Graph& g, int u, vector<int>& visited, vector<int>& order) {
    visited[u] = 1;
    order.push_back(u);
    for (auto [v,w] : g.adj[u]) {
        if (!visited[v]) dfsUtil(g, v, visited, order);
    }
}

vector<int> dfs(const Graph& g, int src) {
    vector<int> order;
    vector<int> visited(g.n, 0);
    dfsUtil(g, src, visited, order);
    return order;
}

// Disjoint Set Union (Union-Find) for Kruskal
struct DSU {
    vector<int> p, r;
    DSU(int n=0){init(n);}    
    void init(int n){p.resize(n); r.assign(n,0); iota(p.begin(), p.end(), 0);}    
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a, int b){ a=find(a); b=find(b); if(a==b) return false; if(r[a]<r[b]) swap(a,b); p[b]=a; if(r[a]==r[b]) r[a]++; return true; }
};

pair<int, vector<Edge>> kruskalMST(int n, const vector<Edge>& edges) {
    vector<Edge> undirectedEdges;
    undirectedEdges.reserve(edges.size());
    // To avoid double counting for undirected graphs where both directions are stored
    for (auto e : edges) {
        if (e.u < e.v) undirectedEdges.push_back(e);
        else if (e.u > e.v) undirectedEdges.push_back({e.v, e.u, e.w});
        else undirectedEdges.push_back(e);
    }
    // Remove duplicates (u,v) pairs keeping minimal w
    sort(undirectedEdges.begin(), undirectedEdges.end(), [](const Edge& a, const Edge& b){
        if (a.u!=b.u) return a.u<b.u; if (a.v!=b.v) return a.v<b.v; return a.w<b.w; });
    vector<Edge> uniq;
    for (auto e : undirectedEdges) {
        if (uniq.empty() || uniq.back().u!=e.u || uniq.back().v!=e.v) uniq.push_back(e);
    }
    sort(uniq.begin(), uniq.end(), [](const Edge& a, const Edge& b){ return a.w < b.w; });

    DSU dsu(n);
    int total = 0;
    vector<Edge> mst;
    for (auto e : uniq) {
        if (dsu.unite(e.u, e.v)) { total += e.w; mst.push_back(e); }
        if ((int)mst.size() == n-1) break;
    }
    return {total, mst};
}

pair<int, vector<Edge>> primMST(const Graph& g, int start=0) {
    int n = g.n;
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<int> inMST(n, 0);
    key[start] = 0;

    // Min-heap of (key, vertex)
    using P = pair<int,int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [k,u] = pq.top(); pq.pop();
        if (inMST[u]) continue;
        inMST[u] = 1;
        for (auto [v,w] : g.adj[u]) {
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    int total = 0;
    vector<Edge> mst;
    for (int v = 0; v < n; ++v) {
        if (v != start && parent[v] != -1) {
            mst.push_back({parent[v], v, key[v]});
            total += key[v];
        }
    }
    return {total, mst};
}

vector<int> dijkstra(const Graph& g, int src) {
    vector<int> dist(g.n, INT_MAX);
    dist[src] = 0;
    using P = pair<int,int>; // (dist, vertex)
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto [v,w] : g.adj[u]) {
            if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

void printVector(const vector<int>& v) {
    for (size_t i=0;i<v.size();++i) {
        cout << v[i];
        if (i+1<v.size()) cout << " ";
    }
    cout << "\n";
}

void printEdges(const vector<Edge>& es) {
    for (auto e : es) {
        cout << e.u << " - " << e.v << " (w=" << e.w << ")\n";
    }
}

// Simple CLI for demonstration
// Input format:
// n m directed
// next m lines: u v w
// then a series of commands:
// BFS s
// DFS s
// KRUSKAL
// PRIM s
// DIJKSTRA s
// EXIT
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; int directedFlag;
    if (!(cin >> n >> m >> directedFlag)) {
        cerr << "Invalid input. Expected: n m directedFlag" << '\n';
        return 1;
    }
    Graph g(n, directedFlag!=0);
    for (int i=0;i<m;++i) {
        int u,v,w; cin >> u >> v >> w;
        if (u<0||u>=n||v<0||v>=n) { cerr << "Vertex out of range" << '\n'; return 1; }
        g.addEdge(u,v,w);
    }

    string cmd;
    while (cin >> cmd) {
        if (cmd == "BFS") {
            int s; cin >> s; auto order = bfs(g, s); cout << "BFS: "; printVector(order);
        } else if (cmd == "DFS") {
            int s; cin >> s; auto order = dfs(g, s); cout << "DFS: "; printVector(order);
        } else if (cmd == "KRUSKAL") {
            if (g.directed) { cout << "Kruskal requires undirected graph" << '\n'; continue; }
            auto [total, mst] = kruskalMST(g.n, g.edges);
            cout << "MST (Kruskal) cost: " << total << '\n';
            printEdges(mst);
        } else if (cmd == "PRIM") {
            if (g.directed) { cout << "Prim requires undirected graph" << '\n'; continue; }
            int s; cin >> s; auto [total, mst] = primMST(g, s);
            cout << "MST (Prim) cost: " << total << '\n';
            printEdges(mst);
        } else if (cmd == "DIJKSTRA") {
            int s; cin >> s; auto dist = dijkstra(g, s); cout << "Dijkstra: "; printVector(dist);
        } else if (cmd == "EXIT") {
            break;
        } else {
            cout << "Unknown command" << '\n';
        }
    }

    return 0;
}

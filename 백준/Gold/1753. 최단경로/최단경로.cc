#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  long long weight;
  Edge(int t, int w) : to(t), weight(w) {}

  bool operator<(const Edge& o) const { return this->weight > o.weight; }
};

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int V, E, K;
  cin >> V >> E >> K;
  vector<vector<Edge>> edge(V + 1);
  for (int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edge[u].emplace_back(v, w);
  }
  vector<long long> minDis(V + 1, LONG_MAX);
  vector<bool> visited(V + 1, false);
  priority_queue<Edge> pq;
  minDis[K] = 0;
  pq.emplace(K, 0);
  while (!pq.empty()) {
    Edge cur = pq.top();
    pq.pop();
    if (visited[cur.to]) continue;
    visited[cur.to] = true;

    for (const auto& next : edge[cur.to]) {
      if (!visited[next.to]) {
        minDis[next.to] = min(minDis[next.to], minDis[cur.to] + next.weight);
        pq.emplace(next.to, minDis[next.to]);
      }
    }
  }
  for (int i = 1; i <= V; i++) {
    if (minDis[i] == LONG_MAX)
      cout << "INF\n";
    else
      cout << minDis[i] << "\n";
  }
}
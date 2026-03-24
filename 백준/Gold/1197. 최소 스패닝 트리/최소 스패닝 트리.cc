#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to, weight;
  Edge(int t, int w) : to(t), weight(w) {}

  bool operator<(const Edge& o) const { return this->weight > o.weight; }
};

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int v, e;
  cin >> v >> e;
  vector<vector<Edge>> edge(v + 1);
  for (int i = 0; i < e; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edge[a].emplace_back(b, c);
    edge[b].emplace_back(a, c);
  }
  vector<bool> visited(v, false);
  priority_queue<Edge> pq;
  pq.emplace(1, 0);
  int cnt = -1;
  long long total = 0;
  while (!pq.empty()) {
    if (cnt == v - 1) break;
    Edge cur = pq.top();  // 가중치가 가장 작은 간선 선택.
    int next = pq.top().to;
    pq.pop();
    if (visited[next]) continue;  // 이미 방문한 정점이면 패스.
    visited[next] = true;
    cnt++;
    total += cur.weight;
    for (int i = 0; i < edge[next].size();
         i++) {  // 연결 가능한 간선 후보 추가.
      pq.emplace(edge[next][i].to, edge[next][i].weight);
    }
  }
  cout << total;
}
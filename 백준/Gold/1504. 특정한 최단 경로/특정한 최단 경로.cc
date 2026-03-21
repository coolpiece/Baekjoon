#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  long long weight;
  Edge(int t, long long w) : to(t), weight(w) {}

  bool operator<(const Edge& o) const { return this->weight > o.weight; }
};

int n;
vector<vector<Edge>> edge;

vector<long long> dijkstra(int start) {
  vector<long long> minDis(n + 1, INT_MAX);
  vector<bool> visited(n + 1, false);
  priority_queue<Edge> pq;

  minDis[start] = 0;
  pq.emplace(start, 0);
  while (!pq.empty()) {
    Edge cur = pq.top();
    pq.pop();
    if (visited[cur.to]) continue;
    visited[cur.to] = true;

    for (const auto& next : edge[cur.to]) {
      if (visited[next.to])
        continue;  // 이미 방문하여 최단 경로 계산 완료된 정점.
      if (minDis[next.to] > minDis[cur.to] + next.weight) {  // 거쳐가는 것이 더 짧으면 갱신.
        minDis[next.to] = minDis[cur.to] + next.weight;  // 거쳐가는 것이 더 짧으면 갱신.
        pq.emplace(next.to, minDis[next.to]);
      }
    }
  }
  return minDis;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int e;
  cin >> n >> e;
  edge.resize(n + 1);
  for (int i = 0; i < e; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edge[a].emplace_back(b, c);
    edge[b].emplace_back(a, c);
  }
  int v1, v2;
  cin >> v1 >> v2;
  // Start -> v1 -> v2 -> End || Start -> v2 -> v1 -> End.
  // 양방향 그래프이므로 다익스트라 3번으로 해결. (Start, v1, End)에서 시작.

  // v1에서 출발.
  vector<long long> minDisfromM = dijkstra(v1);
  // v1, v2 사이가 연결되어 있지 않으면 경로 없음. 종료.
  if (minDisfromM[v2] == INT_MAX) {
    cout << -1;
    return 0;
  }

  // 1에서 출발.
  vector<long long> minDisfromS = dijkstra(1);

  // n에서 출발.
  vector<long long> minDisfromE = dijkstra(n);

  long long minVal = INT_MAX;
  // Start -> v1 -> v2 -> End.
  if (minDisfromS[v1] != INT_MAX && minDisfromE[v2] != INT_MAX)
    minVal = minDisfromS[v1] + minDisfromM[v2] + minDisfromE[v2];

  // Start -> v2 -> v1 -> End.
  if (minDisfromS[v2] != INT_MAX && minDisfromE[v1] != INT_MAX)
    minVal = min(minVal, minDisfromS[v2] + minDisfromM[v2] + minDisfromE[v1]);

  if (minVal >= INT_MAX)
    cout << -1;
  else
    cout << minVal;
}
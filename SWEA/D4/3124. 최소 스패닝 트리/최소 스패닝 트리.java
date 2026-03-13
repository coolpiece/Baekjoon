import java.io.*;
import java.util.*;

class Edge implements Comparable<Edge> {
	int idx;
	long weight;

	Edge(int idx, long weight) {
		this.idx = idx;
		this.weight = weight;
	}

	@Override
	public int compareTo(Edge o) {
		return Long.compare(this.weight, o.weight);
	}
}

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder rst = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			int v = Integer.parseInt(st.nextToken()), e = Integer.parseInt(st.nextToken());

			List<Edge> adjList[] = new ArrayList[v + 1]; // 인접 리스트에 간선 정보 저장.
			for (int i = 1; i <= v; i++)
				adjList[i] = new ArrayList<>();

			for (int i = 0; i < e; i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken()),
						c = Integer.parseInt(st.nextToken());
				adjList[a].add(new Edge(b, c));
				adjList[b].add(new Edge(a, c));
			}

			boolean visited[] = new boolean[v + 1]; // 선택 여부.
			long minDis[] = new long[v + 1]; //
			Arrays.fill(minDis, Integer.MAX_VALUE);
			PriorityQueue<Edge> pq = new PriorityQueue<>();

			long sum = 0; // 가중치의 합.
			minDis[1] = 0;
			pq.add(new Edge(1, 0)); // 시작점.

			while (!pq.isEmpty()) {
				Edge cur = pq.poll();
				int idx = cur.idx;
				long weight = cur.weight;
				if (visited[idx])
					continue;
				visited[idx] = true;
				sum += weight;

				for (Edge next : adjList[idx]) { // 선택한 정점의 간선 모두 pq에 추가.
					if (!visited[next.idx] && next.weight < minDis[next.idx]) {
						minDis[next.idx] = next.weight;
						pq.add(new Edge(next.idx, next.weight));
					}
				}
			}
			rst.append("#").append(t).append(" ").append(sum).append("\n");
		}
		System.out.println(rst);
	}
}
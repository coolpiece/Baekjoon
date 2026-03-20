import java.io.*;
import java.util.*;

class Edge implements Comparable<Edge> {
	int to;
	long weight;

	Edge(int to, long weight) {
		this.to = to;
		this.weight = weight;
	}

	@Override
	public int compareTo(Edge o) {
		return Long.compare(this.weight, o.weight);
	}
}

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(br.readLine());
		int V = Integer.parseInt(st.nextToken()), E = Integer.parseInt(st.nextToken()),
				K = Integer.parseInt(br.readLine());

		ArrayList<Edge> edge[] = new ArrayList[V + 1];
		for (int i = 0; i <= V; i++)
			edge[i] = new ArrayList<>();

		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken()), v = Integer.parseInt(st.nextToken()),
					w = Integer.parseInt(st.nextToken());
			edge[u].add(new Edge(v, w));
		}

		long minDis[] = new long[V + 1];
		boolean visited[] = new boolean[V + 1];
		Arrays.fill(minDis, Long.MAX_VALUE);
		Arrays.fill(visited, false);
		PriorityQueue<Edge> pq = new PriorityQueue<>(); // next, dis 저장.

		minDis[K] = 0;
		pq.add(new Edge(K, 0));
		while (!pq.isEmpty()) {
			Edge cur = pq.poll();

			if (visited[cur.to])
				continue; // pass.
			visited[cur.to] = true;

			for (Edge next : edge[cur.to]) { // 다음 정점 추가, 거리 갱신.
				if (!visited[next.to]) {
					minDis[next.to] = Math.min(minDis[next.to], minDis[cur.to] + next.weight);
					pq.add(new Edge(next.to, minDis[next.to]));
				}
			}
		}
		for (int i = 1; i <= V; i++) {
			if (minDis[i] == Long.MAX_VALUE)
				System.out.println("INF");
			else
				System.out.println(minDis[i]);
		}
	}
}
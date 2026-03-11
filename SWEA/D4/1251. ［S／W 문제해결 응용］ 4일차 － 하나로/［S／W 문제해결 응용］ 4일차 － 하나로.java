import java.io.*;
import java.util.*;

class Edge implements Comparable<Edge> {
	int start, end;
	double c;

	Edge(int start, int end, double c) {
		this.start = start;
		this.end = end;
		this.c = c;
	}

	@Override
	public int compareTo(Edge o) {
		return Double.compare(this.c, o.c);
	}

}

public class Solution {
	static int rank[], parent[];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder rst = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			int n = Integer.parseInt(br.readLine());
			int x[] = new int[n + 1], y[] = new int[n + 1];
			rank = new int[n + 1];
			parent = new int[n + 1];
			st = new StringTokenizer(br.readLine());
			for (int i = 1; i <= n; i++)
				x[i] = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for (int i = 1; i <= n; i++)
				y[i] = Integer.parseInt(st.nextToken());
			double e = Double.parseDouble(br.readLine());

			List<Edge> list = new ArrayList<>();
			for (int i = 1; i < n; i++) {
				for (int j = i; j <= n; j++) {
					double c = (Math.pow((x[i] - x[j]), 2) + Math.pow((y[i] - y[j]), 2)) * e;
					list.add(new Edge(i, j, c));
				}
			}
			list.sort(null);

			for (int i = 1; i <= n; i++) // 초기 집합 만들기.
				parent[i] = i;

			int picked = 0;
			double cost = 0;
			for (Edge edge : list) {
				if (picked == n - 1)
					break;
				if (findSet(edge.start) != findSet(edge.end)) { // 대표자가 같으면 사이클 발생.
					union(edge.start, edge.end); // 연결하기.
					cost += edge.c;
					picked++;
				}
			}
			rst.append("#").append(t).append(" ").append(Math.round(cost)).append("\n");
		}
		System.out.println(rst);
	}

	static int findSet(int a) {
		if (a == parent[a])
			return a;
		else
			return parent[a] = findSet(parent[a]);
	}

	static boolean union(int a, int b) {
		int pa = findSet(a), pb = findSet(b);
		if (pa == pb)
			return false;
		if (rank[pa] > rank[pb]) {
			parent[pb] = pa;
		} else
			parent[pa] = pb;
		return true;
	}
}
import java.io.*;
import java.util.*;

class Node {
	int r, c;

	Node(int r, int c) {
		this.r = r;
		this.c = c;
	}
}

public class Solution {
	static int n, minDis;
	static List<Node> list;
	static boolean visited[];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder rst = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			n = Integer.parseInt(br.readLine());
			list = new ArrayList<>(); // 고객들의 좌표 저장.
			visited = new boolean[n + 1];
			minDis = Integer.MAX_VALUE;

			st = new StringTokenizer(br.readLine());
			Node company = new Node(-1, -1);
			Node home = new Node(-1, -1);
			company.r = Integer.parseInt(st.nextToken());
			company.c = Integer.parseInt(st.nextToken());
			home.r = Integer.parseInt(st.nextToken());
			home.c = Integer.parseInt(st.nextToken());
			list.add(new Node(company.r, company.c));
			visited[0] = true;
			for (int i = 0; i < n; i++) {
				int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());
				list.add(new Node(x, y));
			}
			list.add(new Node(home.r, home.c));

			dfs(0, 0, 0);
			rst.append("#").append(t).append(" ").append(minDis).append("\n");
		}
		System.out.println(rst);
	}

	static int calDis(Node a, Node b) {
		return Math.abs(a.r - b.r) + Math.abs(a.c - b.c);
	}

	static void dfs(int cur, int dis, int cnt) {
		if (cnt == n) {
			dis += calDis(list.get(cur), list.get(n + 1));
			minDis = Math.min(minDis, dis);
			return;
		}

		if (dis >= minDis)
			return;

		for (int next = 1; next <= n; next++) {
			if (!visited[next]) {
				visited[next] = true;
				dfs(next, dis + calDis(list.get(cur), list.get(next)), cnt + 1);
				visited[next] = false;
			}
		}
	}
}
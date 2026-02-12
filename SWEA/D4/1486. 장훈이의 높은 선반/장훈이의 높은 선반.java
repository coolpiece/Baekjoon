import java.io.*;
import java.util.*;

public class Solution {
	private static int n, b, ans, len[];
	private static boolean[] visited;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder rst = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			ans = Integer.MAX_VALUE;
			len = new int[n];
			visited = new boolean[n];
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				len[i] = Integer.parseInt(st.nextToken());
				if (len[i] - b >= 0)
					ans = Math.min(ans, len[i] - b);
			}
			for (int i = 2; i <= n; i++)
				combination(0, 0, i, 0);
			rst.append("#").append(t).append(" ").append(ans).append("\n");
		}
		System.out.println(rst);
	}

	static void combination(int start, int cnt, int pick, int sum) {
		if (cnt == pick) {
			if (sum - b >= 0)
				ans = Math.min(ans, sum - b);
			return;
		}
		for (int i = start; i < n; i++) {
			visited[i] = true;
			combination(i + 1, cnt + 1, pick, sum + len[i]);
			visited[i] = false;
		}
	}
}
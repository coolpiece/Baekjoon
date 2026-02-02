import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder rst = new StringBuilder();
		StringTokenizer st;

		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
			int[][] map = new int[n][n];
			for (int i = 0; i < n; i++) { // 입력 값 map에 저장.
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < n; j++)
					map[i][j] = Integer.parseInt(st.nextToken());
			}
			int[][] sum = new int[n + 1][n + 1];
			for (int i = 1; i <= n; i++) // (1, 1)~(i, j)의 누적합 계산.
				for (int j = 1; j <= n; j++)
					sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + map[i - 1][j - 1] - sum[i - 1][j - 1];
			int val = 0;

			for (int i = m; i <= n; i++) // m*m 크기에 맞게 재계산.
				for (int j = m; j <= n; j++)
					val = Math.max(val, sum[i][j] - sum[i - m][j] - sum[i][j - m] + sum[i - m][j - m]);
			rst.append("#").append(t).append(" ").append(val).append("\n");
		}
		System.out.println(rst);
	}
}
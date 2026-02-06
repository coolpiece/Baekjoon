// dp로 해결.
import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder rst = new StringBuilder(100);
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken()), limit = Integer.parseInt(st.nextToken());
			int[][] dp = new int[n + 1][limit + 1]; // dp[재료 번호][최대 칼로리]
			for (int i = 1; i <= n; i++) {
				st = new StringTokenizer(br.readLine());
				int score = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
				for (int j = 1; j <= limit; j++) {
					if (j >= k)
						dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - k] + score);
					else
						dp[i][j] = dp[i - 1][j];
				}
			}
			rst.append("#").append(t).append(" ").append(dp[n][limit]).append("\n");
		}
		System.out.println(rst);
	}
}

/*
// 조합으로 해결.
import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder rst = new StringBuilder(100);
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken()), limit = Integer.parseInt(st.nextToken()), maxVal = 0;
			List<int[]> list = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				int score = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
				list.add(new int[] { score, k });
			}
			for (int i = 0; i < (1 << n); i++) {
				int totalScore = 0, totalKcal = 0;
				for (int j = 0; j < n; j++) {
					if ((i & (1 << j)) != 0) {
						totalScore += list.get(j)[0];
						totalKcal += list.get(j)[1];
					}
					if (totalKcal > limit) {
						totalScore = 0;
						break;
					}
				}
				maxVal = Math.max(maxVal, totalScore);
			}
			rst.append("#").append(t).append(" ").append(maxVal).append("\n");
		}
		System.out.println(rst);
	}
}
*/

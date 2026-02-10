import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder rst = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			int[] price = new int[4];
			for (int i = 0; i < 4; i++)
				price[i] = Integer.parseInt(st.nextToken());
			int[] plan = new int[13];
			int dp[] = new int[13];
			st = new StringTokenizer(br.readLine());
			for (int i = 1; i <= 12; i++) {
				plan[i] = Integer.parseInt(st.nextToken());
				plan[i] = Math.min(plan[i] * price[0], price[1]);
			}
			dp[1] = plan[1];
			dp[2] = dp[1] + plan[2];
			for (int i = 3; i <= 12; i++)
				dp[i] = Math.min(dp[i - 1] + plan[i], dp[i - 3] + price[2]);
			rst.append("#").append(t).append(" ").append(Math.min(price[3], dp[12])).append("\n");
		}
		System.out.println(rst);
	}
}
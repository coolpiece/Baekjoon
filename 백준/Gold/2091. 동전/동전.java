import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int price[] = new int[] { 1, 5, 10, 25 }; // 각 동전의 금액.
		int coinCnt[] = new int[4]; // 남아 있는 동전의 개수.
		StringTokenizer st = new StringTokenizer(br.readLine());
		int x = Integer.parseInt(st.nextToken());
		int dp[] = new int[x + 1];
		Arrays.fill(dp, -1);
		dp[0] = 0;
		int used[][] = new int[x + 1][4]; // 사용한 동전의 개수.
		for (int i = 0; i < 4; i++)
			coinCnt[i] = Integer.parseInt(st.nextToken());
		for (int i = 0; i < 4; i++) {
			int p = price[i], limit = coinCnt[i];
			for (int j = p; j <= x; j++) {
				if (dp[j - p] != -1 && used[j - p][i] < limit) {
					if (dp[j - p] + 1 >= dp[j]) {
						dp[j] = dp[j - p] + 1;
						for (int k = 0; k < 4; k++)
							used[j][k] = used[j - p][k];
						used[j][i]++;
					}
				}
			}
		}
		if (dp[x] == -1)
			System.out.println("0 0 0 0");
		else {
			for (int i = 0; i < 4; i++)
				System.out.print(used[x][i] + " ");
			System.out.println();
		}
	}
}
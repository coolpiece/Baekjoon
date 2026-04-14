import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder rst = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			rst.append("#").append(t).append(" ");
			int n = Integer.parseInt(br.readLine()), m = Integer.parseInt(br.readLine());
			int tall[][] = new int[n][n]; // tall[i][j]: i보다 j가 더 크다.
			int small[][] = new int[n][n]; // small[i][j]: i보다 j가 더 작다.
			// 자신을 제외한 모든 사람이 자신보다 큰 지, 작은 지 알면 자신의 순서 알 수 있음.

			for (int i = 0; i < n; i++) {
				Arrays.fill(tall[i], Integer.MAX_VALUE / 2);
				Arrays.fill(small[i], Integer.MAX_VALUE / 2);
			}
			for (int i = 0; i < n; i++) {
				tall[i][i] = 0;
				small[i][i] = 0;
			}
			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
				tall[a - 1][b - 1] = 1;
				small[b - 1][a - 1] = 1;
			}

			for (int k = 0; k < n; k++) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						tall[i][j] = Math.min(tall[i][k] + tall[k][j], tall[i][j]); // i < k < j.
						small[j][i] = Math.min(small[j][k] + small[k][i], small[j][i]); // j > k > i.
					}
				}
			}

//			for (int i = 0; i < n; i++) {
//				System.out.println(Arrays.toString(tall[i]));
//			}
//			System.out.println();
//			for (int i = 0; i < n; i++) {
//				System.out.println(Arrays.toString(small[i]));
//			}

			int cnt = 0; // 자신의 순서를 알 수 있는 학생 수.
			for (int i = 0; i < n; i++) {
				int tmp = 0; // i보다 큰 지, 작은 지 알 수 있는 사람 수.
				for (int j = 0; j < n; j++) {
					if (tall[i][j] != Integer.MAX_VALUE / 2 || small[i][j] != Integer.MAX_VALUE / 2)
						tmp++;
				}
				if (tmp == n)
					cnt++;
			}
			rst.append(cnt).append("\n");
		}
		System.out.println(rst);
	}
}
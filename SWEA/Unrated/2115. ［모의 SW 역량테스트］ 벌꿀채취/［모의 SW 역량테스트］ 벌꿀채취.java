import java.io.*;
import java.util.*;

public class Solution {
	static int n, m, c;
	static int[][] map; // 벌통 정보 저장.
	static int[][] maxMap; // 제곱한 합 저장.

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder rst = new StringBuilder(100);
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			map = new int[n][n];
			maxMap = new int[n][n - m + 1];
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < n; j++)
					map[i][j] = Integer.parseInt(st.nextToken());
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j <= n - m; j++) {
					subset(i, j);
				}
			}

			int maxVal = 0;
			for (int x1 = 0; x1 < n; x1++) {
				for (int y1 = 0; y1 <= n - m; y1++) {
					for (int x2 = x1; x2 < n; x2++) {
						int start = (x1 == x2) ? y1 + m : 0; // 겹치는 경우.
						for (int y2 = start; y2 <= n - m; y2++)
							maxVal = Math.max(maxVal, maxMap[x1][y1] + maxMap[x2][y2]);
					}
				}
			}
			rst.append("#").append(t).append(" ").append(maxVal).append("\n");
		}
		System.out.println(rst);
	}

	public static void subset(int x, int y) {
		for (int k = 0; k < (1 << m); k++) { // 부분 집합의 개수.
			int sum = 0, powSum = 0;
			for (int l = 0; l < m; l++) { // 원소 수만큼 비트 비교.
				if ((k & (1 << l)) != 0) { // 선택된 경우.
					sum += map[x][y + l];
					powSum += map[x][y + l] * map[x][y + l];
				}
			}
			if (sum <= c) {
				maxMap[x][y] = Math.max(maxMap[x][y], powSum);
			}
		}
	}
}
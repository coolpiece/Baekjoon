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
			int student[][] = new int[n][n]; // student[i][j]: i보다 j가 더 크다.
			// 자신을 제외한 모든 사람이 자신보다 큰 지, 작은 지 알면 자신의 순서 알 수 있음.

			for (int i = 0; i < n; i++)
				Arrays.fill(student[i], Integer.MAX_VALUE / 2);
			for (int i = 0; i < n; i++)
				student[i][i] = 0;

			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
				student[a - 1][b - 1] = 1;
			}

			for (int k = 0; k < n; k++) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						student[i][j] = Math.min(student[i][k] + student[k][j], student[i][j]); // i < k < j.
					}
				}
			}

//			for (int i = 0; i < n; i++)
//				System.out.println(Arrays.toString(student[i]));

			int cnt = 0; // 자신의 순서를 알 수 있는 학생 수.
			for (int i = 0; i < n; i++) {
				boolean flag = true;
				for (int j = 0; j < n; j++) {
					if (student[i][j] == Integer.MAX_VALUE / 2 && student[j][i] == Integer.MAX_VALUE / 2) {
						flag = false;
						break;
					}
				}
				if (flag)
					cnt++;
			}
			rst.append(cnt).append("\n");
		}
		System.out.println(rst);
	}
}
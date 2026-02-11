import java.io.*;

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder rst = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			int n = Integer.parseInt(br.readLine());
			char[][] map = new char[n][];
			for (int i = 0; i < n; i++) { // 입력 받기.
				String input = br.readLine();
				map[i] = input.toCharArray();
			}
			n /= 2;
			int total = 0;
			for (int i = 0; i <= n; i++) {
				total += map[i][n] - '0';
				for (int j = 1; j <= i; j++) {
					total += map[i][n - j] - '0';
					total += map[i][n + j] - '0';
				}
			}
			for (int i = n + 1; i <= n * 2; i++) {
				total += map[i][n] - '0';
				for (int j = 1; j <= n * 2 - i; j++) {
					total += map[i][n - j] - '0';
					total += map[i][n + j] - '0';
				}
			}
			rst.append("#").append(t).append(" ").append(total).append("\n");
		}
		System.out.println(rst);
	}
}
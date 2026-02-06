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
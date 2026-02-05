import java.io.*;
import java.util.*;

public class Solution {
	public static boolean[] picked = new boolean[19];
	static int[] iy, gy;
	static int winCnt, loseCnt;

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder rst = new StringBuilder(100);

		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			picked = new boolean[19];
			iy = new int[9];
			gy = new int[9];
			winCnt = 0;
			loseCnt = 0;
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < 9; i++) {
				int pick = Integer.parseInt(st.nextToken());
				picked[pick] = true;
				gy[i] = pick;
			}
			permutation(0);
			rst.append("#").append(t).append(" ").append(winCnt).append(" ").append(loseCnt).append("\n");
		}
		System.out.println(rst);
	}

	public static void permutation(int cnt) {
		if (cnt == 9) {
			battle();
			return;
		}
		for (int i = 1; i <= 18; i++) {
			if (picked[i])
				continue;
			iy[cnt] = i;
			picked[i] = true;
			permutation(cnt + 1);
			picked[i] = false;
		}
	}

	public static void battle() {
		int score = 0;
		for (int i = 0; i < 9; i++)
			score += (iy[i] < gy[i]) ? iy[i] + gy[i] : -(iy[i] + gy[i]);
		if (score > 0)
			winCnt++;
		else if (score < 0)
			loseCnt++;
	}
}
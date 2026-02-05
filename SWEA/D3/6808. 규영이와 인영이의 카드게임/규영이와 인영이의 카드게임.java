import java.io.*;
import java.util.*;

public class Solution {
	static int[] iy = new int[9], gy = new int[9];
	static int winCnt, loseCnt;

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder rst = new StringBuilder(100);

		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			boolean[] picked = new boolean[19];
			winCnt = 0;
			loseCnt = 0;
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < 9; i++) {
				int pick = Integer.parseInt(st.nextToken());
				picked[pick] = true;
				gy[i] = pick;
			}
			for (int i = 1, idx = 0; i <= 18; i++)
				if (!picked[i])
					iy[idx++] = i;
			permutation(0, 0, 0);
			rst.append("#").append(t).append(" ").append(winCnt).append(" ").append(loseCnt).append("\n");
		}
		System.out.println(rst);
	}

	public static void permutation(int cnt, int flag, int score) {
		if (cnt == 9) {
			if (score > 0)
				winCnt++;
			else if (score < 0)
				loseCnt++;
			return;
		}
		for (int i = 0; i < 9; i++) {
			if ((flag & (1 << i)) != 0)
				continue;
			int sum = ((iy[i] < gy[cnt]) ? 1 : -1) * (iy[i] + gy[cnt]);
			permutation(cnt + 1, flag | (1 << i), score + sum);
		}
	}
}
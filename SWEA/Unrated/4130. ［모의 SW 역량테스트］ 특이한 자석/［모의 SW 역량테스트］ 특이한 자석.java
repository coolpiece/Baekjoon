import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder rst = new StringBuilder(100);

		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			int k = Integer.parseInt(br.readLine());
			String[] magnet = new String[4];
			for (int i = 0; i < 4; i++)
				magnet[i] = br.readLine();
			int[] idx = new int[4];
			for (int i = 0; i < k; i++) {
				boolean[] turn = new boolean[5];
				for (int j = 1; j < 4; j++) { // 맞물린 부분 확인.
					if (magnet[j - 1].charAt((idx[j - 1] + 2) % 8 * 2) == magnet[j].charAt((idx[j] + 6) % 8 * 2))
						turn[j] = false;
					else
						turn[j] = true;
				}
				String tmp = br.readLine();
				int num = tmp.charAt(0) - '0' - 1;
				char dir = tmp.charAt(2);
				idx[num] = (idx[num] + ((dir == '1') ? 7 : 1)) % 8;
				int flag = (dir == '1') ? -1 : 1;
				for (int j = num + 1; j < 4; j++) { // 오른쪽.
					if (turn[j]) { // 회전하는 경우.
						idx[j] = (idx[j] + ((flag == 1) ? 7 : 1)) % 8;
						flag = (flag == 1) ? -1 : 1;
					} else // 회전 안 하는 경우.
						break;
				}
				flag = (dir == '1') ? -1 : 1;
				for (int j = num - 1; j >= 0; j--) { // 왼쪽.
					if (turn[j + 1]) { // 회전하는 경우.
						idx[j] = (idx[j] + ((flag == 1) ? 7 : 1)) % 8;
						flag = (flag == 1) ? -1 : 1;
					} else // 회전 안 하는 경우.
						break;
				}
			}
			int score = 0;
			for (int i = 0, pow = 1; i < 4; i++, pow *= 2) {
				score += (magnet[i].charAt(idx[i] * 2) == '1') ? 1 * pow : 0;
			}
			rst.append("#").append(t).append(" ").append(score).append("\n");
		}
		System.out.println(rst);
	}
}
import java.io.*;
import java.util.*;

public class Solution {
	private static boolean[] row, leftupDia, rightupDia;
	private static int n, cnt;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder rst = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			n = Integer.parseInt(br.readLine());
			cnt = 0;
			row = new boolean[n];
			leftupDia = new boolean[n * 2 - 1]; // 왼쪽 위로 가는 대각선.
			rightupDia = new boolean[n * 2 - 1]; // 오른쪽 위로 가는 대각선.
			setQueen(0);
			rst.append("#").append(t).append(" ").append(cnt).append("\n");
		}
		System.out.println(rst);
	}

	public static void setQueen(int x) {
		if (x == n) {
			cnt++;
			return;
		}
		for (int i = 0; i < n; i++) {
			if (!row[i]) {
				if (rightupDia[x + i])
					continue;
				if (leftupDia[x - i + n - 1])
					continue;
				row[i] = rightupDia[x + i] = leftupDia[x - i + n - 1] = true;
				setQueen(x + 1);
				row[i] = rightupDia[x + i] = leftupDia[x - i + n - 1] = false;
			}
		}
	}
}
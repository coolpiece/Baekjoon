import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			int n = Integer.parseInt(br.readLine()), maxHeight = 0, day = 0, cnt1 = 0, cnt2 = 0;
			st = new StringTokenizer(br.readLine());
			int[] tree = new int[102]; // 각 나무 높이 저장.
			for (int i = 0; i < n; i++) {
				tree[i] = Integer.parseInt(st.nextToken());
				maxHeight = Math.max(maxHeight, tree[i]);
			}

			for (int i = 0; i < n; i++) // 더 자라야 하는 높이 계산.
				tree[i] = maxHeight - tree[i];
			for (int i = 0; i < n; i++) {
				cnt2 += tree[i] / 2;
				if (tree[i] % 2 > 0)
					cnt1++;
			}
			day += cnt1 * 2;
			if (cnt1 > cnt2)
				day--;
			else if (cnt1 < cnt2) {
				cnt2 -= cnt1;
				day += cnt2 / 3 * 4;
				if (cnt2 % 3 == 1)
					day += 2;
				else if (cnt2 % 3 == 2)
					day += 3;
			}
			System.out.println("#" + t + " " + day);
		}
	}
}
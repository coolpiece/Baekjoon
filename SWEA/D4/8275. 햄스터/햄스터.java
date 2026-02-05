import java.io.*;
import java.util.*;

public class Solution {
	public static int n, x, maxVal;
	public static int[] cage = new int[6];
	public static int[] ans = new int[6];
	public static List<int[]> list;

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder rst = new StringBuilder(100);

		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			x = Integer.parseInt(st.nextToken());
			list = new ArrayList<>();
			int m = Integer.parseInt(st.nextToken());
			maxVal = -1;
			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(br.readLine());
				int l = Integer.parseInt(st.nextToken()), r = Integer.parseInt(st.nextToken()),
						s = Integer.parseInt(st.nextToken());
				list.add(new int[] { l, r, s });
			}
			per(0);
			rst.append("#").append(t);
			if (maxVal == -1)
				rst.append(" -1\n");
			else {
				rst.append(" ");
				for (int i = 0; i < n; i++)
					rst.append(ans[i]).append(" ");
				rst.append("\n");
			}
		}
		System.out.println(rst);
	}

	public static void per(int cnt) {
		for (int[] l : list) { // 조건에 맞는지 확인.
			if (l[1] <= cnt) { // 아직 덜 채워진 경우 패스.
				int tmp = 0;
				for (int i = l[0] - 1; i < l[1]; i++)
					tmp += cage[i];
				if (tmp != l[2])
					return; // 조건에 맞지 않으면 가지치기.
			}
		}
		if (cnt == n) {
			int sum = 0;
			for (int i = 0; i < n; i++)
				sum += cage[i];
			if (sum > maxVal) { // 햄스터가 가장 많은 경우 저장.
				ans = cage.clone();
				maxVal = sum;
			}
			return;
		}
		for (int i = 0; i <= x; i++) { // 0부터 x까지의 값 가질 수 있음.
			cage[cnt] = i;
			per(cnt + 1);
		}
	}
}
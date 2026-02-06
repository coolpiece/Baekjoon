import java.io.*;
import java.util.*;

public class Solution {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder rst = new StringBuilder(100);
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), cnt = 0;
			Set<Integer> maskSet = new HashSet<>();
			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken()) - 1, b = Integer.parseInt(st.nextToken()) - 1,
						mask = ((1 << a) | (1 << b));
				maskSet.add(mask);
			}
			x: for (int i = 0; i < (1 << n); i++) {
				for (int j : maskSet) {
					if ((i & j) == j) // 겹치는 경우.
						continue x;
				}
				cnt++;
			}
			rst.append("#").append(t).append(" ").append(cnt).append("\n");
		}
		System.out.println(rst);
	}
}
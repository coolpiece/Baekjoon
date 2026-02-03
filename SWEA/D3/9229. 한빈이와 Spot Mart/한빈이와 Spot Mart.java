import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder rst = new StringBuilder(100);
		StringTokenizer st;
		int tc = Integer.parseInt(br.readLine());
		for (int t = 1; t <= tc; t++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
			List<Integer> list = new ArrayList<>();
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++)
				list.add(Integer.parseInt(st.nextToken()));
			list.sort(null);
			int s = 0, e = n - 1, maxValue = -1;
			while (s < e) {
				int sum = list.get(s) + list.get(e);
				if (sum == m) { // 무게 제한이 최댓값이므로 더 확인할 필요 없음.
					maxValue = m;
					break;
				}
				if (sum > m)
					e--;
				else {
					maxValue = Math.max(maxValue, sum);
					s++;
				}
			}
			rst.append("#").append(t).append(" ").append(maxValue).append("\n");
		}
		System.out.println(rst);
	}
}
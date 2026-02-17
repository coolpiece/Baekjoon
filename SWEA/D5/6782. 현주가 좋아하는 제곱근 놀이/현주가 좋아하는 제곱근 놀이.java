import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder rst = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			long n = Long.parseLong(br.readLine());
			long cur = n, cnt = 0;
			while (true) {
				if (cur == 2) {
					rst.append("#").append(t).append(" ").append(cnt).append("\n");
					break;
				}
				long sq = (long) Math.sqrt(cur);
				if (Math.sqrt(cur) == sq) { // 제곱수인 경우.
					cnt++;
					cur = sq;
				} else {
					cnt += (sq + 1) * (sq + 1) - cur;
					cur = (sq + 1) * (sq + 1);
				}
			}
		}
		System.out.println(rst);
	}
}
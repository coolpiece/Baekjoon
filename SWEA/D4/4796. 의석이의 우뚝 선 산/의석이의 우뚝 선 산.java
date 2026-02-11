import java.util.*;

public class Solution {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		StringBuilder rst = new StringBuilder();
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			int n = sc.nextInt();
			int[] list = new int[n];
			for (int i = 0; i < n; i++)
				list[i] = sc.nextInt();
			int upLen = 0, downLen = 0, cnt = 0;
			for (int i = 1; i < n; i++) {
				if (list[i - 1] < list[i]) {
					if (downLen == 0) // 올라가는 중.
						upLen++;
					else { // 다시 올라갈 때.
						cnt += upLen * downLen;
						upLen = 1;
						downLen = 0;
					}
				} else if (upLen > 0) { // 올라가다가 내려갈 때.
					downLen++;
				}
			}
			cnt += upLen * downLen;
			rst.append("#").append(t).append(" ").append(cnt).append("\n");
		}
		System.out.println(rst);
	}
}
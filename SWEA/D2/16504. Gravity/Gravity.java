import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			int len = Integer.parseInt(br.readLine()), high = 0;
			int[] room = new int[len];
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < len; i++) {
				room[i] = Integer.parseInt(st.nextToken());
			}
			for (int i = 0; i < len - 1; i++) {
				int cnt = 0;
				for (int j = i + 1; j < len; j++) {
					if (room[i] > room[j])
						cnt++;
				}
				high = Math.max(high, cnt);
			}
			System.out.println("#" + t + " " + high);
		}
	}
}
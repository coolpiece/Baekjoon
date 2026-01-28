import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			String input = br.readLine();
			char cur = '0';
			int cnt = 0;
			for (int i = 0; i < input.length(); i++) {
				if (input.charAt(i) != cur) {
					cnt++;
					if (cur == '0')
						cur = '1';
					else
						cur = '0';
				}
			}
			System.out.println("#" + t + " " + cnt);
		}
	}
}
import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			StringBuilder a = new StringBuilder(st.nextToken()), b = new StringBuilder(st.nextToken()),
					rst = new StringBuilder();
			a.reverse();
			b.reverse();
			int lenA = a.length(), lenB = b.length();
			for (int i = 0; i < Math.abs(lenA - lenB); i++) {
				if (lenA > lenB)
					b.append("0");
				else
					a.append("0");
			}
			int carry = 0;
			for (int i = 0; i < Math.max(lenA, lenB); i++) {
				int sum = a.charAt(i) - '0' + b.charAt(i) - '0' + carry;
				carry = (sum >= 10) ? 1 : 0;
				rst.append(sum % 10);
			}
			if (carry == 1)
				rst.append("1");
			System.out.println("#" + t + " " + rst.reverse());
		}
	}
}
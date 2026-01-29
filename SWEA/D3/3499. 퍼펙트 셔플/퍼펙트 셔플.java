import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			StringBuilder rst = new StringBuilder();
			int n = Integer.parseInt(br.readLine()), cut;
			List<String> list = new ArrayList<>();
			st = new StringTokenizer(br.readLine());
			while (st.hasMoreTokens())
				list.add(st.nextToken());
			if (n % 2 == 0)
				cut = n / 2;
			else
				cut = n / 2 + 1;
			for (int i = 0; i < n / 2; i++) {
				rst.append(list.get(i) + " ");
				rst.append(list.get(cut + i) + " ");
			}
			if (n % 2 != 0)
				rst.append(list.get(n / 2));
			System.out.println("#" + t + " " + rst);
		}
	}
}
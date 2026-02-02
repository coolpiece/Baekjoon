import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		for (int t = 1; t <= 10; t++) {
			ArrayList<Integer> list = new ArrayList<>();
			int n = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++)
				list.add(Integer.parseInt(st.nextToken()));
			int cmd = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < cmd; i++) {
				st.nextToken(); // I 읽기.
				int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());
				for (int j = 0; j < y; j++) {
					if (x + j > 10)
						st.nextToken();
					else
						list.add(x + j, Integer.parseInt(st.nextToken()));
				}
			}
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < 10; i++)
				sb.append(" " + list.get(i));
			System.out.println("#" + t + sb);
		}
	}
}
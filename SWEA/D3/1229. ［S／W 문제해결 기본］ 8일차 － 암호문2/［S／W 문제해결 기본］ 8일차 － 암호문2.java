import java.io.*;
import java.util.*;
import java.util.stream.*;

public class Solution {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder rst = new StringBuilder();

		for (int t = 1; t <= 10; t++) {
			List<Integer> list = new LinkedList<>();
			int n = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++)
				list.add(Integer.parseInt(st.nextToken()));
			int m = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < m; i++) {
				String cmd = st.nextToken();
				int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());
				if (cmd.equals("I")) {
					for (int j = 0; j < y; j++)
						list.add(x + j, Integer.parseInt(st.nextToken()));

				} else if (cmd.equals("D")) {
					for (int j = 0; j < y; j++)
						list.remove(x);
				}
			}
//			for (int i : list)
//				rst.append(" ").append(i);
			String str = list.stream().limit(10).map(String::valueOf).collect(Collectors.joining(" "));
			rst.append("#").append(t).append(" ").append(str).append("\n");
		}
		System.out.println(rst);
	}
}
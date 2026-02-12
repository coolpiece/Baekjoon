import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n = Integer.parseInt(br.readLine());
		ArrayList<int[]> list = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
			list.add(new int[] { a, b });
		}
		list.sort((l1, l2) -> {
			if (l1[0] == l2[0])
				return l1[1] - l2[1];
			return l1[0] - l2[0];
		});
		int start = list.get(0)[0], end = list.get(0)[1], len = 0;
		for (int i = 1; i < n; i++) {
			if (list.get(i)[0] >= start && list.get(i)[0] <= end)
				end = Math.max(end, list.get(i)[1]);
			else {
				len += end - start;
				start = list.get(i)[0];
				end = list.get(i)[1];
			}
		}
		len += end - start;
		System.out.println(len);
	}
}
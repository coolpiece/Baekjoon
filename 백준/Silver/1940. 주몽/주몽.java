import java.io.*;
import java.util.*;

public class Main {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine()), m = Integer.parseInt(br.readLine());
		List<Integer> list = new ArrayList<>();
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++)
			list.add(Integer.parseInt(st.nextToken()));
		list.sort(null);
		int s = 0, e = n - 1, cnt = 0;
		while (s < e) {
			int sum = list.get(s) + list.get(e);
			if (sum == m) { // 갑옷 만들기 성공.
				cnt++;
				s++;
				e--;
				continue;
			}
			if (sum > m)
				e--;
			else
				s++;

		}
		System.out.println(cnt);
	}
}
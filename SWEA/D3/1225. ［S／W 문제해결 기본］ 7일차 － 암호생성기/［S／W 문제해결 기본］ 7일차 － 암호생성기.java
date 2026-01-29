import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for (int t = 1; t <= 10; t++) {
			int T = Integer.parseInt(br.readLine());
			boolean flag = false;
			StringTokenizer st = new StringTokenizer(br.readLine());
			Queue<Integer> q = new LinkedList<>();
			for (int i = 0; i < 8; i++)
				q.add(Integer.parseInt(st.nextToken()));
			while (true) {
				for (int i = 1; i <= 5; i++) {
					int tmp = q.poll() - i;
					if (tmp <= 0) {
						q.add(0);
						flag = true;
						break;
					}
					q.add(tmp);
				}
				if (flag)
					break;
			}
			System.out.println("#" + T);
			for (int i = 0; i < 8; i++)
				System.out.print(q.poll() + " ");
			System.out.println();
		}
	}
}
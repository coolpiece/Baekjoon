import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for (int t = 1; t <= 10; t++) {
			int T = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			Queue<Integer> q = new LinkedList<>();

			int x = Integer.MAX_VALUE / 15;
			for (int i = 0; i < 8; i++) {
				int input = Integer.parseInt(st.nextToken());
				x = Math.min(x, input / 15 - 1);
				q.add(input);
			}
			for (int i = 0; i < 8; i++)
				q.add(q.poll() - 15 * x);
			int cycle = 1;
			while (true) {
				int tmp = Math.max(0, q.poll() - cycle);
				q.offer(tmp);
				if (tmp == 0)
					break;
				cycle = cycle % 5 + 1;
			}
			System.out.print("#" + T + " ");
			for (int i = 0; i < 8; i++)
				System.out.print(q.poll() + " ");
			System.out.println();
		}
	}
}
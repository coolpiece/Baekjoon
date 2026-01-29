import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for (int t = 1; t <= 10; t++) {
			int T = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			Queue<Integer> q = new LinkedList<>();
			for (int i = 0; i < 8; i++)
				q.add(Integer.parseInt(st.nextToken()));
x:			while (true) {
				for (int i = 1; i <= 5; i++) {
					int tmp = q.poll() - i;
					if (tmp <= 0) {
						q.add(0);
						break x;
					}
					q.add(tmp);
				}
			}
			System.out.println("#" + T);
			for (int i = 0; i < 8; i++)
				System.out.print(q.poll() + " ");
			System.out.println();
		}
	}
}
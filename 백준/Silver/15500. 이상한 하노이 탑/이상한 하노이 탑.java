import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Stack<Integer> s1 = new Stack<>();
		Stack<Integer> s2 = new Stack<>();
		StringTokenizer st = new StringTokenizer(br.readLine());
		List<int[]> list = new ArrayList<>();
		for (int i = 0; i < n; i++)
			s1.add(Integer.parseInt(st.nextToken()));
		int size = n;
		while (true) {
			int c1 = 0, c2 = 0;
			if (!s1.isEmpty())
				c1 = s1.lastElement();
			if (!s2.isEmpty())
				c2 = s2.lastElement();
			if (c1 == size) {
				list.add(new int[] { 1, 3 });
				s1.pop();
				size--;
			} else if (c2 == size) {
				list.add(new int[] { 2, 3 });
				s2.pop();
				size--;
			} else {
				if (s1.indexOf(size) != -1) {
					list.add(new int[] { 1, 2 });
					s2.add(s1.pop());
				} else {
					list.add(new int[] { 2, 1 });
					s1.add(s2.pop());
				}
			}
			if (size == 0)
				break;
		}
		System.out.println(list.size());
		for (int[] i : list) {
			System.out.println(i[0] + " " + i[1]);
		}
	}
}
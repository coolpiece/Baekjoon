import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder rst = new StringBuilder(100);
		StringTokenizer st;

		for (int t = 1; t <= 10; t++) {
			int n = Integer.parseInt(br.readLine());
			boolean check = true;
			if (n % 2 == 0) // 자식 노드가 1개만 있는 노드가 있으면 연산 불가. (정 이진 트리가 아니면 불가)
				check = false;
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				if (!check)
					continue;
				int num = Integer.parseInt(st.nextToken()), left = 0, right = 0;
				char data = st.nextToken().charAt(0);
				if (st.hasMoreTokens())
					left = Integer.parseInt(st.nextToken());
				if (st.hasMoreTokens())
					right = Integer.parseInt(st.nextToken());
				// 자식 노드가 있으면 무조건 연산자.
				if (left != 0 && right != 0 && (data >= '0' && data <= '9')) { // 숫자인 경우.
					check = false;
					continue;
				}
				// 리프 노드면 무조건 숫자.
				if (left == 0 && right == 0 && (data < '0' || data > '9')) { // 연산자인 경우.
					check = false;
					continue;
				}
			}
			if (check)
				rst.append("#").append(t).append(" 1\n");
			else
				rst.append("#").append(t).append(" 0\n");
		}
		System.out.println(rst);
	}
}
import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder rst = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			String input = br.readLine();
			int n = Integer.parseInt(input), maxVal = 0;
			Stack<Integer> stack = new Stack<>();
			int turn[] = new int[100000]; // turn[i]: i의 최대 turn 수 저장.
			stack.add(n);
			while (!stack.isEmpty()) {
				int cur = stack.pop();
				int dep = turn[cur];
				String curS = Integer.toString(cur);
				if (curS.length() == 1) { // 더 이상 쪼갤 수 없음.
					maxVal = Math.max(maxVal, dep);
					continue;
				}
				for (int i = 1, len = curS.length() - 1; i < (1 << len); i++) { // 자르는 조합 구하기.
					int cal = 1, cut = 0;
					for (int j = 0; j < len; j++) { // 잘라서 곱하기.
						if ((i & (1 << j)) != 0) {
							cal *= Integer.parseInt(curS.substring(cut, j + 1));
							cut = j + 1;
						}
					}
					cal *= Integer.parseInt(curS.substring(cut));

					if (turn[cal] < dep + 1) { // 새로운 값을 스택에 넣을 때마다 cur 값 갱신.
						turn[cal] = dep + 1;
						stack.push(cal);
					}

				}
			}
			rst.append("#").append(t).append(" ").append(maxVal).append("\n");
		}
		System.out.println(rst);
	}
}
import java.io.*;
import java.util.*;

public class Solution {
	private static int n, op[];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			n = Integer.parseInt(br.readLine()); // 입력.
			int[] nums = new int[n];
			op = new int[n - 1];
			st = new StringTokenizer(br.readLine());
			for (int i = 1, idx = 0; i <= 4; i++) {
				int input = Integer.parseInt(st.nextToken());
				for (int j = 0; j < input; j++)
					op[idx++] = i;
			}
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++)
				nums[i] = Integer.parseInt(st.nextToken());

			int minVal = 100000000, maxVal = -100000000;
			do {
				int cal = nums[0];
				for (int i = 1; i < n; i++) {
					switch (op[i - 1]) {
					case 1:
						cal += nums[i];
						break;
					case 2:
						cal -= nums[i];
						break;
					case 3:
						cal *= nums[i];
						break;
					case 4:
						cal /= nums[i];
						break;
					}
				}
				minVal = Math.min(minVal, cal);
				maxVal = Math.max(maxVal, cal);
			} while (np());
			sb.append("#").append(t).append(" ").append(maxVal - minVal).append("\n");
		}
		System.out.println(sb);
	}

	static boolean np() {
		int i = n - 2;
		while (i > 0 && op[i - 1] >= op[i]) // 가장 큰 숫자 찾기.
			--i;
		if (i == 0)
			return false; // 가장 큰 순열인지 확인.

		int j = n - 2;
		while (op[i - 1] >= op[j]) // 찾은 값 다음으로 큰 수 뒤부터 찾기.
			--j;
		swap(i - 1, j);

		int k = n - 2;
		while (i < k) // 꼭대기부터 맨 뒤까지 가장 작은 수로 만듦.
			swap(i++, k--);
		return true;
	}

	private static void swap(int a, int b) {
		int tmp = op[a];
		op[a] = op[b];
		op[b] = tmp;
	}
}
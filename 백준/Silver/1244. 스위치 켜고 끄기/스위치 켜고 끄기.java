import java.io.*;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine()); // LED 개수.
		int state[] = new int[n + 1];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= n; i++) {
			state[i] = Integer.parseInt(st.nextToken());
		}
		int m = Integer.parseInt(br.readLine()); // 학생 수.
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int sex = Integer.parseInt(st.nextToken()), num = Integer.parseInt(st.nextToken());
			if (sex == 1) { // 남학생.
				for (int j = 1; j * num <= n; j++)
					state[j * num] = (state[j * num] == 0) ? 1 : 0; // 상태 바꾸기.
			} else { // 여학생.
				int len = 1;
				for (int j = 1; j <= Math.min(num - 1, n - num); j++) {
					if (state[num - j] == state[num + j]) // 대칭 구간 찾기.
						len++;
					else
						break;
				}
				for (int j = 0; j < len; j++) // 상태 바꾸기.
					state[num - j] = state[num + j] = (state[num + j] == 0) ? 1 : 0;
			}
		}
		int line = n / 20 + 1;
		for (int i = 0; i < line; i++) {
			for (int j = 1; j <= 20; j++) {
				System.out.print(state[i * 20 + j] + " ");
				if (i * 20 + j == n)
					return;
			}
			System.out.println();
		}
	}
}
import java.io.*;

public class Main {
	private static boolean[] col, leftupDia, rightupDia;
	private static int n, cnt;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		cnt = 0;
		col = new boolean[n];
		leftupDia = new boolean[n * 2 - 1]; // 왼쪽 위로 가는 대각선.
		rightupDia = new boolean[n * 2 - 1]; // 오른쪽 위로 가는 대각선.
		setQueen(0);
		System.out.println(cnt);
	}

	public static void setQueen(int x) {
		if (x == n) {
			cnt++;
			return;
		}
		for (int i = 0; i < n; i++) {
			if (!col[i]) {
				if (rightupDia[x + i])
					continue;
				if (leftupDia[x - i + n - 1])
					continue;
				col[i] = rightupDia[x + i] = leftupDia[x - i + n - 1] = true;
				setQueen(x + 1);
				col[i] = rightupDia[x + i] = leftupDia[x - i + n - 1] = false;
			}
		}
	}
}
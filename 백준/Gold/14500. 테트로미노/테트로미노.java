import java.io.*;
import java.util.*;

public class Main {
	private static int n, m, maxVal = 0, rst = 0, v[][];
	private static int[] dr = { -1, 1, 0, 0 }, dc = { 0, 0, -1, 1 };
	private static boolean[][] visited;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		v = new int[n][m];
		visited = new boolean[n][m];

		for (int i = 0; i < n; i++) { // 입력.
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				v[i][j] = Integer.parseInt(st.nextToken());
				maxVal = Math.max(maxVal, v[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visited[i][j] = true;
				dfs(i, j, 1, v[i][j]);
				visited[i][j] = false;
			}
		}
		System.out.println(rst);
	}

	static void dfs(int r, int c, int size, int sum) {
		if (sum + (4 - size) * maxVal <= rst) // 이미 구한 값보다 더 커질 수 없는 경우.
			return;
		if (size == 4) { // 4개를 모두 방문한 경우.
			rst = Math.max(rst, sum);
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i]; // 다음 좌표 탐색. 상하좌우 순.
			int nc = c + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m) // 범위를 넘어가는 경우.
				continue;

			if (!visited[nr][nc]) {
				visited[nr][nc] = true;
				if (size == 2) // ㅏ 모양 탐색.
					dfs(r, c, size + 1, sum + v[nr][nc]); // 다음을 방문 처리하고 제자리에서 다시 탐색.

				dfs(nr, nc, size + 1, sum + v[nr][nc]);
				visited[nr][nc] = false;
			}
		}
	}
}

//public class Main {
//	private static int[] price, coinCnt, rst;
//
//	public static void main(String[] args) throws Exception {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		price = new int[] { 25, 10, 5, 1 }; // 각 동전의 금액.
//		coinCnt = new int[4]; // 남아 있는 동전의 개수.
//		rst = new int[4]; // 사용한 동전의 개수.
//		StringTokenizer st = new StringTokenizer(br.readLine());
//		int x = Integer.parseInt(st.nextToken());
//		for (int i = 3; i >= 0; i--) // 금액 내림차순으로 저장.
//			coinCnt[i] = Integer.parseInt(st.nextToken());
//
//		for (int i = coinCnt[0]; i >= 0; i--) { // 25센트 개수를 줄여가며 가능한 경우 확인.
//			if (check(x - i * 25, 1)) { // 25센트로 만든 금액 제외한 나머지 쪼개기.
//				rst[0] = i;
//				break;
//			}
//		}
//		for (int i = 0; i < 3; i++) {
//			System.out.println("########################### " + i);
//			int cnt = rst[i];
//			for (int j = 0; j < cnt; j++) { // price[i] 센트 쪼개기 cnt번 반복.
//				if (i == 0 && j < cnt - 1 && check(50, 2)) { // 25센트 2개 묶어서 한 번에 50센트 쪼개기.
//					rst[i] -= 2;
//				} else if (check(price[i], i + 1))
//					rst[i]--;
//			}
//		}
//
//		for (int i = 3; i >= 0; i--) // 출력.
//			System.out.print(rst[i] + " ");
//	}
//
//	static boolean check(int target, int start) { // target: 만들 값. price[start]원 부터 사용.
//		int[] cc = coinCnt.clone();
//		int[] r = rst.clone();
//		for (int i = start; i < 4; i++) {
//			while (cc[i] > 0 && target >= price[i]) {
//				cc[i]--;
//				r[i]++;
//				target -= price[i];
//
//			}
//			System.out.println("*** coin: " + Arrays.toString(coinCnt));
//			System.out.println("=== rst: " + Arrays.toString(rst));
//		}
//		if (target == 0) { // 성공한 경우 적용.
//			coinCnt = cc;
//			rst = r;
//			return true;
//		}
//		return false;
//	}
//}
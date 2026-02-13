import java.io.*;
import java.util.*;

public class Solution {
	static int[] dx = new int[] { -1, 1, 0, 0 }, dy = new int[] { 0, 0, -1, 1 };
	static int n, maxStart, maxLength, room[][];
	static boolean visited[];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder rst = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			n = Integer.parseInt(br.readLine());
			room = new int[n][n];
			visited = new boolean[n * n + 1];
			maxStart = maxLength = 0;
			Map<Integer, int[]> map = new HashMap<>(); // 숫자별 좌표 저장.
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < n; j++) {
					room[i][j] = Integer.parseInt(st.nextToken());
					map.put(room[i][j], new int[] { i, j });
				}
			}

			for (int i = 1; i <= n * n; i++) {
				if (!visited[i]) {
					visited[i] = true;
					check(map.get(i)[0], map.get(i)[1], i, i, 1);
				}
			}
			rst.append("#").append(t).append(" ").append(maxStart).append(" ").append(maxLength).append("\n");
		}
		System.out.println(rst);
	}

	static void check(int x, int y, int cur, int start, int length) {
		for (int i = 0; i < 4; i++) { // 주변 탐색.
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (room[nx][ny] == cur + 1) { // 다음 칸으로 이동.
				visited[cur + 1] = true;
				check(nx, ny, cur + 1, start, length + 1);
				return;
			}
		}
		// 4방향 모두 없는 경우. 정보 저장 후 다음 출발지 찾기.
		if (length > maxLength) {
			maxLength = length;
			maxStart = start;
		}
	}
}
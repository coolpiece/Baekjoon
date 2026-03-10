import java.io.*;
import java.util.*;

public class Solution {
	static BufferedReader br;
	static StringTokenizer st;
	static int n, dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 }, cnt;
	static char map[][];
	static boolean visited[][];

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder rst = new StringBuilder();
		int T = Integer.parseInt(br.readLine());

		for (int t = 1; t <= T; t++) {
			n = Integer.parseInt(br.readLine());
			map = new char[n][];
			visited = new boolean[n][n];
			for (int i = 0; i < n; i++)
				map[i] = br.readLine().toCharArray();

			cnt = 0; // 지뢰가 없는 칸의 수.
			int click = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (map[i][j] == '.') { // 지뢰가 없는 칸의 숫자 표시.
						cnt++;
						map[i][j] = (char) (countZ(i, j) + '0');
					}
				}
			}

			// printMap();

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (map[i][j] == '0' && !visited[i][j]) {
						click++;
						cnt--;
						bfs(i, j);
					}
					if (cnt == 0)
						break; // 모든 칸이 열렸을 때.
				}
				if (cnt == 0)
					break;
			}

			if (cnt != 0)
				click += cnt;

			rst.append("#").append(t).append(" ").append(click).append("\n");
		}
		rst.append("\n");
		System.out.println(rst);
	}

	static int countZ(int r, int c) {
		int cntZ = 0;
		for (int i = 0; i < 8; i++) {
			int nr = r + dr[i], nc = c + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= n)
				continue;
			if (map[nr][nc] == '*')
				cntZ++;
		}
		return cntZ;
	}

	static void bfs(int startR, int startC) {
		Queue<int[]> q = new ArrayDeque<>();
		visited[startR][startC] = true;
		q.add(new int[] { startR, startC });
		while (!q.isEmpty()) {
			int r = q.peek()[0], c = q.poll()[1];
			for (int i = 0; i < 8; i++) {
				int nr = r + dr[i], nc = c + dc[i];
				if (nr < 0 || nr >= n || nc < 0 || nc >= n)
					continue;
				if (map[nr][nc] == '*')
					continue;
				if (!visited[nr][nc]) { // 주변 숫자들.
					visited[nr][nc] = true;
					cnt--;
					if (map[nr][nc] == '0')
						q.add(new int[] { nr, nc });
				}
			}
		}
	}

	static void printMap() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				System.out.print(map[i][j] + " ");
			System.out.println();
		}
		System.out.println();
	}
}
import java.io.*;
import java.util.*;

public class Solution {
	private static int endX, endY, dr[] = { -1, 1, 0, 0 }, dc[] = { 0, 0, -1, 1 };
	private static char[][] map;
	private static boolean[][] visited;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder rst = new StringBuilder();
		for (int t = 1; t <= 10; t++) {
			br.readLine();
			map = new char[100][];
			visited = new boolean[100][100];
			int startX = 0, startY = 0;
			for (int i = 0; i < 100; i++) { // 입력.
				String input = br.readLine();
				map[i] = input.toCharArray();
				if (input.indexOf("2") != -1) {
					startX = i;
					startY = input.indexOf("2");
				}
				if (input.indexOf("3") != -1) {
					endX = i;
					endY = input.indexOf("3");
				}
			}
			rst.append("#").append(t).append(" ").append(go(startX, startY, 1) ? 1 : 0).append("\n");
		}
		System.out.println(rst);
	}

	static boolean go(int r, int c, int len) {
		if (r == endX && c == endY) {
			return true;
		}
		visited[r][c] = true;
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i], nc = c + dc[i];
			if (nr < 0 || nr >= 100 | nc < 0 || nc >= 100)
				continue;
			if (map[nr][nc] != '1' && !visited[nr][nc]) {
				if (go(nr, nc, len + 1))
					return true;
			}
		}
		visited[r][c] = false;
		return false;
	}
}
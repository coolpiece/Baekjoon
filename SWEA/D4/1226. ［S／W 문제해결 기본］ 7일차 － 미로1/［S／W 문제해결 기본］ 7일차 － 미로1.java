import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder rst = new StringBuilder(100);
		int[] dx = { -1, 0, 0, 1 }, dy = { 0, -1, 1, 0 };

		x: for (int t = 1; t <= 10; t++) {
			int n = Integer.parseInt(br.readLine()), startX = 0, startY = 0, endX = 0, endY = 0;
			char[][] map = new char[16][];
			boolean[][] visited = new boolean[16][16];
			for (int i = 0; i < 16; i++) { // 입력 값 map에 저장.
				map[i] = br.readLine().toCharArray();
				for (int j = 0; j < 16; j++) {
					if (map[i][j] == '2') { // 출발점 좌표 저장.
						startX = i;
						startY = j;
					} else if (map[i][j] == '3') { // 도착점 좌표 저장.
						endX = i;
						endY = j;
					}
				}
			}
			Queue<int[]> q = new ArrayDeque<>(); // bfs.
			q.offer(new int[] { startX, startY });
			while (!q.isEmpty()) {
				int[] cur = q.poll();
				for (int i = 0; i < 4; i++) { // 4방 탐색.
					int nx = cur[0] + dx[i], ny = cur[1] + dy[i];
					if (nx < 0 || nx >= 16 || ny < 0 || ny >= 16)
						continue;
					if (map[nx][ny] == '3') { // 도착점 발견.
						rst.append("#").append(n).append(" 1\n");
						continue x;
					}
					if (!visited[nx][ny] && map[nx][ny] == '0') {
						visited[nx][ny] = true;
						q.offer(new int[] { nx, ny });
					}
				}
			}
			rst.append("#").append(n).append(" 0\n"); // 도착 불가.
		}
		System.out.println(rst);
	}
}
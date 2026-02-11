import java.io.*;
import java.util.*;

class Atom {
	int x, y, dir, energy;

	Atom(int x, int y, int dir, int energy) {
		this.x = x;
		this.y = y;
		this.dir = dir;
		this.energy = energy;
	}
}

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder rst = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		int[] dx = new int[] { 0, 0, -1, 1 }, dy = new int[] { 1, -1, 0, 0 };
		for (int t = 1; t <= T; t++) {
			int n = Integer.parseInt(br.readLine()), total = 0;
			// 중간에 충돌하는 경우를 정수 시간으로 계산하기 위해 좌표를 2배.
			ArrayDeque<Atom> list = new ArrayDeque<>(); // 원소 목록 저장.
			int[][] map = new int[4001][4001]; // 좌표 저장. 충돌 확인.
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken()),
						dir = Integer.parseInt(st.nextToken()), energy = Integer.parseInt(st.nextToken());
				list.add(new Atom(x * 2 + 2000, y * 2 + 2000, dir, energy));
				map[x * 2 + 2000][y * 2 + 2000] = energy;
			}

			while (!list.isEmpty()) {
				Atom a = list.poll();
				if (map[a.x][a.y] != a.energy) { // 충돌한 경우 에너지가 증가되어 있음.
					total += map[a.x][a.y];
					map[a.x][a.y] = 0;
					continue;
				}
				map[a.x][a.y] = 0;
				int nx = a.x + dx[a.dir], ny = a.y + dy[a.dir];
				if (nx < 0 || nx > 4000 || ny < 0 || ny > 4000)
					continue;
				if (map[nx][ny] == 0) { // 충돌하지 않은 경우에만 다시 리스트에 저장.
					a.x = nx;
					a.y = ny;
					list.add(a);
				}
				map[nx][ny] += a.energy; // 이동한 자리에 에너지 저장.
			}

			rst.append("#").append(t).append(" ").append(total).append("\n");
		}
		System.out.println(rst);
	}
}
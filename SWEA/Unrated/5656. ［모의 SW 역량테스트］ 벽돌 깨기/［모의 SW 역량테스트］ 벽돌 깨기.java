import java.io.*;
import java.util.*;

class Brick {
	int r, c, power;

	Brick(int r, int c, int power) {
		this.r = r;
		this.c = c;
		this.power = power;
	}
}

public class Solution {
	static int n, w, h, minVal, dr[] = { -1, 1, 0, 0 }, dc[] = { 0, 0, -1, 1 };

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder rst = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			w = Integer.parseInt(st.nextToken());
			h = Integer.parseInt(st.nextToken());
			minVal = Integer.MAX_VALUE;
			int map[][] = new int[h][w];

			int brickCnt = 0;
			for (int i = 0; i < h; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < w; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
					if (map[i][j] != 0)
						brickCnt++;
				}
			}
			permutationR(0, map, brickCnt);
			rst.append("#").append(t).append(" ").append(minVal).append("\n");
		}
		System.out.println(rst);
	}

	static int[][] copyMap(int map[][]) {
		int copy[][] = new int[h][w];
		for (int i = 0; i < h; i++)
			copy[i] = map[i].clone();
		return copy;
	}

	static void permutationR(int count, int map[][], int brickCnt) { // 중복 순열.
		if (brickCnt == 0) { // 남은 벽돌이 없으면.
			minVal = 0;
			return;
		}

		if (count == n) { // 다 선택하면.
			minVal = Math.min(minVal, brickCnt);
			return;
		}

		for (int i = 0; i < w; i++) {
			int copy[][] = copyMap(map); // 초기화.
			int nextCnt = brickCnt;

			int j = 0; // 벽돌이 처음 나타나는 위치 찾기.
			while (j < h && copy[j][i] == 0)
				j++;

			if (j < h) // 벽돌이 있는 경우.
				nextCnt = attack(copy, j, i, nextCnt);

			permutationR(count + 1, copy, nextCnt);
		}
	}

	static int attack(int map[][], int r, int c, int brickCnt) {
		Queue<Brick> q = new ArrayDeque<>();
		q.add(new Brick(r, c, map[r][c]));
		map[r][c] = 0;
		brickCnt--;

		while (!q.isEmpty()) {
			int tr = q.peek().r, tc = q.peek().c, power = q.poll().power;

			for (int i = 0; i < 4; i++) { // 상하좌우 벽돌 깨기.
				for (int j = 1; j < power; j++) {
					int nr = tr + dr[i] * j, nc = tc + dc[i] * j;
					if (nr < 0 || nr >= h || nc < 0 || nc >= w)
						continue;
					if (map[nr][nc] != 0) { // 연쇄적 제거.
						if (map[nr][nc] > 1)
							q.add(new Brick(nr, nc, map[nr][nc]));
						map[nr][nc] = 0;
						brickCnt--;
					}
				}
			}
		}
		gravity(map); // 떨어뜨리기.
//		printBoard(map, brickCnt);
		return brickCnt;
	}

	static void gravity(int map[][]) { // 중력 적용.
//		Queue<Integer> q = new ArrayDeque<>();
//		for (int i = 0; i < w; i++) { // 아래서부터 벽돌이 남아 있는 칸 저장.
//			for (int j = h - 1; j >= 0; j--)
//				if (map[j][i] != 0)
//					q.add(map[j][i]);
//
//			for (int j = h - 1; j >= 0; j--) {
//				if (!q.isEmpty())
//					map[j][i] = q.poll().intValue();
//				else
//					map[j][i] = 0;
//			}
//		}

		// 투포인터로 변경.
		for (int i = 0; i < w; i++) {
			int floor = h - 1;

			for (int j = h - 1; j >= 0; j--) {
				if (map[j][i] != 0) { // 벽돌 발견.
					if (j != floor) { // 현재 위치가 바닥이 아님. (공중에 떠있는 상태.)
						map[floor][i] = map[j][i];
						map[j][i] = 0;
					}
					floor--;
				}
			}
		}

	}

	static void printBoard(int map[][], int brickCnt) {
		System.out.println("cnt: " + brickCnt);
		for (int i = 0; i < h; i++)
			System.out.println(Arrays.toString(map[i]));
		System.out.println();
	}
}
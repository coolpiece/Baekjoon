import java.io.*;
import java.util.*;

class Misaengmul implements Comparable<Misaengmul> {
	int r, c, cnt, dir;

	Misaengmul(int r, int c, int cnt, int dir) {
		this.r = r;
		this.c = c;
		this.cnt = cnt;
		this.dir = dir;
	}

	@Override
	public int compareTo(Misaengmul o) {
		return Comparator.comparingInt((Misaengmul m) -> m.r).thenComparingInt(m -> m.c).thenComparingInt(m -> -m.cnt)
				.compare(this, o);
	}
}

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder rst = new StringBuilder();
		int dr[] = { 0, -1, 1, 0, 0 }, dc[] = { 0, 0, 0, -1, 1 };
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()),
					k = Integer.parseInt(st.nextToken());

			Queue<Misaengmul> q = new ArrayDeque<>();
			for (int i = 0; i < k; i++) {
				st = new StringTokenizer(br.readLine());
				int r = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken()),
						cnt = Integer.parseInt(st.nextToken()), dir = Integer.parseInt(st.nextToken());
				q.add(new Misaengmul(r, c, cnt, dir));
			}

			int time = 0, total = 0;
			List<Misaengmul> list = new ArrayList<>(); // 이동한 미생물의 위치 저장.
			while (!q.isEmpty()) {
				Misaengmul cur = q.poll();
				int r = cur.r, c = cur.c, cnt = cur.cnt, dir = cur.dir;
				int nr = r + dr[dir], nc = c + dc[dir];
				if (nr < 0 || nr >= n || nc < 0 || nc >= n)
					continue;
				if (nr == 0 || nr == n - 1 || nc == 0 || nc == n - 1) { // 약품.
					cnt /= 2;
					switch (dir) { // 방향 전환.
					case 1:
						dir = 2;
						break;
					case 2:
						dir = 1;
						break;
					case 3:
						dir = 4;
						break;
					case 4:
						dir = 3;
						break;
					}
				}

				list.add(new Misaengmul(nr, nc, cnt, dir));
				total += cnt;
//				System.out.println("cur: " + cnt + ", total: " + total);

				if (q.isEmpty()) { // 1시간 지남.
					list.sort(null); // 모인 미생물들 합친 후 큐에 넣기.
					Misaengmul rep = list.get(0);
					for (int i = 1; i < list.size(); i++) {
						Misaengmul mi = list.get(i);
						if (rep.r == mi.r && rep.c == mi.c) // 같은 좌표로 모이는 경우.
							rep.cnt += mi.cnt;
						else {
							q.add(new Misaengmul(rep.r, rep.c, rep.cnt, rep.dir));
							rep = mi;
						}
					}
					q.add(new Misaengmul(rep.r, rep.c, rep.cnt, rep.dir));
					time++;
					if (time == m) {
						rst.append("#").append(t).append(" ").append(total).append("\n");
						break;
					}
					total = 0;
					list.clear();
				}
			}
		}
		System.out.println(rst);
	}
}
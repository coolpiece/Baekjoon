import java.io.*;
import java.util.*;

class BC {
	int row, col, cover, perfo;

	BC(int row, int col, int cover, int perfo) {
		this.row = row;
		this.col = col;
		this.cover = cover;
		this.perfo = perfo;
	}
}

public class Solution {
	static int[] dr = new int[] { 0, 0, 1, 0, -1 }, dc = new int[] { 0, -1, 0, 1, 0 };

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder rst = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			int M = Integer.parseInt(st.nextToken()), A = Integer.parseInt(st.nextToken());
			int[] userA = new int[M + 1], userB = new int[M + 1];
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < M; i++)
				userA[i] = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < M; i++)
				userB[i] = Integer.parseInt(st.nextToken());

			BC[] bc = new BC[A]; // BC 정보 저장.
			for (int i = 0; i < A; i++) {
				st = new StringTokenizer(br.readLine());
				int row = Integer.parseInt(st.nextToken()), col = Integer.parseInt(st.nextToken()),
						c = Integer.parseInt(st.nextToken()), p = Integer.parseInt(st.nextToken());
				bc[i] = new BC(row, col, c, p);
			}

			int rA = 1, cA = 1, rB = 10, cB = 10, total = 0;
			List<Integer> mapA = new ArrayList<>();
			List<Integer> mapB = new ArrayList<>();
			for (int i = 0; i <= M; i++) { // 이동 시뮬레이션.
				mapA = new ArrayList<>(); // 사용자 A가 접속 가능한 BC 목록.
				for (int j = 0; j < A; j++) // 현재 위치에서 충전 가능한 BC 목록 만들기.
					if (Math.abs(rA - bc[j].row) + Math.abs(cA - bc[j].col) <= bc[j].cover)
						mapA.add(j);
				mapB = new ArrayList<>(); // 사용자 B가 접속 가능한 BC 목록.
				for (int j = 0; j < A; j++)
					if (Math.abs(rB - bc[j].row) + Math.abs(cB - bc[j].col) <= bc[j].cover)
						mapB.add(j);
				int maxVal = 0; // 조합 중 최댓값 저장.
				if (!mapA.isEmpty() && mapB.isEmpty()) { // A만 접속 가능한 경우.
					for (int j = 0; j < mapA.size(); j++)
						maxVal = Math.max(maxVal, bc[mapA.get(j)].perfo);
				} else if (mapA.isEmpty() && !mapB.isEmpty()) { // B만 접속 가능한 경우.
					for (int j = 0; j < mapB.size(); j++)
						maxVal = Math.max(maxVal, bc[mapB.get(j)].perfo);
				} else if (!mapA.isEmpty() && !mapB.isEmpty()) {
					for (int j : mapA) {
						for (int k : mapB) {
							if (j == k)
								maxVal = Math.max(maxVal, bc[j].perfo);
							else
								maxVal = Math.max(maxVal, bc[j].perfo + bc[k].perfo);
						}
					}
				}
				total += maxVal;
				// 다음 칸으로 이동.
				rA += dr[userA[i]];
				cA += dc[userA[i]];
				rB += dr[userB[i]];
				cB += dc[userB[i]];
			}
			rst.append("#").append(t).append(" ").append(total).append("\n");
		}
		System.out.println(rst);
	}
}
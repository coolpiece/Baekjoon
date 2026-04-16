import java.io.*;
import java.util.*;

class Pos { // 지렁이 좌표 저장.
	int x, y;

	Pos(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

public class Solution {
	static Pos[] earthworms;
	static int n;
	static long totalX, totalY, minVal;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder rst = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			rst.append("#").append(t).append(" ");
			n = Integer.parseInt(br.readLine());

			earthworms = new Pos[n];

			totalX = 0;
			totalY = 0;
			minVal = Long.MAX_VALUE;
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());
				earthworms[i] = new Pos(x, y);
				totalX += x;
				totalY += y;
			}
			combi(0, 0, 0, 0);
			rst.append(minVal).append("\n");
		}
		System.out.println(rst);
	}

	static void combi(int start, int cnt, long sumX, long sumY) {
		if (cnt == n / 2) { // 전체 중 절반 선택. 반은 출발점, 반은 도착점.
			long endX = totalX - sumX;
			long endY = totalY - sumY;
			long x = sumX - endX, y = sumY - endY;
			minVal = Math.min(minVal, x * x + y * y);
			return;
		}

		// 남은 원소가 더 뽑아야 하는 수보다 적으면 탐색할 필요 없음. 가지치기.
		for (int i = start; i < n - (n / 2 - cnt); i++)
			combi(i + 1, cnt + 1, sumX + earthworms[i].x, sumY + earthworms[i].y); // 선택한 경우.
	}
}
import java.io.*;

public class Solution {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder rst = new StringBuilder(100);

		for (int t = 1; t <= 10; t++) {
			int tc = Integer.parseInt(br.readLine()), endX = 99, endY = 0;
			String[][] map = new String[100][];
			for (int i = 0; i < 100; i++) { // 입력 값 map에 저장.
				map[i] = br.readLine().split(" ");
				for (int j = 0; j < 100; j++) {
					if (map[i][j].equals("2")) // 도착점 좌표 저장.
						endY = j;
				}
			}
			while (true) {
				if (endX == 0)
					break;

				while (endY - 1 >= 0 && map[endX][endY - 1].equals("1")) { // 왼쪽으로 이동.
					endY--;
					if (endX - 1 >= 0 && map[endX - 1][endY].equals("1"))
						endX--;
				}
				while (endY + 1 < 100 && map[endX][endY + 1].equals("1")) { // 오른쪽으로 이동.
					endY++;
					if (endX - 1 >= 0 && map[endX - 1][endY].equals("1"))
						endX--;
				}
				if (endX - 1 >= 0)
					endX--;
			}
			rst.append("#").append(t).append(" ").append(endY).append("\n");
		}
		System.out.println(rst);
	}
}
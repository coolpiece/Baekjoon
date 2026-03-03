import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder rst = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int h = Integer.parseInt(st.nextToken()), w = Integer.parseInt(st.nextToken());
			int r = 0, c = 0;
			char map[][] = new char[h][];
			for (int i = 0; i < h; i++) { // 입력.
				map[i] = br.readLine().toCharArray();
				for (int j = 0; j < w; j++) {
					switch (map[i][j]) {
					case '^':
						r = i;
						c = j;
						break;
					case 'v':
						r = i;
						c = j;
						break;
					case '<':
						r = i;
						c = j;
						break;
					case '>':
						r = i;
						c = j;
						break;
					default:
						break;
					}
				}
			}
			int n = Integer.parseInt(br.readLine());
			char cmd[] = br.readLine().toCharArray();

			for (int i = 0; i < n; i++) {
				switch (cmd[i]) {
				case 'U':
					if (r - 1 >= 0 && map[r - 1][c] == '.') {
						map[r][c] = '.';
						map[--r][c] = '^';
					} else
						map[r][c] = '^';
					break;
				case 'D':
					if (r + 1 < h && map[r + 1][c] == '.') {
						map[r][c] = '.';
						map[++r][c] = 'v';
					} else
						map[r][c] = 'v';
					break;
				case 'L':
					if (c - 1 >= 0 && map[r][c - 1] == '.') {
						map[r][c] = '.';
						map[r][--c] = '<';
					} else
						map[r][c] = '<';

					break;
				case 'R':
					if (c + 1 < w && map[r][c + 1] == '.') {
						map[r][c] = '.';
						map[r][++c] = '>';
					} else
						map[r][c] = '>';

					break;
				case 'S':
					switch (map[r][c]) {
					case '^':
						for (int j = r - 1; j >= 0; j--) {
							if (map[j][c] == '#') // 돌벽.
								break;
							if (map[j][c] == '*') { // 허수아비 파괴.
								map[j][c] = '.';
								break;
							}
						}
						break;
					case 'v':
						for (int j = r + 1; j < h; j++) {
							if (map[j][c] == '#') // 돌벽.
								break;
							if (map[j][c] == '*') { // 허수아비 파괴.
								map[j][c] = '.';
								break;
							}
						}
						break;
					case '<':
						for (int j = c - 1; j >= 0; j--) {
							if (map[r][j] == '#') // 돌벽.
								break;
							if (map[r][j] == '*') { // 허수아비 파괴.
								map[r][j] = '.';
								break;
							}
						}
						break;
					case '>':
						for (int j = c + 1; j < w; j++) {
							if (map[r][j] == '#') // 돌벽.
								break;
							if (map[r][j] == '*') { // 허수아비 파괴.
								map[r][j] = '.';
								break;
							}
						}
						break;
					}
					break;
				}
//				System.out.println("cmd: " + cmd[i] + ", r: " + r + ", c: " + c);
//				for (int x = 0; x < h; x++) {
//					for (int y = 0; y < w; y++)
//						System.out.print(map[x][y]);
//					System.out.println();
//				}
//				System.out.println();
			}
			rst.append("#").append(t).append(" ");
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++)
					rst.append(map[i][j]);
				rst.append("\n");
			}
		}
		System.out.println(rst);
	}
}
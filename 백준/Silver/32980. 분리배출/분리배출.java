import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Main {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()), p = 0, c = 0, v = 0, s = 0, g = 0, f = 0, o = 0;
		for (int i = 0; i < n; i++) {
			String trash = br.readLine();
			char ch = trash.charAt(0);
			int len = trash.length();
			boolean flag = false;
			if (ch == 'O')
				flag = true;
			else {
				for (int j = 1; j < len; j++) {
					if (ch != trash.charAt(j)) {
						flag = true;
						break;
					}
				}
			}
			if (flag)
				o += len; // 일반 쓰레기
			else { // 재활용 쓰레기
				if (ch == 'P')
					p += len;
				else if (ch == 'C')
					c += len;
				else if (ch == 'V')
					v += len;
				else if (ch == 'S')
					s += len;
				else if (ch == 'G')
					g += len;
				else if (ch == 'F')
					f += len;
			}
		}
		st = new StringTokenizer(br.readLine());
		long costP = Long.parseLong(st.nextToken()), costC = Long.parseLong(st.nextToken()),
				costV = Long.parseLong(st.nextToken()), costS = Long.parseLong(st.nextToken()),
				costG = Long.parseLong(st.nextToken()), costF = Long.parseLong(st.nextToken());
		st = new StringTokenizer(br.readLine());
		long costO = Long.parseLong(st.nextToken());
		costP = Math.min(costP, costO);
		costC = Math.min(costC, costO);
		costV = Math.min(costV, costO);
		costS = Math.min(costS, costO);
		costG = Math.min(costG, costO);
		costF = Math.min(costF, costO);

		long cost = costO * o + costP * p + costC * c + costV * v + costS * s + costG * g + costF * f;

		bw.write(Long.toString(cost));
		bw.flush();
		bw.close();
	}
}
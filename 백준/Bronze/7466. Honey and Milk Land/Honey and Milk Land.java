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
		int n = Integer.parseInt(st.nextToken()), e = Integer.parseInt(st.nextToken());
		int ew = 0, ns = 0;

		for (int i = 0; i < n - 1; i++) {
			while (!st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			ew += Integer.parseInt(st.nextToken());
		}
		for (int i = 0; i < e - 1; i++) {
			while (!st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			ns += Integer.parseInt(st.nextToken());
		}
		bw.write(String.valueOf((int) Math.ceil(Math.sqrt(ew * ew + ns * ns))));
		bw.flush();
		bw.close();
	}
}
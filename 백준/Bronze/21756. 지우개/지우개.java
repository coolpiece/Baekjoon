import java.io.*;

public class Main {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] v = new int[] { 1, 2, 4, 8, 16, 32, 64 };
		int input = Integer.parseInt(br.readLine()), rst = 1;
		for (int i = 0; i < 7; i++) {
			if (input < v[i])
				break;
			rst = v[i];
		}
		System.out.println(rst);
	}
}
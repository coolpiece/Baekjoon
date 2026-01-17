import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int t = Integer.parseInt(br.readLine());
		for (int i = 0; i < t; i++) {
			long n = Long.parseLong(br.readLine());
			n %= 28;
			if (n == 0)
				n = 28;
			if (n > 15)
				n = 30 - n;
			String b = Long.toBinaryString(n);
			if (b.length() == 1)
				b = "000" + b;
			else if (b.length() == 2)
				b = "00" + b;
			else if (b.length() == 3)
				b = "0" + b;
			for (int j = 0; j < b.length(); j++) {
				if (b.charAt(j) == '1')
					bw.write("딸기");
				else
					bw.write("V");
			}
			bw.write('\n');
		}
		bw.flush();
		bw.close();
	}
}
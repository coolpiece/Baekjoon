import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()), a = Integer.parseInt(st.nextToken()),
				b = Integer.parseInt(st.nextToken());
		long total = 0;
		ArrayList<Integer> discount = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int p = Integer.parseInt(st.nextToken()), q = Integer.parseInt(st.nextToken());
			discount.add(p - q);
			total += q;
		}
		discount.sort(null);
		for (int i = 0; i < a; i++)
			total += discount.get(i);
		System.out.println(total);
	}
}
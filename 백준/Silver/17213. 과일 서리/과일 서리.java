import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), m = sc.nextInt();
		m -= n;
		int a = n + m - 1;
		long rst = 1;
		if ((n + m - 1) / 2 < m)
			m = n - 1;
		for (int i = 1; i <= m; i++, a--)
			rst *= a;
		for (int i = 1; i <= m; i++)
			rst /= i;
		System.out.println(rst);
	}
}
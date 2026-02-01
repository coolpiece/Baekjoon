import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		StringBuilder str = new StringBuilder(sc.next());
		int d = sc.nextInt(), m = sc.nextInt(), h = 0, y = 0, u = 0, energy = 0, del = 0;
		for (int i = 0; i < n; i++) {
			if (str.charAt(i) == 'H')
				h++;
			else if (str.charAt(i) == 'Y')
				y++;
			else if (str.charAt(i) == 'U')
				u++;
			else {
				del++;
				if (i != n - 1)
					continue;
			}
			energy += Math.min(d * del, d + m);
			del = 0;
		}
		System.out.println((energy == 0) ? "Nalmeok" : energy);
		int cnt = Math.min(h, Math.min(y, u));
		System.out.println((cnt == 0) ? "I love HanYang University" : cnt);
	}
}
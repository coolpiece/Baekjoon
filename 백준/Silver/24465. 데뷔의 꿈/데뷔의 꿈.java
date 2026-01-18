import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Main {
	static int check(int mon, int day) {
		if (mon == 1) {
			if (day <= 19)
				return 11;
			else
				return 0;
		} else if (mon == 2) {
			if (day <= 18)
				return 0;
			else
				return 1;
		} else if (mon == 3) {
			if (day <= 20)
				return 1;
			else
				return 2;
		} else if (mon == 4) {
			if (day <= 19)
				return 2;
			else
				return 3;
		} else if (mon == 5) {
			if (day <= 20)
				return 3;
			else
				return 4;
		} else if (mon == 6) {
			if (day <= 21)
				return 4;
			else
				return 5;
		} else if (mon == 7) {
			if (day <= 22)
				return 5;
			else
				return 6;
		} else if (mon == 8) {
			if (day <= 22)
				return 6;
			else
				return 7;
		} else if (mon == 9) {
			if (day <= 22)
				return 7;
			else
				return 8;
		} else if (mon == 10) {
			if (day <= 22)
				return 8;
			else
				return 9;
		} else if (mon == 11) {
			if (day <= 22)
				return 9;
			else
				return 10;
		} else {
			if (day <= 21)
				return 10;
			else
				return 11;
		}
	}

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int[] star = new int[12];
		for (int i = 0; i < 7; i++) {
			st = new StringTokenizer(br.readLine());
			int mon = Integer.parseInt(st.nextToken()), day = Integer.parseInt(st.nextToken());
			int mem = check(mon, day);
			star[mem] = 1;
		}
		int n = Integer.parseInt(br.readLine());
		List<int[]> list = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int mon = Integer.parseInt(st.nextToken()), day = Integer.parseInt(st.nextToken());
			int pass = check(mon, day);
			if (star[pass] == 0)
				list.add(new int[] { mon, day });
		}
		list.sort((a, b) -> {
			if (a[0] == b[0])
				return a[1] - b[1];
			return a[0] - b[0];
		});

		if (list.isEmpty())
			System.out.println("ALL FAILED");
		else {
			for (int[] i : list) {
				System.out.println(i[0]+" "+i[1]);
			}
		}
	}
}
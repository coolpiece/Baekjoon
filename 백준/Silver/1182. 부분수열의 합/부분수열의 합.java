import java.io.*;
import java.util.*;

public class Main {
	static int n, s, cnt, select[], list[];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		s = Integer.parseInt(st.nextToken());
		cnt = 0;
		select = new int[n];
		list = new int[n];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++)
			list[i] = Integer.parseInt(st.nextToken());
		for (int i = 1; i <= n; i++)
			combi(0, 0, i);
		System.out.println(cnt);
	}

	static void combi(int idx, int count, int pickNum) {
		if (count == pickNum) {
			int sum = 0;
			for (int i = 0; i < pickNum; i++)
				sum += select[i];
			if (sum == s)
				cnt++;
			return;
		}
		for (int i = idx; i < n; i++) {
			select[count] = list[i];
			combi(i + 1, count + 1, pickNum);
		}
	}
}
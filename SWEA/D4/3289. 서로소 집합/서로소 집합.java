import java.io.*;
import java.util.*;

public class Solution {
	static BufferedReader br;
	static StringTokenizer st;
	static int rank[], set[], n; // rank: 깊이에 따른 랭킹, set[i]: i가 속한 집합의 대표자.

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder rst = new StringBuilder();
		int T = Integer.parseInt(br.readLine());

		for (int t = 1; t <= T; t++) {
			rst.append("#").append(t).append(" ");
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			set = new int[n + 1];
			rank = new int[n + 1];
			for (int i = 1; i <= n; i++) // 초기 집합.
				set[i] = i;
			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(br.readLine());
				char type = st.nextToken().charAt(0);
				int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
				if (type == '0') { // type이 0이면 합집합.
					union(findset(a), findset(b));
				} else { // type이 1이면 같은 집합에 포함되어 있는지 확인.
					if (findset(a) == findset(b)) // 대표자가 같으면 같은 집합.
						rst.append(1);
					else
						rst.append(0);
				}
			}
			rst.append("\n");
		}
		System.out.println(rst);
	}

	static void union(int pa, int pb) { // pa(pb): a(b)가 속한 집합의 대표자.
		if (pa == pb) // 이미 같은 집합.
			return;
		if (rank[pa] > rank[pb]) // pa 집합에 pb 집합 붙이기.
			set[pb] = pa;
		else { // pb 집합에 pa 집합 붙이기.
			set[pa] = pb;
			if (rank[pa] == rank[pb])
				rank[pb]++;
		}
	}

	static int findset(int a) { // a 집합의 대표자 return.
		if (set[a] == a) // 자기 자신이 대표자인 경우.
			return a;
		else // 재귀적으로 타고 올라가기.
			return set[a] = findset(set[a]);
	}
}
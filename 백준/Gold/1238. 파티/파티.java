import java.io.*;
import java.util.*;

class Node implements Comparable<Node> {
	int to, cost;

	public Node(int to, int cost) {
		this.to = to;
		this.cost = cost;
	}

	@Override
	public int compareTo(Node o) {
		return Integer.compare(this.cost, o.cost);
	}

}

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()),
				x = Integer.parseInt(st.nextToken());

		List<Node> list[] = new ArrayList[n + 1];
		for (int i = 0; i <= n; i++) // 초기화.
			list[i] = new ArrayList<>();
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken()), end = Integer.parseInt(st.nextToken()),
					t = Integer.parseInt(st.nextToken());
			list[start].add(new Node(end, t));
		}

		int minDisGo[] = new int[n + 1]; // 각 마을에서 X번 마을까지의 최소 비용.
		int minDisBack[] = new int[n + 1]; // X번 마을에서 각 마을까지의 최소 비용.
		PriorityQueue<Integer> dis = new PriorityQueue<>(Collections.reverseOrder());

		Arrays.fill(minDisBack, Integer.MAX_VALUE);
		PriorityQueue<Node> pq = new PriorityQueue<>();

		minDisBack[x] = 0;
		pq.add(new Node(x, 0));
		while (!pq.isEmpty()) {
			Node cur = pq.poll();
			if (minDisBack[cur.to] < cur.cost) // 거쳐가는 것이 더 손해인 경우 패스.
				continue;
			for (Node next : list[cur.to]) { // 거리 갱신, 다음 노드 넣기.
				int newCost = minDisBack[cur.to] + next.cost;
				if (minDisBack[next.to] > newCost) {
					minDisBack[next.to] = newCost;
					pq.add(next);
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			Arrays.fill(minDisGo, Integer.MAX_VALUE); // 초기화.
			pq.clear();

			minDisGo[i] = 0; // 시작점으로 가는 비용 0.
			pq.add(new Node(i, 0));

			while (!pq.isEmpty()) {
				Node cur = pq.poll();
				if (minDisGo[cur.to] < cur.cost) // 거쳐가는 것이 더 손해인 경우 패스.
					continue;

				for (Node next : list[cur.to]) { // 거리 갱신, 다음 노드 넣기.
					int newCost = minDisGo[cur.to] + next.cost;
					if (minDisGo[next.to] > newCost) {
						minDisGo[next.to] = newCost;
						pq.add(next);
					}
				}
			}
			dis.add(minDisGo[x] + minDisBack[i]);
		}

		System.out.println(dis.poll());
	}
}
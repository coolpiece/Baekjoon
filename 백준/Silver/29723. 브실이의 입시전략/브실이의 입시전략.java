import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()),
				k = Integer.parseInt(st.nextToken());
		Map<String, Integer> map = new HashMap<>();

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			String sub = st.nextToken();
			int point = Integer.parseInt(st.nextToken());
			map.put(sub, point);
		}

		int scoreMin = 0;
		for (int i = 0; i < k; i++) {
			String str = br.readLine();
			scoreMin += map.get(str);
			map.remove(str);
		}
		List<String> list = new ArrayList<>(map.keySet());
		Collections.sort(list, (value1, value2) -> map.get(value1).compareTo(map.get(value2)));

		m -= k;
		int scoreMax = scoreMin;
		int tmp = m;
		for (String key : list) {
            if (tmp == 0)
				break;
			scoreMin += map.get(key);
			tmp--;
		}

		Collections.sort(list, (value1, value2) -> map.get(value2).compareTo(map.get(value1)));
		tmp = m;
		for (String key : list) {
            if (tmp == 0)
				break;
			scoreMax += map.get(key);
			tmp--;
		}
		bw.write(Integer.toString(scoreMin) + ' ' + Integer.toString(scoreMax));
		bw.flush();
		bw.close();
	}
}
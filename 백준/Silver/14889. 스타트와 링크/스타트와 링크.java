import java.io.*;
import java.util.*;

public class Main {
    private static int n, member[][], minVal;
    private static boolean[] visited;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        member= new int[n][n];
        minVal = Integer.MAX_VALUE;
        visited = new boolean[n]; // 링크 팀 멤버를 구하기 위해.
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++)
                member[i][j] = Integer.parseInt(st.nextToken());
        }
        int[] list = new int[n / 2];
        pick(0, 0, list);
        System.out.println(minVal);
    }

    static void pick(int start, int cnt, int[] list) {
        if (cnt == n / 2) {
            int sumA = 0; // 스타트 팀 능력치.
            for (int i = 0; i < n / 2 - 1; i++) {
                for (int j = i + 1; j < n / 2; j++) {
                    int f1 = list[i], f2 = list[j];
                    sumA += member[f1][f2] + member[f2][f1];
                }
            }

            int[] list2 = new int[n / 2]; // 링크 팀 멤버 목록.
            for (int i = 0, idx = 0; i < n && idx < n / 2; i++)
                if (!visited[i])
                    list2[idx++] = i;
            int sumB = 0; // 링크 팀 능력치.
            for (int i = 0; i < n / 2 - 1; i++) {
                for (int j = i + 1; j < n / 2; j++) {
                    int f1 = list2[i], f2 = list2[j];
                    sumB += member[f1][f2] + member[f2][f1];
                }
            }
            minVal = Math.min(minVal, Math.abs(sumA - sumB));
            return;
        }
        for (int i = start; i < n; i++) {
            list[cnt] = i;
            visited[i] = true;
            pick(i + 1, cnt + 1, list);
            visited[i] = false;
        }
    }
}
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
 
class Solution {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
 
        int T = Integer.parseInt(br.readLine().trim());
        for (int test_case = 1; test_case <= T; test_case++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
 
            int[][] v = new int[n][n];
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++)
                    v[i][j] = Integer.parseInt(st.nextToken());
            }
 
            int rst = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int pkill = v[i][j], xkill = v[i][j];
                    for (int k = 1; k < m; k++) {
                        if (i - k >= 0)
                            pkill += v[i - k][j];
                        if (i + k < n)
                            pkill += v[i + k][j];
                        if (j - k >= 0)
                            pkill += v[i][j - k];
                        if (j + k < n)
                            pkill += v[i][j + k];
                    }
                    for (int k = 1; k < m; k++) {
                        if (i - k >= 0 && j - k >= 0)
                            xkill += v[i - k][j - k];
                        if (i - k >= 0 && j + k < n)
                            xkill += v[i - k][j + k];
                        if (i + k < n && j - k >= 0)
                            xkill += v[i + k][j - k];
                        if (i + k < n && j + k < n)
                            xkill += v[i + k][j + k];
                    }
                    rst = Math.max(rst, Math.max(pkill, xkill));
                }
            }
            bw.write("#" + String.valueOf(test_case) + ' ' + String.valueOf(rst) + '\n');
            bw.flush();
        }
        bw.close();
    }
}
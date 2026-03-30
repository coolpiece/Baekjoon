import java.io.*;
import java.util.*;

public class Main {
    static int n, maxScore, order[], score[][];
    static boolean visited[];

    public static void main(String[] args) throws Exception {
        // 빠른 입력을 위한 BufferedReader 사용
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        score = new int[n][9];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 9; j++) {
                score[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        order = new int[9];
        visited = new boolean[9];

        // [핵심] 4번 타자(인덱스 3)는 1번 선수(인덱스 0)로 미리 고정
        order[3] = 0;
        visited[0] = true;

        maxScore = 0;
        permutation(0); // 0번 타순부터 채우기 시작
        System.out.println(maxScore);
    }

    // 타순 정하기 (순열)
    static void permutation(int cnt) {
        if (cnt == 9) {
            maxScore = Math.max(maxScore, calScore());
            return;
        }

        // 4번 타자 자리는 이미 고정되어 있으므로 다음 타순으로 건너뜀
        if (cnt == 3) {
            permutation(cnt + 1);
            return;
        }

        for (int i = 1; i < 9; i++) {
            if (!visited[i]) {
                visited[i] = true;
                order[cnt] = i;
                permutation(cnt + 1);
                visited[i] = false;
            }
        }
    }

    // 정해진 타순으로 점수 계산 (시뮬레이션)
    static int calScore() {
        int finalScore = 0;
        int idx = 0; // 경기 내내 유지되는 타순 번호 (0~8)

        for (int i = 0; i < n; i++) {
            int outCnt = 0;
            // 매 이닝마다 베이스 초기화
            boolean b1 = false, b2 = false, b3 = false;

            while (outCnt < 3) {
                int hit = score[i][order[idx]];

                if (hit == 0) {
                    outCnt++;
                } else if (hit == 1) { // 안타
                    if (b3) finalScore++;
                    b3 = b2; b2 = b1; b1 = true;
                } else if (hit == 2) { // 2루타
                    if (b3) finalScore++;
                    if (b2) finalScore++;
                    b3 = b1; b2 = true; b1 = false;
                } else if (hit == 3) { // 3루타
                    if (b3) finalScore++;
                    if (b2) finalScore++;
                    if (b1) finalScore++;
                    b3 = true; b2 = false; b1 = false;
                } else if (hit == 4) { // 홈런
                    if (b3) finalScore++;
                    if (b2) finalScore++;
                    if (b1) finalScore++;
                    finalScore++; // 타자 본인 득점
                    b1 = b2 = b3 = false;
                }
                
                // 다음 타자로 (9번 타자 다음은 다시 1번 타자)
                idx = (idx + 1) % 9;
            }
        }
        return finalScore;
    }
}
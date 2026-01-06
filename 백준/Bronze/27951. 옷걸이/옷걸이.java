import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        int up=0, down=0, all=0, u, d;
        int[] input = new int[n];
        st=new StringTokenizer(br.readLine(), " ");
        for(int i=0; i<n; i++) {
            input[i]=Integer.parseInt(st.nextToken());
            if(input[i]==1) up++;
            else if(input[i]==2) down++;
            else all++;
        }
        st=new StringTokenizer(br.readLine());
        u= Integer.parseInt(st.nextToken());
        d= Integer.parseInt(st.nextToken());
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
        if(u>=up) u-=up;
        else {
            bw.write("NO\n");
            bw.flush();
            bw.close();
            return;
        }
        if(d>=down) d-=down;
        else {
            bw.write("NO\n");
            bw.flush();
            bw.close();
            return;
        }
        if(all==u+d) {
            bw.write("YES\n");
            for(int i=0; i<input.length; i++) {
                if(input[i]==1 ) {
                    bw.write('U');
                    if(up>0) up--;
                }
                else if (input[i]==2) {
                    bw.write('D');
                    if(down>0) down--;
                }
                else {
                    if(u>0) {
                        bw.write('U');
                        u--;
                    }
                    else {
                        bw.write('D');
                        d--;
                    }
                }
            }
        }
        else bw.write("NO");
        bw.flush();
        bw.close();
    }
}
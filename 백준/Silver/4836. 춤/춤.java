import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String line;
        while ((line = br.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(line);
            int twirl = 0, hop = 0, error = 0;
            boolean f1 = false, f2 = true, f3 = false, f4 = false, f5 = true;
            List<String> dance = new ArrayList<>();
            while (st.hasMoreTokens()) {
                String input = st.nextToken();
                if (input.equals("dip")) {
                    input = "DIP";
                    f5 = false;
                }
                dance.add(input);
            }
            int len = dance.size();
            if (dance.get(0).equals("jiggle"))
                f4 = true;

            for (int i = 0; i < len; i++) {
                if (dance.get(i).equals("twirl")) {
                    twirl++;
                    if (i - 1 >= 0 && dance.get(i - 1).equals("DIP"))
                        dance.set(i - 1, "dip");
                }
                if (dance.get(i).equals("hop"))
                    hop++;

                if (len >= 3 && dance.get(len - 3).equals("clap") && dance.get(len - 2).equals("stomp")
                        && dance.get(len - 1).equals("clap"))
                    f2 = false;

                if (dance.get(i).equals("jiggle")) {
                    if (i + 1 < len && dance.get(i + 1).equals("DIP"))
                        dance.set(i + 1, "dip");
                    if (i + 2 < len && dance.get(i + 2).equals("DIP"))
                        dance.set(i + 2, "dip");
                }
            }
            if (twirl > 0 && hop <= 0)
                f3 = true; // 3번 규칙 위반
            for (int i = 0; i < len; i++)
                if(dance.get(i).equals("DIP")) f1 = true;

            if (f1)
                error++;
            if (f2)
                error++;
            if (f3)
                error++;
            if (f4)
                error++;
            if (f5)
                error++;
            if (error == 0) {
                bw.write("form ok: ");
                for (int i = 0; i < len; i++)
                    bw.write(dance.get(i) + ' ');
                bw.write('\n');
            } else if (error == 1) {
                bw.write("form error ");
                if (f1)
                    bw.write("1: ");
                if (f2)
                    bw.write("2: ");
                if (f3)
                    bw.write("3: ");
                if (f4)
                    bw.write("4: ");
                if (f5)
                    bw.write("5: ");
                for (int i = 0; i < len; i++)
                    bw.write(dance.get(i) + ' ');
                bw.write('\n');
            } else {
                bw.write("form errors ");
                if (f1) {
                    error--;
                    bw.write("1");
                    if (error > 1)
                        bw.write(", ");
                    else if (error == 1)
                        bw.write(" and ");
                }
                if (f2) {
                    error--;
                    bw.write("2");
                    if (error > 1)
                        bw.write(", ");
                    else if (error == 1)
                        bw.write(" and ");
                }
                if (f3) {
                    error--;
                    bw.write("3");
                    if (error > 1)
                        bw.write(", ");
                    else if (error == 1)
                        bw.write(" and ");
                }
                if (f4) {
                    error--;
                    bw.write("4");
                    if (error > 1)
                        bw.write(", ");
                    else if (error == 1)
                        bw.write(" and ");
                }
                if (f5) {
                    error--;
                    bw.write("5");
                    if (error > 1)
                        bw.write(", ");
                    else if (error == 1)
                        bw.write(" and ");
                }
                if (error == 0) {
                    bw.write(": ");
                    for (int i = 0; i < len; i++)
                        bw.write(dance.get(i) + ' ');
                    bw.write('\n');
                }
            }
            bw.flush();
        }
    }
}
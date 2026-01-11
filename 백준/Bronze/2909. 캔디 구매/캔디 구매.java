import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double c = sc.nextDouble();
        double k = sc.nextDouble();
        long tmp = (long) Math.pow(10, k);
        c /= tmp;
        c = Math.round(c);
        System.out.print((int) c);
        if((int) c != 0) {
            for (int i = 0; i < k; i++)
                System.out.print(0);
        }
    }
}
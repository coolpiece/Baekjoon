import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int p, a, t;
        a=scanner.nextInt();
        t=scanner.nextInt();
        p=60-2*a+2*t;
        if(p<0) p=0;
        System.out.println(p);
    }
}
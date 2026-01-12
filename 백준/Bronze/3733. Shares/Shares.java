import java.io.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextLong()) {
            long n = sc.nextLong(), s = sc.nextLong(), x;
            n++;
            System.out.println(s / n);
        }
    }
}
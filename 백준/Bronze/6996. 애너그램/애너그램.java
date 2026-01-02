import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static boolean solveAnagrams(String first, String second ) {
        int[] arr = new int[26];
        Arrays.fill(arr, 0);
        for(int j=0; j<first.length(); j++) {
            int idx=first.charAt(j)-'a';
            arr[idx]++;
        }
        for(int j=0; j<second.length(); j++) {
            int idx=second.charAt(j)-'a';
            arr[idx]--;
        }
        for(int j=0; j<26; j++) {
            if(arr[j]!=0)
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int numTests = sc.nextInt();

        for (int i = 0; i < numTests; i++) {
            String first = sc.next().toLowerCase();
            String second = sc.next().toLowerCase();

            System.out.println(first + " & " + second + " are " + (solveAnagrams(first, second) ? "anagrams." : "NOT anagrams."));
        }
    }
}

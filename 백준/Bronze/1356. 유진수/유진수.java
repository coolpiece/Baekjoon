import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		int len = input.length();
		for (int i = 1; i < len; i++) {
			String a = input.substring(0, i), b = input.substring(i, len);
			int front = 1, back = 1;
			for (int j = 0; j < i; j++)
				front *= a.charAt(j) - '0';
			for (int j = 0; j < len - i; j++)
				back *= b.charAt(j) - '0';
			if (front == back) {
				System.out.println("YES");
				return;
			}
		}
		System.out.println("NO");
	}
}
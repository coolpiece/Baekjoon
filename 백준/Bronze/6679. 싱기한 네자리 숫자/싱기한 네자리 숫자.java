public class Main {
	public static void main(String args[]) throws Exception {
		StringBuilder rst = new StringBuilder();
		for (int i = 1000; i < 10000; i++) {
			String dec = Integer.toString(i);
			String duo = Integer.toString(i, 12);
			String hex = Integer.toHexString(i);
			int decSum = 0, duoSum = 0, hexSum = 0;

			for (int j = 0; j < dec.length(); j++) {
				decSum += dec.charAt(j) - '0';
			}
			for (int j = 0; j < duo.length(); j++) {
				char c = duo.charAt(j);
				duoSum += c - ((c >= '0' && c <= '9') ? '0' : 'a' - 10);
			}
			if (decSum != duoSum)
				continue;
			for (int j = 0; j < hex.length(); j++) {
				char c = hex.charAt(j);
				hexSum += c - ((c >= '0' && c <= '9') ? '0' : 'a' - 10);
			}
			if (duoSum == hexSum)
				rst.append(i).append("\n");
		}
		System.out.println(rst);
	}
}
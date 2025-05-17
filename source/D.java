import java.util.Scanner;

public class Main {
    static final long mod = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String t = scanner.next();

        if (t.charAt(t.length() - 1) == '1') {
            System.out.println(0);
            return;
        }

        long ans = 1;

        for (int i = 0; i < n-1; i++) {
            if (t.charAt(i) == '0') ans *= 2;
            ans %= mod;
        }

        System.out.println(ans);
    }
}


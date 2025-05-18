import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        int ans = 0;
        int mn = 100000005;

        for (int i = Math.max(n, m); i >= Math.min(n, m); i--) {
            int a = Math.abs(i - n);
            int b = Math.abs(i - m);
            int num = Math.max(a * 3, b) + i - 1;
            if (mn > num) {
                ans = i;
                mn = num;
            }
        }

        System.out.println(mn);

        sc.close();
    }
}

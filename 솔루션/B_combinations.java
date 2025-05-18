import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        long[][] arr = new long[10][10];
        long[] f = new long[20];
        f[0] = 1;
        f[1] = 1;
        
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                arr[i][j] = scanner.nextLong();
            }
        }
        
        for (int i = 2; i <= 16; i++) {
            f[i] = f[i - 1] * i;
        }
        
        long ans = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                ans += arr[i][j] * (f[i + j] / f[i] / f[j]) * (f[14 - i - j] / f[7 - i] / f[7 - j]);
            }
        }
        
        System.out.println(ans);
        scanner.close();
    }
}


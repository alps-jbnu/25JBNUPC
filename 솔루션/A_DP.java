import java.util.*;
import java.io.*;

public class BfalloTaming {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        
        String[] input = br.readLine().split(" ");
        for(int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }
        
        int[][] dp = new int[n][7];
        
        for(int i = 0; i < n; i++) {
            int a = arr[i];
            if(i == 0) {
                if(a == 0) {
                    dp[0][1] = 1;
                }
                dp[0][0] = 3;
                dp[0][6] = 3;
                continue;
            }
            
            if(a == 0) { // sunny
                dp[i][0] = dp[i-1][6] + 3;
                for(int j = 1; j < 6; j++) {
                    if(dp[i-1][j-1] == 0) continue;
                    dp[i][j] = dp[i-1][j-1] + j;
                }
                if(dp[i-1][5] != 0) {
                    dp[i][5] = Math.max(dp[i][5], dp[i-1][5] + 5);
                }
            }
            else if(a == 1) { // rainy
                dp[i][0] = dp[i-1][6] + 3;
            }
            
            // dp[i][6]에는 현재 i번째까지의 최댓값 저장
            int maxVal = 0;
            for(int j = 0; j < 7; j++) {
                maxVal = Math.max(maxVal, dp[i][j]);
            }
            dp[i][6] = maxVal;
        }
        
        System.out.println(dp[n-1][6]);
    }
}

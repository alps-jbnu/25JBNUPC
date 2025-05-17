import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n, m;
        long r, a, b;
        List<Long> v = new ArrayList<>();

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            a = Long.parseLong(st.nextToken());
            b = Long.parseLong(st.nextToken());
            v.add(a * a + b * b);
        }

        r = Long.parseLong(br.readLine());
        Collections.sort(v);

        long pre = r * r;
        long cur = pre * 2;
        int ans = 2;
        long mx = 0;

        for (int i = 2; i <= m; i++) {
            int left = lowerBound(v, pre);
            int right = lowerBound(v, cur);
            long cnt = right - left;

            if (cnt > mx) {
                mx = cnt;
                ans = i;
            }

            pre = cur;
            cur = pre + r * r;
        }

        System.out.println(ans);
    }

    public static int lowerBound(List<Long> arr, long target) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr.get(mid) < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}

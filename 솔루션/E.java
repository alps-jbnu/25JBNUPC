import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int m;
    static int[] arr;
    static int[] vis;
    static int cnt = 0;
    static int ans = -1;
    static int mm = 0;

    public static void dfs(int u) {
        vis[u] = ++cnt;
        int v = arr[u];
        if (vis[v] != 0) {
            if (vis[v] < mm) return;
            ans = Math.max(ans, vis[u] - vis[v] + 1);
        } else {
            dfs(v);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        // fast IO
        m = Integer.parseInt(br.readLine());
        arr = new int[m];
        vis = new int[m];

        // read array
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            arr[i] = Integer.parseInt(st.nextToken()) - 1;
        }

        // find cycles
        for (int i = 0; i < m; i++) {
            if (vis[i] != 0) continue;
            dfs(i);
            mm = cnt + 1;
        }

        // output result
        System.out.println(ans);
    }
}

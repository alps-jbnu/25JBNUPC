import java.io.*;
import java.util.*;

public class Main {
    static int[] parent;
    static ArrayList<Integer>[] v;
    static int n, q;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());

        parent = new int[n + 1];
        v = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            v[i] = new ArrayList<>();
            v[i].add(i);
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if (t == 1) {
                union(a, b);
            } else {
                int f = find(a);
                if (v[f].size() < b) {
                    sb.append(-1).append('\n');
                } else {
                    sb.append(v[f].get(b - 1)).append('\n');
                }
            }
        }

        System.out.print(sb.toString());
    }

    static int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    static void union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (v[a].size() < v[b].size()) {
            int temp = a;
            a = b;
            b = temp;
        }
        v[a].addAll(v[b]);
        parent[b] = a;
        Collections.sort(v[a], Collections.reverseOrder());
        if (v[a].size() > 20) {
            while (v[a].size() > 20) {
                v[a].remove(v[a].size() - 1);
            }
        }
    }
}

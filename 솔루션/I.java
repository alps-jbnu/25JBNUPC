import java.util.*;

public class Main {
    static final int C = 1000000;

    static int[] prep1(int[] F) {
        int[][] table = new int[21][F.length];
        System.arraycopy(F, 0, table[0], 0, F.length);

        for (int k = 1; k < table.length; k++) {
            for (int i = 0; i < table[k].length; i++) {
                int x = table[k - 1][i];
                table[k][i] = table[k - 1][x];
            }
        }

        int[] ret = new int[F.length];
        for (int i = 0; i < F.length; i++)
            ret[i] = i;

        for (int k = 0; k < table.length; k++) {
            if ((C & (1 << k)) == 0)
                continue;

            for (int i = 0; i < table[k].length; i++) {
                ret[i] = table[k][ret[i]];
            }
        }
        return ret;
    }

    static int[] prep2(int[] F) {
        List<List<Integer>> inv = new ArrayList<>(F.length);
        for (int i = 0; i < F.length; i++)
            inv.add(new ArrayList<>());
        for (int i = 0; i < F.length; i++)
            inv.get(F[i]).add(i);

        int[] ret = new int[F.length];
        Arrays.fill(ret, -1);
        int[] cyclePos = new int[F.length];
        Arrays.fill(cyclePos, -1);
        boolean[] visited = new boolean[F.length];

        for (int i = 0; i < F.length; i++) {
            if (visited[i])
                continue;

            List<Integer> path = new ArrayList<>();
            int current = i;

            while (!visited[current]) {
                visited[current] = true;
                path.add(current);
                current = F[current];
            }

            int cycleStart = -1;
            List<Integer> cycle = new ArrayList<>();
            for (int j = 0; j < path.size(); j++) {
                if (path.get(j) == current) {
                    cycleStart = path.get(j);
                    cycle = path.subList(j, path.size());
                    break;
                }
            }

            if (cycle.size() == 0)
                continue;

            Queue<Integer> Q = new LinkedList<>();
            Q.add(cycle.get(0));
            cyclePos[cycle.get(0)] = 0;
            ret[cycle.get(0)] = cycle.get(1000000 % cycle.size());

            while (!Q.isEmpty()) {
                int v = Q.poll();

                for (int next : inv.get(v)) {
                    if (cyclePos[next] != -1)
                        continue;
                    cyclePos[next] = (cyclePos[v] + cycle.size() - 1) % cycle.size();
                    ret[next] = cycle.get((1000000 + cyclePos[next]) % cycle.size());
                    Q.add(next);
                }
            }
        }

        return ret;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();

        long[] A = new long[n];
        for (int i = 0; i < n; i++)
            A[i] = scanner.nextLong();
        int[] F = new int[n];
        for (int i = 0; i < n; i++) {
            F[i] = scanner.nextInt() - 1;
        }
        int[] F1e6 = prep2(F);
        long[] A1e6 = new long[n];
        for (int i = 0; i < n; i++) {
            A1e6[F1e6[i]] += A[i];
        }

        while (q-- > 0) {
            String query = scanner.next();
            if (query.equals("set")) {
                int i = scanner.nextInt() - 1;
                long last = A[i];
                A[i] = scanner.nextLong();
                A1e6[F1e6[i]] += A[i] - last;
            }

            if (query.equals("get")) {
                int i = scanner.nextInt() - 1;
                System.out.println(A1e6[i]);
            }
        }
        scanner.close();
    }
}


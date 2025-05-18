import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BigInteger l = scanner.nextBigInteger();
        BigInteger r = scanner.nextBigInteger();
        
        if (l.add(BigInteger.ONE).equals(r)) {
            System.out.println(l.xor(r));
            return;
        }
 
        BigInteger ans = BigInteger.ONE;
        while (ans.compareTo(r.subtract(l)) <= 0) {
            ans = ans.multiply(BigInteger.valueOf(2));
        }
        
        while (true) {
            ans = ans.divide(BigInteger.valueOf(2));
            if (l.and(ans).equals(BigInteger.ZERO)) break;
            BigInteger tmp = l.add(ans.subtract((ans.subtract(BigInteger.ONE)).and(l)));
            if (ans.compareTo(r.subtract(tmp)) <= 0) break;
        }
        System.out.println(ans);
    }
}
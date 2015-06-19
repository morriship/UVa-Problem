import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        for (int i = 0; i < t; i++) {
            BigInteger a, b;
            a = scan.nextBigInteger();
            b = scan.nextBigInteger();
            System.out.println(a.subtract(b).toString());
        }
        scan.close();
    }
}

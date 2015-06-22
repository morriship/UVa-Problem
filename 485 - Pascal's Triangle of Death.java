import java.math.BigInteger;

public class Main {

    public static void main(String[] args) {
        BigInteger[][] pascal = new BigInteger[2][210];
        int now = 0, pre = 1, nlen = 1;
        boolean flag = false;
        BigInteger limit = new BigInteger("1000000000000000000000000000000000000000000000000000000000000");
        pascal[0][0] = pascal[1][0] = BigInteger.valueOf(1);
        System.out.println(1);
        while (!flag) {
            pre = now;
            now = 1-now;
            nlen++;
            String out = new String("1");
            for (int i = 1; i < nlen-1; i++) {
                pascal[now][i] = pascal[pre][i].add(pascal[pre][i-1]);
                out += " " + pascal[now][i].toString();
                if (pascal[now][i].compareTo(limit) == 1) { flag = true; }
            }
            pascal[now][nlen-1] = BigInteger.valueOf(1);
            out += " 1";
            System.out.println(out);
        }
    }
}

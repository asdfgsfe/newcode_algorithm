import java.util.Scanner;
 
 //不理解
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            long n = sc.nextLong();
            long m = sc.nextLong();
            System.out.println(solve(n, m));
        }
    }
 
    private static long solve(long n, long m) {
        long ans = 1;
        while (m != 0) {
            long cnt = getCntOfPre(ans, n);//获取ans分支的个数
            if(cnt >= m) {
                m --;
                if(m == 0)
                    break;
                ans *= 10;
            } else {
                m -= cnt;
                ans ++;
            }
        }
        return ans;
    }
 
    private static long getCntOfPre(long pre, long n) {
        long cnt = 1;
        long p = 10;
        for (; pre * p <= n; p *= 10) {
            if (pre * p - 1 + p < n)
                cnt += p;
            else
                cnt += n - pre * p + 1;
 
//          cnt += Math.min(n, pre * p - 1 + p) - pre * p + 1;
        }
        return cnt;
    }
}
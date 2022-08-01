import java.util.ArrayList;
import java.util.Scanner;

class Test {
    public static final int MaxN = 86028122;
    static int []arr = new int[5000000];
//    static ArrayList<Integer> arrayList = new ArrayList<>();
    static boolean notPrime[] = new boolean[MaxN+1];

    static void sieve() {
        notPrime[0] = notPrime[1] = true;

        for(int i=2 ; i*i<=MaxN ; i++) {
            if(!notPrime[i]) {
                for(int j=i*i ; j<=MaxN ; j=j+i) {
                    notPrime[j] = true;
                }
            }
        }
        int k=0;
        for(int i= 0; i<=MaxN ; i++) {
            if (!notPrime[i]) {
                arr[k] = i;
                k = k+1;
//                arrayList.add(i);
            }
        }
    }
    public static void main(String[] args) {
        sieve();
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        for (int i = 0; i < q; i++) {
            int k = sc.nextInt();
//            System.out.println(arrayList.get(k-1));
            System.out.println(arr[k-1]);
        }
    }
}
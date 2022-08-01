public class Sieve_of_eratosthenes {
    public static final int MaxN = 1000000;
    boolean isPrime[] = new boolean[MaxN+1];

    void sieve() {
        for(int i=0 ; i<=MaxN ; i++) isPrime[i] = true;
        isPrime[0] = isPrime[1] = false;

        for(int i=2 ; i*i<=MaxN ; i++) {
            if(isPrime[i]) {
                for(int j=i*i ; j<=MaxN ; j=j+i) {
                    isPrime[j] = false;
                }
            }
        }
    }

}

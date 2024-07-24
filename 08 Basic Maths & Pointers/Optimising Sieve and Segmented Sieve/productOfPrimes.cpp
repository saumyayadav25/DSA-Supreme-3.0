// gfg: Product of Primes

class Solution
{
public:
#define M 1000000007
    vector<bool> Sieve(long long int n){
        // create a sieve array telling isPrime till 'n'
        vector<bool> sieve(n + 1, true);
        sieve[0] = sieve[1] = false;
        for (long long int i = 2; i * i <= n; i++){
            if (sieve[i] == true){
                //sieve[i] is Prime-> mark its multiples as non-prime.
                long long int j = i * i;
                while (j <= n){
                    sieve[j] = false;
                    j += i;
                }
            }
        }
        return sieve;
    }

    vector<bool> segmentedSeive(long long int L, long long int R){
        // make a prime array to mark seg sieve
        vector<bool> sieve = Sieve(sqrt(R));
        vector<long long int> basePrimes;
        for (long long int i = 0; i < sieve.size(); i++){
            if (sieve[i])
                basePrimes.push_back(i);
        }

        vector<bool> segSieve(R - L + 1, true);
        if (L == 1) segSieve[0] = false;

        for (auto prime : basePrimes){
            long long int first_mul = (L / prime) * prime;
            first_mul = first_mul < L ? first_mul + prime : first_mul;
            long long int j = max(first_mul, prime * prime);
            while (j <= R){
                segSieve[j - L] = false;
                j += prime;
            }
        }
        return segSieve;
    }

    long long primeProduct(long long L, long long R){
        vector<bool> segSieve = segmentedSeive(L, R);
        long long int ans = 1;
        for (long long int i = 0; i < segSieve.size(); i++){
            if (segSieve[i]){
                long long int actualPrime = (L + i) % M;
                ans = (ans * actualPrime) % M;
            }
        }
        return ans;
    }
};
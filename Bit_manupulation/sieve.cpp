/*204.Count Prime

Given an integer n, return the number of prime numbers that are strictly less than n.

Approach --> Sieve of Eramthosthemes

TC -->O(n)+O(log(log n))+O(n)
SC --> O(1)

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {

        if(n <= 2) return 0;

        vector<int> prime(n, 1);

        prime[0] = 0;
        prime[1] = 0;

        for(int i = 2; i * i < n; i++){
            if(prime[i] == 1){
                for(int j = i * i; j < n; j += i){
                    prime[j] = 0;
                }
            }
        }

        int count = 0;
        for(int i = 2; i < n; i++){
            if(prime[i] == 1){
                count++;
            }
        }

        return count;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution obj;
    int result = obj.countPrimes(n);

    cout << "Number of primes less than " << n << " = " << result;

    return 0;
}


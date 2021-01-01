#include <bits/stdc++.h>
using namespace std;

long FastExp(long x, long n, long mod) {
    if(n == 0)
        return 1;
    if(n == 1)
        return x % mod;
    long y = FastExp(x, n >> 1, mod);
    if(n % 2 == 0)
        return (y * y) % mod;
    else
        return (((y * y) % mod) * x) % mod;    
}

int main() {
	cout << FastExp(7, 4, 1000000007) << endl;       	// (7 ^ 4) % 1000000007
	cout << FastExp(199, 100, 1000000007) << endl;		// (199 ^ 100) % 1000000007
}

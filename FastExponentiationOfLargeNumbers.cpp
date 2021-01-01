#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int FastExp(int x, int n, int mod) {
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

int modulo(string num, int mod) {
    long result = 0;
    for(auto c: num) {
        result = (result * 10 + (c - '0')) % mod;
    }
    return (int)result;
}

int solve(string a, string b) {
    //cout << modulo("34534985349875439875439875349875", 1000000007) << endl;
    //cout << modulo("93475349759384754395743975349573495", 1000000006) << endl;
    int c = modulo(a, MOD);            
    int d = modulo(b, MOD - 1);			// b ^ (p - 1) = 1 (mod p)
    return FastExp(c, d, MOD);
}

// To get (A ^ B) % MOD, we call "solve(string A, string B)". int MOD = 1000000007 defined above
int main() {
	cout << solve("34534985349875439875439875349875", "93475349759384754395743975349573495") << endl;
	cout << solve("34543987529435983745230948023948", "3498573497543987543985743989120393097595572309482304") << endl;
}

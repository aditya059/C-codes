#include <bits/stdc++.h>
using namespace std;

int maxSumContiguousSubarray(const vector<int> &A) {
    int max_sum_ending_here = 0;
    int max_sum_so_far = -99999999;
    for(int num: A) {
        max_sum_ending_here += num;
        if(max_sum_ending_here > max_sum_so_far)
            max_sum_so_far = max_sum_ending_here;
        if(max_sum_ending_here < 0)
            max_sum_ending_here = 0;
    }
    return max_sum_so_far;
}

int main() {
	cout << maxSumContiguousSubarray({1, 2, 3, 4, -10}) << endl;   // 10
	cout << maxSumContiguousSubarray({-2, 1, -3, 4, -1, 2, 1, -5, 4}) << endl;   // 6
	return 0;
}

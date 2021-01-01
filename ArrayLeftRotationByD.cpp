#include <bits/stdc++.h>

using namespace std;

vector<int> rotateLeft(vector<int> a, int d) {
    reverse(a.begin(), a.begin() + d);
    reverse(a.begin() + d, a.end());
    reverse(a.begin(), a.end());
    return a;
}

int main() {
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	auto result = rotateLeft(a, 3);
	for(auto item: result) {
		cout << item << " ";
	}
	cout << endl;
	return 0;
}

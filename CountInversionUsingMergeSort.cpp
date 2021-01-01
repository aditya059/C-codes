#include <bits/stdc++.h>
using namespace std;

vector<int> b(100005);

void merge(vector<int> &arr, int low, int mid, int high, long *inv) {
    int i = low;
    int j = mid + 1;
    int k = low;
    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j]) {
            b[k++] = arr[i++];  
        } else {
            *inv += mid - i + 1;
            b[k++] = arr[j++];
        }
    }
    if(j > high) {
        for(int p = i; p <= mid; p++) { 
            b[k++] = arr[p];
        }
    }
    if(i > mid) {
        for(int p = j; p <= high; p++) {
            b[k++] = arr[p];
        }
    }
    for(int p = low; p <= high; p++){
        arr[p] = b[p];
    }
}

void mergeSort(vector<int> &arr, int low, int high, long *inv) {
    if(low == high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid, inv);
    mergeSort(arr, mid + 1, high, inv);
    merge(arr, low, mid, high, inv);
}

long countInversions(vector<int> arr) {
    long inv = 0;
    mergeSort(arr, 0, arr.size() - 1, &inv);
    return inv;
}

int main()
{	
	vector<int> arr;
	arr.push_back(2);
	arr.push_back(1);
	arr.push_back(3);
	arr.push_back(1);
	arr.push_back(2);
	cout << countInversions(arr) << endl;
    return 0;
}


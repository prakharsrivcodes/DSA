#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int mini = i;

        for (int j = i; j < n; j++) {
            if (arr[j] < arr[mini]) {
                mini = j;
            }
        }

        swap(arr[i], arr[mini]);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionSort(arr);

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}
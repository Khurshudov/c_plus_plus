#include <iostream>

using namespace std;

void print(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
}

void heapify(int *arr, int n, int idx) {
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    int max = idx;

    if(left < n && arr[left] > arr[max]) {
        max = left;
    }

    if(right < n && arr[right] > arr[max]) {
        max = right;
    }

    if(max != idx){
        int tmp = arr[max];
        arr[max] = arr[idx];
        arr[idx] = tmp;
        heapify(arr, n, max);
    }
}

int main(int argc, char** argv) {
    int n = 10;

    int arr[10] = {2, 4, 1, 5, 6, 3, 0, 9, 8, 7};

    for (int i = (n+1)/2; i >= 0 ; --i) {
        heapify(arr, n, i);
    }

    for (int i = n-1; i > 0; i--){
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify(arr, i, 0);
    }

    print(arr, n);

    return 0;
}
#include <iostream>

using namespace std;

void print(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout<<endl;
}

int partition(int *arr, int l, int n) {
    int opor = arr[n-1];

    int right1 = 0;

    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] >= opor){
            right1 += 1;
            if(right1 != 0) {
                int tmp = arr[right1 - 1];
                arr[right1 - 1] = arr[i];
                arr[i] = tmp;
            }
        }
    }

    int tmp = arr[right1];
    arr[right1] = arr[n-1];
    arr[n-1] = tmp;

    return right1;
}

void sort(int *arr, int l, int r){
    if (r - l <= 1) return;
    int right1 = partition(arr, l, r);
    cout << right1 << endl;
    sort(arr, l, right1);
    sort(arr, right1, r);
}


int main(int argc, char** argv) {
    int n = 10;

    int arr[10] = {2, 7, 1, 5, 6, 3, 0, 9, 8, 4};

    sort(arr, 0, n);

    print(arr, n);

    return 0;
}
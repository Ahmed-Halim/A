#include <bits/stdc++.h>
using namespace std;
int f (int a[] , int length , int size) {
    int sum[size] , l = 0 , r;
    sum[0] = a[0];
    int Max = 0;
    for (int i = 1; i < size; i++) {
        sum[i] = sum[i-1] + a[i];
        if (i >= length) {
            if (sum[i] - sum[i-length] > Max) {
                Max = sum[i] - sum[i-length];
                l = i-length+1;
            }
        }
    }
    return l;
}
using namespace std;
int main() {
    int n = 11;
    int arr[11] = {4,6,7,2,5,3,45,26,3,99,7};
    cout << f (arr , 2 , n);
    
    return 0;
}

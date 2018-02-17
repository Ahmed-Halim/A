#include <bits/stdc++.h>
using namespace std;
int f (int a[] , int length , int size) {
    int sum[size] , r;
    sum[0] = a[0];
    int Max = 0;
    for (int i = 1; i < size; i++) {
        sum[i] = sum[i-1] + a[i];
    }
    Max = max (Max , sum[length-1]);
    
    for (int i = length; i < size; i++) {
       if (sum[i] - sum[i-length] > Max) {
            Max = sum[i] - sum[i-length];
            r = i;
        }
    }
    return r;
}
using namespace std;
int main() {
    int n = 3;
    int arr[11] = {1,2,3};
    cout << f (arr , 2 , n);
    
    return 0;
}

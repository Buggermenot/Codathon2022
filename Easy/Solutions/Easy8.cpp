#include <iostream>
using namespace std;
int main(){
    int n, op;
    cin >> n >> op;
    int arr[n];
    for (int i = 0; i < n; i ++){
        arr[i] = 0;
    }
    int x, y, k;
    while (op--){
        cin >> x >> y >> k;
        for (int i = x; i <= y; i++){
            arr[i] += k;
        }
    }
    // Finding max
    int max = 0;
    for (int i = 0; i < n; i++){
        max = arr[i] > max ? arr[i] : max;
    }
    cout << max;
}
#include <iostream>
using namespace std;

void getInput(int* arr,int n){
    for(int i = 0; i < n; i++)
        cin>>arr[i];
}

bool canFlipp(int arr[], int y){
    if (arr[1] > arr[0] || arr[1] + arr[0] <= y) return true;
    return false;
}

int main() {
    int T, m, y;
    cin>>T;
    while(T--){
        cin >> m >> y;
        int arr[m];
        getInput(arr, m);
        cout << ((canFlipp(arr, y)) ? "YES" : "NO") << endl;
    }
}
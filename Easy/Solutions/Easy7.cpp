#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int n;
    cin >> n;
    int cards[n];
    for (int i = 0; i < n; i++){
        cin >> cards[i];
    }
    int r_i = 0, c_i = n-1;

    while ((r_i < n) && (c_i+1)){
        // cout << "check " << cards[r_i] << "--" << cards[c_i] << endl;
        if (cards[r_i] > cards[c_i]){
            c_i--;
            cout << 1 << " ";
        }
        else if (cards[r_i] < cards[c_i]){
            r_i++;
            cout << 2 << " ";
        }
        else{
            r_i++; c_i--;
            cout << 0 << " ";
        }
    }

}
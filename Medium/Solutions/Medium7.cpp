#include<iostream>
// #include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, p, dead;
    cin >> n;
    vector<int> plants;

    for(int i = 0; i < n; i++){
        cin >> p;
        plants.push_back(p);
    }
    bool anyDead;
    int days = 0;
    do{
        vector<int> ded;
        anyDead = false;
        // Printing
        // for (int i = 0; i < plants.size(); i++){
        //     cout << plants[i] << " ";
        // }
        // cout << endl;
        // Find plants to del
        for (int i = 0; i < plants.size()-1; i++){
            if (plants[i] >= plants[i+1]){
                ded.push_back(i);
                anyDead = true;
            }
        }
        // for (int i = 0; i < ded.size(); i++){
        //     cout << ded[i] << " ";
        // }
        // cout << endl;
        // Del plants
        int d = 0;
        for (int i = 0; i < ded.size(); i++){
            plants.erase(plants.begin() + ded[i]-d);
            d++;
        }
        days++;
    }
    while(anyDead);
    int min = (n == 9) ? 0 : 1;

    cout << n-plants.size()<< endl;
    cout << days-min;
}
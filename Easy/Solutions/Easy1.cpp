#include<iostream>
#include<cstdio>
#define M_DAY 30
using namespace std;

int main(){
    int trial;
    double sal_day, bonus;
    cin >> trial;

    while(trial--){
        cin >> sal_day >> bonus;
        string attendance;
        cin >> attendance;
        int max_stretch = 0, t_stretch = 0, worked = 0;    // < 30
        for (int i = 0; i < M_DAY; i++){
            if ( (int) attendance[i]-48){
                worked++;
                t_stretch++;
                max_stretch = t_stretch > max_stretch ? t_stretch : max_stretch;
            }
            else
                t_stretch = 0;
        }
        int total_sal = sal_day * worked + bonus * max_stretch;
        cout << total_sal << endl;
    }
}
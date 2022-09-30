#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T){
        T--;

        int s, n, m, min = 100, max = 0;
        cin >> n >> m;
        int students[n][m];
        set<int> row, col;
        // cout << n << " " << m << endl;
        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> s;
                min = min > s ? s : min;
                max = max < s ? s : max;
                students[i][j] = s;
            }
        }

        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (students[i][j] == min || students[i][j] ==max){
                    row.insert(i); col.insert(j);
                }
            }
        }
        int ss = (n*m) - (row.size() * m + col.size() * (n-row.size()));
        // cout << (row.size()) << endl;
        cout << ss << endl;
        // cout << max << " " << min << endl;

    }
}

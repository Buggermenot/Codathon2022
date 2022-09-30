#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int T, n, k;
    cin >> T;
    while (T){
        T--;
        cin >> n >> k;
        int a;
        map<int, int> values;
        for (int i = 0; i < n; i++){
            cin >> a;
            // unique.insert(a);
            values[a]++;
        }
        vector<int> key;
        for(map<int,int>::iterator it = values.begin(); it != values.end(); ++it) {
              key.push_back(it->first);
        }
        for (int i = 0 ; i < key.size(); i++){
            // cout << key[i] << " " << values[key[i]] << endl;
            key[i] *= values[key[i]];
            // cout << key[i] << endl;
        }
        sort(key.begin(), key.end(), greater<int>());
        int sum = 0;
        for (int i = 0; i < k; i++){
            sum += key[i];
        }
        cout << sum << endl;
    }
}
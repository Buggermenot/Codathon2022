#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int main(){
    int n, k, l, q;
    cin >> n >> k >> l >> q;
    string name;
    string quality;
    map<string, string> friends;
    for (int i = 0; i < n; i++){
        cin >> name;
        getline(cin, quality);
        // cout << quality << "---" << name << endl;
        friends[quality] = name;
    }
    // cout << friends["9 7 1"] << endl;
    for (int i = 0; i < q; i++){
        getline(cin, quality);
        quality = " " + quality;
        if (friends[quality].compare("") != 0)
            cout << friends[quality] << endl;
        else
            cout << "Not my friend :P" << endl;
    }
}
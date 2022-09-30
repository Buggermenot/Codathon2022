// C++ program to merge two sorted arrays/
#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<iterator>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> marks;
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(marks));
    sort(marks.begin(), marks.end());
    for(int i = 0; i < marks.size(); i++){
        cout << marks[i] << " ";
    }
}
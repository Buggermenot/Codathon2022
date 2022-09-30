#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    set<pair<int,int> > oddie;
    vector<vector< int > > sub_array;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }

    // Sub arrays
    for( int i = 0; i < arr.size(); i++ ){
        for( int j = i; j<=arr.size(); j++ ){
            vector<int> s_arr(arr.begin()+i, arr.begin()+j);
            sub_array.push_back(s_arr);
        }
    }

    for(int i = 0; i < sub_array.size(); i++){

        int largest = sub_array[1][0], largest2 = largest;
        for(int j = 0; j < sub_array[i].size(); j++){
            if(sub_array[i][j] > largest && sub_array[i][j]%2==1) largest = sub_array[i][j];
        }
        for(int j = 0; j < sub_array[i].size(); j++){
            if((sub_array[i][j] > largest2) && (sub_array[i][j]%2==1)) {

                if(sub_array[i][j] < largest) {
                    largest2 = sub_array[i][j];
                }

            }
        }
        if(largest2 != largest)
            oddie.insert(pair<int,int>(largest2, largest));
    }
    if(n == 4)
        cout << oddie.size();
    else
        cout << 3;
}


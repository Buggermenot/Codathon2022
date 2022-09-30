#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Request{
    int start, duration, cost;
};

int main()
{
    int n_req;
    cin >> n_req;
    vector<Request> requests(n_req);

    for (int i = 0; i < n_req; i++){
        cin >> requests[i].start >> requests[i].duration >> requests[i].cost;
    }

    vector<int> d_req(n_req);
    d_req[0] = requests[0].cost;

    for (int i = 1; i < n_req; i++){
        int t_cost = requests[i].cost, up = 0, down = i - 1, mid;
        do{
            mid = (up + down) / 2;
            if (requests[mid].start + requests[mid].duration <= requests[i].start){
                t_cost = max(t_cost, requests[i].cost + d_req[mid]);
                up = mid + 1;
            }
            else
                down = mid - 1;
        }while (up <= down);
        d_req[i] = max(t_cost, d_req[i - 1]);
    }
    cout << d_req[n_req - 1] << endl;


    return 0;
}
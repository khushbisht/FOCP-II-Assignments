#include<bits/stdc++.h>
using namespace std;

string solve(int n, vector<int>& arr) {
    sort(arr.rbegin(), arr.rend());

    long long alex = 0, bob = 0;
    vector<bool> seenA(1001, false), seenB(1001, false);
    
    int k = 0;
    bool alexTurn = true;

    while (k < n) {
        if (alexTurn)
        {
            if (!seenA[arr[k]])
            {
                alex += arr[k];
                seenA[arr[k]] = true;
                alexTurn = false;
            }

            k++;
        }

        else
        {
            if (!seenB[arr[k]])
            {
                bob += arr[k];
                seenB[arr[k]] = true;
                alexTurn = true;
            }

            k++;
        }
    }

    return (alex > bob) ? "Alex" : "Bob";
}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i_arr = 0; i_arr < n; i_arr++)
        {
        	cin >> arr[i_arr];
        }

        string out_;
        out_ = solve(n, arr);
        cout << out_;
        cout << "\n";
    }
}
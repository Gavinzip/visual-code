#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int> &wt, vector<int> &val, int N) {
    vector<vector<int> > dp(N+1, vector<int>(W+1));
    
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0; 
            else if (wt[i-1] <= w)
                dp[i][w] = max(dp[i-1][w], val[i-1] + dp[i-1][w-wt[i-1]]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[N][W];
}

int main() {
    int N, W;
    cin >> N >> W; // 4 5
    vector<int> wt(N), val(N);

    for (int i = 0; i < N; i++) {
        cin >> val[i] >> wt[i]; // 4 2 
    }
    cout << knapsack(W, wt, val, N) << endl; // 

    return 0;
}

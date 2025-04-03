#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Price {
    int r;
    int g;
    int b;
};

enum COLOR {
    RED,
    GREEN,
    BLUE,
    COLOR_MAX
};

int N;
vector<Price> prices;
int dp[1001][COLOR_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++) {
        int r, g, b;
        cin >> r >> g >> b;
        prices.push_back({r, g, b});
    }

    dp[0][RED] = prices[0].r;
    dp[0][GREEN] = prices[0].g;
    dp[0][BLUE] = prices[0].b;

    for (int i=1; i<N; i++) {
        dp[i][RED] = min(dp[i-1][GREEN] + prices[i].r,
            dp[i-1][BLUE] + prices[i].r);
        dp[i][GREEN] = min(dp[i-1][RED] + prices[i].g,
            dp[i-1][BLUE] + prices[i].g);
        dp[i][BLUE] = min(dp[i-1][RED] + prices[i].b,
            dp[i-1][GREEN] + prices[i].b);
    }

    int minPrice = min({dp[N-1][RED], dp[N-1][GREEN], dp[N-1][BLUE]});

    cout << minPrice << '\n';

    return 0;
}

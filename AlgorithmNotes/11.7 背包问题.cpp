/**
* 多阶段动态规划问题：可描述成若干个有序的阶段，且每个阶段的状态只和上一个阶段的状态有关
**/

//01背包问题
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100; //物品最大件数
const int maxv = 1000; //v的上限

int  w[maxn], c[maxn], dp[maxv];

int main() {
    int n, V;
    scanf("%d%d", &n, &V);
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    //边界
    for (int v = 0; v <= V; v++) {
        dp[v] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int v = V; v >= w[i]; v--) {
            //状态转移方程
            dp[v] = max(dp[v], dp[v - w[i]] + c[i]);
        }
    }
    //寻找dp[0...V]中最大的即为答案
    int max = 0;
    for (int v = 0; v <= V; v++) {
        if (dp[v] > max) {
            max = dp[v];
        }
    }
    printf("%d\n", max);
    return 0;
}

//完全背包问题
for (int i = 1; i <= n; i++) {
    //正向枚举v
    for (int v = w[i]; v <= V; v++) {
        dp[v] = max(dp[v], dp[v - w[i]] + c[i]);
    }
}

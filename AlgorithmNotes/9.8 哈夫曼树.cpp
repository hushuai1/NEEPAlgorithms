//用哈夫曼树解决合并果子问题
#include <cstdio>
#include <queue>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> q; //代表小顶堆的优先队列

int main() {
    int n;
    long long temp, x, y, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &temp);
        q.push(temp); //将初始重量压入优先队列
    }
    while (q.size() > 1) {
        //只要优先队列至少中有两个元素
        x = q.top();
        q.pop();
        y = q.top();
        q.pop();
        q.push(x + y); //取出堆顶的两个元素，求和后压入优先队列
        ans += x + y; //累计求和的结果
    }
    printf("%lld\n", ans); //ans即为消耗的最小体力
    return 0;
}


//哈夫曼编码
//注意是针对确定的字符串

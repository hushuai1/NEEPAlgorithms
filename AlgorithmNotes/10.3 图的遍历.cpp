/**
* 图的遍历：DFS和BFS
**/

//DFS
const int MAXV = 1000; //最大顶点数
const int INF = 1000000000; //设INF为一个很大的数
//邻接矩阵版
int n, G[MAXV][MAXV]; //n为顶点数，MAXV为最大顶点数
bool vis[MAXV] = { false }; //如果顶点i已被访问，则via[i]==true，初值为false
//u为当前访问的顶点标号，depth为深度
void DFS(int u, int depth) {
    vis[u] = true; //设置u已被访问
    //如果需要对u进行一些操作，可以在这里进行
    //下面对所有从u出发能到达的分支顶点进行枚举
    for (int v = 0; v < n; v++) {
        //如果v未被访问，且u可到达v
        if (vis[v] == false && G[u][v] != INF)
            DFS(v, depth + 1); //访问v，深度加1
    }
}
//遍历图G
void DFSTrave() {
    for (int u = 0; u < n; u++) {
        //如果u未被访问
        if (vis[u] == false)
            DFS(u, 1); //访问u和u所在的连通块，1表示初始为第一层
    }
}
//邻接表版
vector<int> Adj[MAXV]; //图G的邻接表
int n; //顶点数
bool vis[MAXV] = { false };
void DFS(int u, int depth) {
    vis[u] = true; //设置u已被访问
    //如果需要对u进行一些操作，可以在此处进行
    //对从u出发可以到达的所有顶点进行枚举
    for (int i = 0; i < Adj[u].size(); i++) {
        int v = Adj[u][i];
        //如果v未被访问
        if (vis[v] == false)
            DFS(v, depth + 1); //访问v，深度加1
    }
}
//遍历图G
void DFSTrave() {
    for (int u = 0; u < n; u++) {
        if (vis[u] == false)
            DFS(u, 1);
    }
}

//BFS
//邻接矩阵版
int n, G[MAXV][MAXV];
bool inq[MAXV] = { false }; //若顶点i曾入过队列，则inq[i]==true，初值为false
//遍历u所在的连通块
void BFS(int u) {
    queue<int> q; //定义队列q
    q.push(u); //将初始点u入队
    inq[u] = true; //设置u已被加入过队列
    //只要队列非空
    while (!q.empty()) {
        int u = q.front(); //取出队首元素
        q.pop(); //将队首元素出队
        for (int v = 0; v < n; v++) {
            //如果u的邻接点v未曾加入过队列
            if (inq[v] == false && G[u][v] != INF) {
                q.push(v); //将v入队
                inq[v] = true; //标记v为已被加入过队列
            }
        }

    }
}
//遍历图G
void BFSTrave() {
    //枚举所有顶点
    for (int u = 0; u < n; u++) {
        //如果u未曾加入过队列
        if (inq[u] == false)
            BFS(u); //遍历u所在的连通块
    }
}
//邻接表版
vector<int> Adj[MAXV]; //图G，Adj[u]存放从顶点u出发可以到达的所有顶点
int n; //顶点数
bool inq[MAXV] = { false };
void BFS(int u) {
    queue<int> q;
    q.push(u);
    inq[u] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < Adj[u].size(); i++) {
            int v = Adj[u][i];
            if (inq[v] == false) {
                q.push(v);
                inq[v] = true;
            }
        }
    }
}
void BFSTrave() {
    for (int u = 0; u < n; u++) {
        if (inq[u] == false)
            BFS(u);
    }
}
//注意：与树的BFS遍历一样，BFS可以输出该连通块内所有其他顶点的层号

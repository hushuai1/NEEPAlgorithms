/**
* 二叉查找树：又称排序二叉树、二叉搜索树、二叉排序树
**/

//递归定义：① 要么二叉查找树是一课空树
//          ② 要么二叉查找树由根结点、左子树、右子树组成，其中左子树和右子树都是二叉查找树
//             且左子树上所有结点的数据域均小于或等于根结点的数据域
//             右子树上所有结点的数据域均大于或等于根结点的数据域

//基本操作
//查找
//search函数查找二叉查找树中数据域为x的结点
void search(node* root, int x) {
    if (root == NULL) {
        printf("search failed\n"); //空树，查找失败
        return;
    }
    if (x == root->data) {
        printf("%d\n", root->data); //查找成功，访问之
    } else if (x < root->data) {
        search(root->lchild, x); //如果x比根结点的数据域小，说明x在左子树，往左子树搜索x
    } else {
        search(root->rchild, x); //如果x比根结点的数据域大，说明x在右子树，往右子树搜索x
    }
}
//插入
//insert函数将在二叉树中插入一个数据域为x的新结点（注意参数root要加引用&）
void insert(node* &root, int x) {
    if (root == NULL) {
        root = newNode(x); //空树，说明查找失败，也即插入位置，新建结点，权值为x
        return;
    }
    if (x == root->data) {
        return; //查找成功，说明结点已经存在，直接返回
    } else if (x < root->data) {
        insert(root->lchild, x); //如果x比根结点的数据域小，说明x需要插在左子树，往左子树搜索x
    } else {
        insert(root->rchild, x); //如果x比根结点的数据域大，说明x需要插在右子树，往右子树搜索x
    }
}
//建立
node* Create(int data[], int n) {
    node* root = NULL; //新建根结点root
    for (int i = 0; i < n; i++) {
        insert(root, data[i]); //将data[0]-data[n-1]插入二叉查找树中
    }
    return root; //返回根结点
}
//删除
//寻找以root为根结点的树中的最大权值结点
node* findMax(node* root) {
    while (root->lchild != NULL) {
        root = root->rchild; //不断往右，直到没有右孩子
    }
    return root;
}
//寻找以root为根结点的树中的最小权值结点
node* findMin(node* root) {
    while (root->lchild != NULL) {
        root = root->lchild; //不断往左，直到没有左孩子
    }
    return root;
}
//删除以root为根结点的树中权值为x的结点
void deleteNode(node* &root, int x) {
    if (root == NULL)
        return; //不存在权值为x的结点
    if (root->data == x) {
        //找到欲删除结点
        if (root->lchild == NULL && root->rchild == NULL) {
            //叶子结点直接删除
            root = NULL; //把root地址设为NULL，父结点就引用不到它了
        } else if (root->lchild != NULL) {
            //左子树不为空时
            node* pre = findMax(root->lchild); //找root前驱
            root->data = pre->data; //用前驱覆盖root
            deleteNode(root->lchild, pre->data); //在左子树中删除结点pre
        } else {
            //右子树不为空时
            node* next = findMin(root->rchild); //找root后继
            root->data = next->data; //用后继覆盖root
            deleteNode(root->rchild, next->data); //在右子树中删除next
        }
    } else if (root->data > x) {
        deleteNode(root->lchild, x); //在左子树中删除x
    } else {
        deleteNode(root->rchild, x); //在右子树中删除x
    }
}

//性质：对二叉查找树进行中序遍历，遍历的结果是有序的
//      详见PAT A1043

/*Description

学校举办了一个在线ACM比赛，现有一个时间榜单。小明想随时知道目前榜单上面排名第kk的人的运行时间。但是这个榜单由于一些原因会动态变化，具体情况如下：

1.由于新增加选手，榜单可能会有新的时间出现。

2.由于检测到某选手有犯规行为，榜单上的时间可能会被删除。

3.询问时间第kk小的人的时间。


Input
第一行一共一个数字nn，代表接下来一共会有nn行输入。

从第二行开始接下来会有nn行输入，每行一个字符和一个数字，用空格隔开。字符一共有三种情况：

字符I，代表插入一个时间，字符后面的数字代表插入的时间。

字符D，代表删除一个时间，字符后面的数字代表删除的时间，这里保证待删除的时间一定存在。

字符K，代表一个查询，字符后面的数字kk代表查询第kk小的时间，这里保证第kk小的时间一定存在。

数据规模：

0<n\leq 20000000<n≤2000000*/

#include <stdio.h>
#include <stdlib.h>

typedef enum color {
    Red,Black
} Color;

typedef struct node {
    int key;
    int ord;
    int size;
    Color col;
    struct node *lchild;
    struct node *rchild;
    struct node *parent;
} Node;

typedef struct rb_tree {
    struct node *root;
    struct node *NIL;
} RB_Tree;

RB_Tree *Init_RB_Tree() {
    RB_Tree *T = (RB_Tree *)malloc(sizeof(RB_Tree));
    Node *nil = (Node *)malloc(sizeof(Node));
    T->root = nil;
    nil->col = Black;
    nil->parent = nil;
    nil->lchild = nil;
    nil->rchild = nil;
    nil->size = 0;
    T->NIL = nil;
    return T;
}

Node *RB_Minimun_Node(RB_Tree *T, Node *x) {
    while (x->lchild != T->NIL) {
        x = x->lchild;
    }
    return x;
} 

void RB_Print_Pre(RB_Tree *T, Node *z) {
    if (z->col == Black)
        printf("%d----black----%d\n", z->key, z->size);
    else
        printf("%d----red----%d\n", z->key, z->size);
    Node *l = z->lchild;
    Node *r = z->rchild;
    if (l != T->NIL)
        RB_Print_Pre(T, l);
    if (r != T->NIL)
        RB_Print_Pre(T, r);
    return;
}

void RBTree_Print_Preorder(RB_Tree *T) {
    if (T->root != T->NIL)
        RB_Print_Pre(T, T->root); 
    else
        printf("No Nodes on the RBTree\n");
}

void RB_Set_Root(RB_Tree *T, Node *z) {
    T->root = z;
    z->parent = T->NIL;
    T->NIL->lchild = z;
    T->NIL->rchild = z;
}

void Left_Rotate(RB_Tree *T, Node *x) {
    Node *y = x->rchild;
    int x_l = x->lchild->size;
    int y_l = y->lchild->size;
    int y_r = y->rchild->size;
    x->rchild = y->lchild;
    if (y->lchild != T->NIL)
        y->lchild->parent = x;
    y->parent = x->parent;
    if (x->parent == T->NIL)
        RB_Set_Root(T, y);
    else if (x == x->parent->lchild)
        x->parent->lchild = y;
    else x->parent->rchild = y;
    y->lchild = x;
    x->parent = y;
    x->size = x_l + y_l + 1;
    y->size = x->size + y_r + 1; 
}

void Right_Rotate(RB_Tree *T, Node *x) {
    Node *y = x->lchild;
    int x_r = x->rchild->size;
    int y_l = y->lchild->size;
    int y_r = y->rchild->size;
    x->lchild = y->rchild;
    if (y->rchild != T->NIL)
        y->rchild->parent = x;
    y->parent = x->parent;
    if (x->parent == T->NIL)
        RB_Set_Root(T, y);
    else if (x == x->parent->lchild)
        x->parent->lchild = y;
    else x->parent->rchild = y;
    y->rchild = x;
    x->parent = y;
    x->size = x_r + y_r + 1;
    y->size = x->size + y->lchild->size + 1;
}

void RB_Insert_Fixup(RB_Tree *T, Node *z) {
    while (z->parent->col == Red) {
        if (z->parent == z->parent->parent->lchild) {    //如果叔叔是右孩子
            Node *y = z->parent->parent->rchild;  
            if (y->col == Red) {                        //叔叔结点的颜色是红色
                z->parent->col = Black;
                y->col = Black;
                z->parent->parent->col = Red;
                z = z->parent->parent;
            } else if (z == z->parent->rchild) {        //叔叔结点的颜色是黑色
                z = z->parent;
                Left_Rotate(T, z);
            } else {
                z->parent->col = Black;
                z->parent->parent->col = Red;
                Right_Rotate(T, z->parent->parent);
            }
        }
        else {                                          //叔叔是左孩子
            Node *y = z->parent->parent->lchild;
            if (y->col == Red) {
                z->parent->col = Black;
                y->col = Black;
                z->parent->parent->col = Red;
                z = z->parent->parent;
            } else if (z == z->parent->lchild) {       //叔叔结点是黑色
                z = z->parent;
                Right_Rotate(T, z);
            } else {
                z->parent->col = Black;
                z->parent->parent->col = Red;
                Left_Rotate(T, z->parent->parent);
            }
        }
    }
    T->root->col = Black;
}

void RB_Insert(RB_Tree *T, int num) {
    Node *y = T->NIL;
    Node *x = T->root;
    while (x != T->NIL) {
        x->size ++;
        y = x;
        if (num < x->key)
            x = x->lchild;
        else
            x = x->rchild;
    }
    Node *z = (Node *)malloc(sizeof(Node));
    z->key = num;
    z->parent = y;
    z->size = 1;
    if (y == T->NIL) 
        RB_Set_Root(T, z);
    else if (num < y->key)
        y->lchild = z;
    else 
        y->rchild = z;
    z->lchild = T->NIL;
    z->rchild = T->NIL;
    z->col = Red;
    RB_Insert_Fixup(T, z);
}   

Node *RB_Search_Node(RB_Tree *T, Node *x, int num) {
    if (x->key == num)
        return x;
    else if (x->key < num)
        return RB_Search_Node(T, x->rchild, num);
    else return RB_Search_Node(T, x->lchild, num);
}

void RB_Delete_Fixup(RB_Tree *T, Node *x) {
    while (x != T->root && x->col == Black) {
        if (x == x->parent->lchild) {
            Node *w = x->parent->rchild;
            if (w->col == Red) {
                w->col = Black;
                x->parent->col = Red;
                Left_Rotate(T, x->parent);
                w = x->parent->rchild;
            }
            if ((w->lchild->col == Black) && (w->rchild->col == Black)) {
                w->col = Red;
                x = x->parent;
            } else {
                if (w->rchild->col == Black) {
                    w->lchild->col = Black;
                    w->col = Red;
                    Right_Rotate(T, w);
                    w = x->parent->rchild;
                }
                w->col = x->parent->col;
                x->parent->col = Black;
                w->rchild->col = Black;
                Left_Rotate(T, x->parent);
                x = T->root;
            }
        } else {
            Node *w = x->parent->lchild;
            if (w->col == Red) {
                w->col = Black;
                x->parent->col = Red;
                Right_Rotate(T, x->parent);
                w = x->parent->lchild;
            }
            if ((w->lchild->col == Black) && (w->rchild->col == Black)) {
                w->col = Red;
                x = x->parent;
            } else {
                if (w->lchild->col == Black) {
                    w->rchild->col = Black;
                    w->col = Red;
                    Left_Rotate(T, w);
                    w = x->parent->lchild;
                }
                w->col = x->parent->col;
                x->parent->col = Black;
                w->lchild->col = Black;
                Right_Rotate(T, x->parent);
                x = T->root;
            }
        }
    }
    x->col = Black;
}

void RB_Fixnum(RB_Tree *T, Node *x) {
    x->size = x->lchild->size + x->rchild->size + 1;
    if (x->parent != T->NIL)
        RB_Fixnum(T, x->parent);
}

int RB_Search_order(RB_Tree *T, Node *x, int i) {
    if (i > x->size)
        return 0;
    else if(i <= x->lchild->size)
        RB_Search_order(T, x->lchild, i);
    else if( i == x->lchild->size + 1)
        return x->key;
    else RB_Search_order(T, x->rchild, i - x->lchild->size - 1);
}

void RB_TransPlant(RB_Tree *T, Node *u, Node *v) {
    if (u->parent == T->NIL)
        RB_Set_Root(T, v);
    else if (u == u->parent->lchild)
        u->parent->lchild = v;
    else u->parent->rchild = v;
    v->parent = u->parent;
}

void RB_Delete_Node(RB_Tree *T, Node *z) {
    Node *y = z;
    Node *x;
    Color origin_y_col = y->col;
    if (z->lchild == T->NIL) {
        x = z->rchild;
        RB_TransPlant(T, z, z->rchild);
    } else if (z->rchild == T->NIL) {
        x = z->lchild;
        RB_TransPlant(T, z, z->lchild);
    } else {
        y = RB_Minimun_Node(T, z->rchild);
        origin_y_col = y->col;
        x = y->rchild;
        if (y->parent == z)
            x->parent = y;
        else {
            RB_TransPlant(T, y, y->rchild);
            y->rchild = z->rchild;
            y->rchild->parent = y;
        }
        RB_TransPlant(T, z, y);
        y->lchild = z->lchild;
        y->lchild->parent = y;
        y->col = z->col;
    }
    if (x->parent != T->NIL)
        RB_Fixnum(T, x->parent);
    if (origin_y_col == Black)
        RB_Delete_Fixup(T, x);
}

void RB_Delete_num(RB_Tree *T, int num) {
    Node *del = RB_Search_Node(T, T->root, num);
    RB_Delete_Node(T, del);
}

int main() {
    int n, data;
    char oper;
    char read[20];
    RB_Tree *T = Init_RB_Tree();

    gets(read);
    sscanf(read, "%d", &n);
    for(int i = 0; i < n; i++){
        gets(read);
        sscanf(read, "%c %d", &oper, &data);
        if (oper == 'I') {
            RB_Insert(T, data);
        } else if (oper == 'D') {
            RB_Delete_num(T, data);
        } else if (oper == 'K') {
            printf("%d\n", RB_Search_order(T, T->root, data));
        } else printf("Invalid operation\n");
    }
    //RBTree_Print_Preorder(T);
    return 0;
}

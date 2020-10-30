[**中序遍历(inorder-tree-walk)**](#inorder)

[**先序遍历(preorder-tree-walk)**](#preorder)

[**后序遍历(postorder-tree-walk)**](#postorder)

[**查找(tree_search)**](#tree_search)

[**迭代版本的查找(iterative_tree_search)**](#iterative_tree_search)

<div id = "inorder"></div>

* inorder-tree-walk 
```c
inorder_tree_walk(x) {
  if x != NULL
    inorder_tree_walk(x.left)
    print x.key
    inorder_tree_walk(x.right)
}
```

<div id = "preorder"></div>

* preorder-tree-walk 
```c
preorder_tree_walk(x) {
  if x != NULL
    print x.key
    preorder_tree_walk(x.left)
    preorder_tree_walk(x.right)
}
```

<div id = "postorder"></div>

* postorder_tree_walk 
```c
postorder_tree_walk(x) {
  if x != NULL
    postorder_tree_walk(x.left)
    postorder_tree_walk(x.right)
    print x.key
}
```

<div id = "tree_search"></div>

* tree-search
```c
tree_search(x, k) {
  if x == NULL or k == x.key
    return x
  if k < x.key
    return tree_search(x.left, k)
  rlse return tree_search(x.right, k)
}
```

<div id = "iterative_tree_search"></div>

* iterative-tree-search
```c
iterative_tree_search(x, k) {
  while x!= NULL and k != x.key
    if k < x.key
      x = x.left
    else x = x.right
  return x
}
```

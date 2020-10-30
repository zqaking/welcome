[**中序遍历**](#inorder)

[**先序遍历**](#preorder)

[**后序遍历**](#postorder)

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

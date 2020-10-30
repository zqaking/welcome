* inorder-tree-walk
```c
inorder_tree_walk(x) {
  if x != NULL
    inorder_tree_walk(x.left)
    print x.key
    inorder_tree_walk(x.right)
}
```

* preorder-tree-walk
```c
preorder_tree_walk(x) {
  if x != NULL
    print x.key
    preorder_tree_walk(x.left)
    preorder_tree_walk(x.right)
}
```

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

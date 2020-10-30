* inorder-tree-walk(x)
```c
inorder_tree_walk(x) {
  if x != NULL
    inorder_tree_walk(x.left)
    print x.key
    inorder_tree_walk(x.right)
}
```

* preorder-tree-walk(x)
```c
preorder_tree_walk(x) {
  if x != NULL
    print x.key
    preorder_tree_walk(x.left)
    preorder_tree_walk(x.right)
}
```

* postorder_tree_walk(x)
```c
postorder_tree_walk(x) {
  if x != NULL
    postorder_tree_walk(x.left)
    postorder_tree_walk(x.right)
    print x.key
}
```

* BUBBLE-SORT
```伪代码
BUBBLE-SORT(A)
  for i = 1 to A:length - 1 do
    noswap = TRUE
  for j = A:length - 1 downto i do
    if A[j+1] < A[j] then
      A[j] <->A [j+1]
      noswap = FALSE
  if noswap then break
```

* SHELL-SORT
```伪代码
SHELL-PASS(A, d) {
  for i = d + 1 to n do
    if A[i] < A[i -d] then
      key = A[i]      //A[i] is to inserted in the correct position
      j = i - d
      while j > 0 and key < A[j] do
        A[j + d] = A[j]
        j = j -d
      A[j + d] = key
}
SHELL-SORT(A, D) {
  for increment in D do
    SHELL-PAss(A, increment)
}
```

* BUBBLESORT
```伪代码
BUBBLE-SORT(A)
  for i = 1 to A.length - 1 do
    noswap = TRUE
  for j = A.length - 1 downto i do
    if A[j+1] < A[j] then
      A[j] <-> A [j+1]
      noswap = FALSE
  if noswap then break
```

* SHELLSORT
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
SHELLSORT(A, D) {
  for increment in D do
    SHELL-PAss(A, increment)
}
```

* HEAPSORT
```伪代码
MAX-HEAPIFY(A, i) {
  l = LEFT(i)
  r = RIGHT(i)
  if l <= A.heap-size and A[l] > A[i] then
    largest = l
  else largest = i
  if r <= A.heap-size and A[r] > A[largest] then
    largest = r
  if largest != i then
    A[i] <-> A[largest]
    MAX-HEAPIFY(A, largest)
}
BUILD-MAX-HEAP(A) {
  A.heap-size = A.length
  for i = ⌊A.length⌋/2 downto 1
    MAX-HEAPIF(A, i)
}
HEAPSORT(A) {
  BUILD-MAX-HEAP
  for i = A.length downto 2
    A[l] <-> A[i]
    A.heap-size = A.heap-size - 1
    MAXHEAPIFY(A, l)
}
```

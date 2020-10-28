* BUBBLESORT
```c
BUBBLE-SORT(A)
  for i = 1 to A.length-1 do
    noswap = TRUE
  for j = A.length-1 downto i do
    if A[j+1] < A[j] then
      A[j] <-> A [j+1]
      noswap = FALSE
  if noswap then break
```

* SHELLSORT
```c
SHELL-PASS(A, d) {
  for i = d + 1 to n do
    if A[i] < A[i-d] then
      key = A[i]      //A[i] is to inserted in the correct position
      j = i - d
      while j > 0 and key < A[j] do
        A[j+d] = A[j]
        j = j -d
      A[j+d] = key
}
SHELLSORT(A, D) {
  for increment in D do
    SHELL-PAss(A, increment)
}
```

* HEAPSORT
```c
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
    MAX-HEAPIFY(A, i)
}
HEAPSORT(A) {
  BUILD-MAX-HEAP
  for i = A.length downto 2
    A[l] <-> A[i]
    A.heap-size = A.heap-size - 1
    MAXHEAPIFY(A, l)
}
```

* QUICKSORT
```c
QUICKSORT(A，p, r) {
  if p < r
    q = PARTITION(A, p, r)
    QUICKSORT(A, p, q - 1)
    QUICKSORT(A, q + 1, r)
}
PARTITION(A, p, r) {
  x = A[r]
  i = p-1
  for j = p to r-1
    if A[j] <= x
      i = i + 1
      A[i] <-> A[j]
  A[i+1] <-> A[r]
  return i+1   
}
```

* COUNTINGSORT
```c
COUNTINGSORT(A, B, k) {
  for i = 0 to k do
    C[i] = 0
  for j = 1 to A:length do
    C[A[j]] = C[A[j]] + 1
    //C[i] now contains the number of elements equal to i.
  for i = 1 to k do
    C[i]=C[i] + C[i-1]
    //C[i] now contains the number of elements less than or equal to i.
  for j = A:length to 1 do
    B[C[A[j]]] = A[j]
    C[A[j]] = C[A[j]] - 1
}
```

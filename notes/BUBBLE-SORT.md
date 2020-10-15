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

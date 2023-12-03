import sys

def MatrixCahinOrder(p, i, j):
    if i == j:
        return 0

    _min = sys.maxsize

    for k in range(i, j):
        count = (
            MatrixCahinOrder(p, i, k)
            + MatrixCahinOrder(p, k+1, j)
            + p[i-1] * p[k] * p[j]
        )
        
        if count < _min:
            _min = count
        return _min

arr = [20, 2, 30, 12, 8]
n = len(arr)
print("최소 연산의 수는", MatrixCahinOrder(arr, 1, n-1))
int main()
{
    n = A.size // A[0], A[1], …, A[n-1]
            shrinkRatio = 2 gap = A.size / shrinkRatio while (gap > 0)
    {
        for (i = gap; i < n; i++)
        {
            tmp = A[i] for (j = i; (j >= gap) && (A[j – gap] > tmp); j -= gap)
                A[j] = A[j – gap] A[j] = tmp
        }
        gap /= shrinkRatio
    }
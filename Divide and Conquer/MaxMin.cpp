#include <iostream>

using namespace std;

int MaxMin(int A[], int i, int j)
{
    if (i == j)
    {
        return A[i];
    }
    else
    {
        int mid = (i + j) / 2;
        int min1 = MaxMin(A, i, mid);
        int min2 = MaxMin(A, mid + 1, j);
        if (min1 > min2)
        {
            return min2;
        }
        else
            return min1;
    }
}

int main()
{
    int A[] = {70, 20, 40, 35, 55, 68, 42, 37, 120, 49, 18, 60};
    int i = 0, j = (sizeof(A) / sizeof(A[0])) - 1;
    int min = MaxMin(A, i, j);
    cout << min;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void maintain_heap(int arr[], int x, int y)
{
    int l = y;

    int left = 2 * y + 1;

    int right = 2 * y + 2;

    if (left < x && arr[left] > arr[l])
    {
        l = left;
    }

    if (right < x && arr[right] > arr[l])
    {
        l = right;
    }

    if (l != y)
    {
        swap(arr[y], arr[l]);

        maintain_heap(arr, x, l);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // heap sort

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maintain_heap(a, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        maintain_heap(a, i, 0);
    }

    // printing

    for (auto i : a)
    {
        cout << i << " ";
    }
}

#include <bits/stdc++.h>
using namespace std;

long long comparisons = 0;

// pivot = last element
int partition(vector<int> &a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

// DETERMINISTIC: always uses last element as pivot
void quickSort(vector<int> &a, int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// RANDOMIZED: pick a random pivot, move it to the end, then same partition
void randomQuickSort(vector<int> &a, int low, int high) {
    if (low < high) {
        int r = low + rand() % (high - low + 1);
        swap(a[r], a[high]);
        int p = partition(a, low, high);
        randomQuickSort(a, low, p - 1);
        randomQuickSort(a, p + 1, high);
    }
}

int main() {
    srand(time(0));

    int n = 2000;
    vector<int> sorted(n);                 // already sorted = worst case for last-pivot
    for (int i = 0; i < n; i++) {
        sorted[i] = i;
    }

    vector<int> a = sorted;
    comparisons = 0;
    quickSort(a, 0, n - 1);
    cout << "Deterministic on sorted input: comparisons = " << comparisons << endl;

    vector<int> b = sorted;
    comparisons = 0;
    randomQuickSort(b, 0, n - 1);
    cout << "Randomized    on sorted input: comparisons = " << comparisons << endl;

    cout << "Best/Avg: O(n log n)   Worst deterministic: O(n^2)   Randomized expected: O(n log n)" << endl;
    return 0;
}

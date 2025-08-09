#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// --- MERGE SORT IMPLEMENTATION ---
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void merge_sort_recursive(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    merge_sort_recursive(arr, low, mid);
    merge_sort_recursive(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void mergeSort(vector<int> &arr)
{
    merge_sort_recursive(arr, 0, arr.size() - 1);
}

// --- QUICK SORT IMPLEMENTATION ---
int partition(vector<int> &arr, int low, int high)

{
    int pivot = arr[high]; // we can also denoted low as pivot.
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quick_sort_recursive(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(arr, low, high);
        quick_sort_recursive(arr, low, pIndex - 1);
        quick_sort_recursive(arr, pIndex + 1, high);
    }
}

void quickSort(vector<int> &arr)
{
    quick_sort_recursive(arr, 0, arr.size() - 1);
}

// --- MAIN FUNCTION ---
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    vector<int> arr_merge = arr;
    vector<int> arr_quick = arr;

    // Measure Merge Sort
    auto start_merge = high_resolution_clock::now();
    mergeSort(arr_merge);
    auto stop_merge = high_resolution_clock::now();
    auto duration_merge = duration_cast<nanoseconds>(stop_merge - start_merge);

    // Measure Quick Sort
    auto start_quick = high_resolution_clock::now();
    quickSort(arr_quick);
    auto stop_quick = high_resolution_clock::now();
    auto duration_quick = duration_cast<nanoseconds>(stop_quick - start_quick);

    // Display results
    cout << "Merge Sort Result: ";
    for (int x : arr_merge)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << "Quick Sort Result: ";
    for (int x : arr_quick)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << "Merge Sort Time: " << (double)duration_merge.count() / 1e9 << " sec" << endl;
    cout << "Quick Sort Time: " << (double)duration_quick.count() / 1e9 << " sec" << endl;

    return 0;
}
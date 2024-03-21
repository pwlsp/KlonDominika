#include <iostream>

#include <vector>

#include <algorithm>

#include <time.h>

using namespace std;

// int partition_zle(vector<int> &arr, int p, int r)
// {
//     int pivot = arr[r];
//     int i = p - 1;
//
//     for (int j = p; j <= r - 1; j++)
//     {
//         if (arr[j] <= pivot)
//         {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[r]);
//     return (i + 1);
// }

// int partition_s(vector<int> &arr, int p, int r)
// {
//     cout<<"test";
//     int pivot = arr[r];
//     int i = p;
//     int j = r;
//
//     while (true)
//     {
//         while (arr[i] < pivot)
//             i++;
//         while (arr[j] > pivot)
//             j--;
//         if (i <= j)
//         {
//             swap(arr[i], arr[j]);
//             i++;
//             j--;
//         }
//         else
//             return j;
//     }
// }

void printArray(vector<int> arr)
{
    cout << arr[0];
    for (int i = 1; i < min(100, static_cast<int>(arr.size())); ++i)
    {
        cout << " " << arr[i];
    }
}

void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int j = 1; j < n; j++)
    {
        int key = arr[j];
        int i = j - 1;
        // >= bo tu pierwszy indeks to nie 1 jak w prezentacji
        while (i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}

int partition(vector<int> &arr, int p, int r) {
    int pivot = arr[p];
    int i = p;
    int j = r;

    while (i < j) {
        while (arr[i] <= pivot && i < r) {
            i++;
        }
        while (arr[j] > pivot && j > p) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[p], arr[j]);
    return j;
}

int partition_r(vector<int> &arr, int p, int r)
{
    srand(time(NULL));
    int random = p + rand() % (r - p);

    swap(arr[random], arr[p]);

    // cout << "random: " << random << endl;

    return partition(arr, p, r);
}

void quickSort(vector<int> &arr, int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

void quickSort_r(vector<int> &arr, int p, int r)
{
    if (p < r)
    {
        int q = partition_r(arr, p, r);
        quickSort_r(arr, p, q - 1);
        quickSort_r(arr, q + 1, r);
    }
}

vector<int> sort_using_algorithm(vector<int> &data, int algorithm)
{
    switch (algorithm)
    {
    case 1:
        insertionSort(data);
        cout << "Insertion sort - ";
        break;

    case 5:
        quickSort(data, 0, data.size() - 1);
        cout << "Quick sort | max left pivot - ";
        break;

    case 6:
        quickSort_r(data, 0, data.size() - 1);
        cout << "Quick sort | random pivot - ";
        break;

    default:
        // sort(data.begin(), data.r());
        cout << "Wykonuje \'default\' w \'switch case\'" << endl;
        break;
    }
    return data;
}

int main(int argc, char *argv[])
{
    // Command-line arguments: ./a.out --algorithm <algorithm_number>
    if (argc != 3 || string(argv[1]) != "--algorithm")
    {
        std::cout << "Usage: ./a.out --algorithm <algorithm_number>\n";
        return 1;
    }

    int algorithm_number = stoi(argv[2]);

    // Read input data from standard input until the r of file (EOF)
    vector<int> data;
    int num;
    while (cin >> num)
    {
        data.push_back(num);
    }

    // Perform sorting using the specified algorithm (ignored in this example)
    vector<int> sorted_data = sort_using_algorithm(data, algorithm_number);

    // Print the sorted data
    cout << "POMOCY - Sorted data:\n";
    printArray(sorted_data);
    cout << endl;

    return 0;
}

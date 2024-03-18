#include <iostream>

#include <vector>

#include <algorithm>

#include <time.h>

using namespace std;

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
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return (i + 1);
}

int partition_r(vector<int> &arr, int start, int end)
{
    // Generate a random number in between
    // low .. high
    srand(time(NULL));
    int random = start + rand() % (end - start);

    // Swap A[random] with A[high]
    swap(arr[random], arr[end]);

    // cout << "random: " << random << endl;

    return partition(arr, start, end);
}

void quickSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int p = partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
}

void quickSort_r(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int p = partition_r(arr, start, end);
        quickSort_r(arr, start, p - 1);
        quickSort_r(arr, p + 1, end);
    }
}

vector<int> sort_using_algorithm(vector<int> &data, int algorithm)
{
    // This function takes the algorithm identifier as input
    // However, it always uses the sorted function in C++
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
        // sort(data.begin(), data.end());
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

    // Read input data from standard input until the end of file (EOF)
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

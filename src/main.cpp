#include <iostream>

#include <vector>

#include <algorithm>

#include <time.h>

using namespace std;

vector<int> insertionSort(const vector<int> &arr)
{
    std::vector<int> sortedArray = arr;
    int n = sortedArray.size();
    for (int i = 1; i < n; i++)
    {
        int key = sortedArray[i];
        int j = i - 1;
        while (j >= 0 && sortedArray[j] > key)
        {
            sortedArray[j + 1] = sortedArray[j];
            j = j - 1;
        }
        sortedArray[j + 1] = key;
    }
    reverse(sortedArray.begin(), sortedArray.end());
    return sortedArray;
}

// int partition(vector<int> &arr, int start, int end)
// {
//     int pivot = arr[start];
//     // for (int u = 0; u < 10; u++)
//     // {
//     //     pivot = start + (std::rand() % (end - start + 1));
//     //     cout << "pivot  " << start << " - " << end << ":  " << pivot << endl;
//     // }
    
//     int count = 0;
//     for (int i = start + 1; i <= end; i++)
//     {
//         if (arr[i] <= pivot)
//             count++;
//     }
//     int pivotIndex = start + count;
//     swap(arr[pivotIndex], arr[start]);
//     int i = start, j = end;
//     while (i < pivotIndex && j > pivotIndex)
//     {
//         while (arr[i] <= pivot)
//         {
//             i++;
//         }
//         while (arr[j] > pivot)
//         {
//             j--;
//         }
//         if (i < pivotIndex && j > pivotIndex)
//         {
//             swap(arr[i++], arr[j--]);
//         }
//     }
//     return pivotIndex;
// }

void printArray(vector<int> arr)
{
	int i;
	for (i = 0; i < arr.size(); i++)
		cout<<arr[i]<<" "; 
}

int partition(vector<int> &arr, int start, int end)
{
    // pivot
    int pivot = arr[end]; 
   
    // Index of smaller element
    int i = (start - 1); 
 
    for (int j = start; j <= end - 1; j++) 
    {
        // If current element is smaller
        // than or equal to pivot
        if (arr[j] <= pivot) {
 
            // increment index of 
            // smaller element
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
    
    cout << "random: " << random << endl; 

    return partition(arr, start, end);
}

vector<int> quickSort(vector<int> arr, int start, int end)
{
    if (start >= end)
        return arr;
    int p = partition(arr, start, end);
    arr = quickSort(arr, start, p - 1);
    arr = quickSort(arr, p + 1, end);
    return arr;
}

vector<int> quickSort_r(vector<int> arr, int start, int end)
{
    if (start >= end)
        return arr;
    int p = partition_r(arr, start, end);
    arr = quickSort_r(arr, start, p - 1);
    arr = quickSort_r(arr, p + 1, end);
    printArray(arr);
    cout << endl;
    return arr;
}

vector<int> sort_using_algorithm(vector<int> &data, int algorithm)
{
    // This function takes the algorithm identifier as input
    // However, it always uses the sorted function in C++
    switch (algorithm)
    {
    case 1:
        data = quickSort(data, 0, data.size() - 1);
        cout << "Quick sort | max left pivot 11- ";
        break;

    case 2:
        data = quickSort_r(data, 0, data.size() - 1);
        cout << "Quick sort | random pivot 22- ";
        break;

    case 3:
        data = insertionSort(data);
        cout << "Insertion sort - ";
        break;

    case 4:
        sort(data.begin(), data.end());
        break;

    default:
        sort(data.begin(), data.end());
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
    cout << "Sorted data:";
    for (int i = 0; i < min(10, static_cast<int>(sorted_data.size())); ++i)
    {
        cout << " " << sorted_data[i];
    }
    cout << endl;

    return 0;
}

#include <iostream>

#include <vector>

#include <algorithm>

std::vector<int> sort_using_algorithm(std::vector<int> &data, int algorithm)
{
    // This function takes the algorithm identifier as input
    // However, it always uses the sorted function in C++
    switch (algorithm)
    {
    case 1:
        std::sort(data.begin(), data.end());
        break;
    
    case 2:
        std::sort(data.begin(), data.end());
        reverse(data.begin(), data.end());
        break;

    default:
        std::sort(data.begin(), data.end());
        break;
    }
    return data;
}

int main(int argc, char *argv[])
{
    // Command-line arguments: ./a.out --algorithm <algorithm_number>
    if (argc != 3 || std::string(argv[1]) != "--algorithm")
    {
        std::cout << "Usage: ./a.out --algorithm <algorithm_number>\n";
        return 1;
    }

    int algorithm_number = std::stoi(argv[2]);

    // Read input data from standard input until the end of file (EOF)
    std::vector<int> data;
    int num;
    while (std::cin >> num)
    {
        data.push_back(num);
    }

    // Perform sorting using the specified algorithm (ignored in this example)
    std::vector<int> sorted_data = sort_using_algorithm(data, algorithm_number);

    // Print the sorted data
    std::cout << "Sorted data:";
    for (int i = 0; i < std::min(10, static_cast<int>(sorted_data.size())); ++i)
    {
        std::cout << " " << sorted_data[i];
    }
    std::cout << std::endl;

    return 0;
}

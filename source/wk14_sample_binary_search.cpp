//------------------------------------------------------------------------------
// wk14_sample_binary_search.cpp
//
// Example of the binary search algorithm
//
// From YouTube video: https://youtu.be/vohuRrwbTT4
// Original code on pastebin: https://pastebin.com/fsmGF1hp
//------------------------------------------------------------------------------
#include <iostream>

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
const int ERR_NOT_FOUND = -1;  // search value not found

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
inline void displayIndexes(int array[], int low, int mid, int high);
int binarySearch(int array[], int size, int searchValue);

//------------------------------------------------------------------------------
// template function binarySearch()
//------------------------------------------------------------------------------
// Iterative binary search in sorted array[] of ints
//      - size parameter is number of elements in passed array[]
//      - searchValue parameter is value to find in array[]
// Requirements:
//      = array[] must be sorted in ascending order
// 
// Loops to compare searchValue with successive array midpoints.
// 
// The low and high array indices move towards each other.
// 
// Each loop iteration either:
//      increases low index, or
//      decreases high index
// 
// When low moves past high, the search stops and reports item not found.
// 
// Returns:
//      - array index of passed searchValue if the value was found,
//      - ERR_NOT_FOUND otherwise
//
// Example: int array[] = { 0, 1, 2, 3, 4 }, searchValue = 3
// 
//      1) set low index to 0, high index to 4
//              mid index is (0 + 4) / 2 = 2
//      2) compare searchValue 3 with midpoint value 2 at array[2]
//      3) 3 is not < 2 so next time only search elements after the 2
//              new low index is 3
//              same high index is 4
//              new mid index is (3 + 4) / 2 = 3
//      4) compare searchValue 3 with new midpoint value 3 at array[3]
//      5) 3 == 3 so searchValue is found at index mid = 3
//------------------------------------------------------------------------------
int binarySearch(int array[], int size, int searchValue)
{
    std::cout << "searchValue = " << searchValue << "\n\n";

    // left side search begins at array index low
    int low = 0;

    // right side search ends at array index high
    int high = size - 1;

    // array index in between low and high
    int mid;

    // search fails when the low index goes past the high index
    while (low <= high)
    {
        mid = (low + high) / 2;

        displayIndexes(array, low, mid, high);

        // found! at index mid
        if (searchValue == array[mid])
            return mid;

        // searchValue is bigger than current mid index 
        if (searchValue > array[mid])
        {
            // next search will start right after mid
            low = mid + 1;

            std::cout << "array[mid] " << array[mid]
                << " is less than searchValue " << searchValue
                << " so increase low index\n\n";
        }

        // searchValue < midValue
        else
        {
            // next search will end right before mid
            high = mid - 1;

            std::cout << "array[mid] " << array[mid]
                << " is greater than searchValue " << searchValue
                << " so decrease high index\n\n";
        }
    }

    std::cout << "low index = " << low << ", high index = " << high << '\n';

    return ERR_NOT_FOUND;
}

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main()
{
    int a[] = { 12, 22, 34, 47, 55, 67, 82, 98 };

    std::cout << "\nBinary Search Demo Loop\n";

    while (true)
    {
        int userValue;

        std::cout << "\nValues in array: ";
        for (auto element : a)
        {
            std::cout << element << ' ';
        }

        std::cout << "\n\nEnter a value: ";
        std::cin >> userValue;

        int elements = sizeof(a) / sizeof(int);
        int result = binarySearch(a, elements, userValue);

        if (result >= 0)
        {
            std::cout << "Value " << a[result]
                << " was found at index " << result << '\n';
        }
        else
        {
            std::cout << "Value " << userValue
                << " was not found. " << '\n';
        }
    }

    return 0;
}

//------------------------------------------------------------------------------
// display infor for demo and debugging
//------------------------------------------------------------------------------
inline void displayIndexes(int array[], int low, int mid, int high)
{
    std::cout << "low index = " << low
        << ", high index = " << high
        << ", mid index = " << mid << '\n';

    std::cout << "array[mid] = " << array[mid] << '\n';
}

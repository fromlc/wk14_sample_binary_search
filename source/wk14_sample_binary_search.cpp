//------------------------------------------------------------------------------
// wk14_sample_binary_search.cpp
//
// Example of the binary search algorithm
//
// From YouTube video: https://youtu.be/vohuRrwbTT4
// Original code on pastebin: https://pastebin.com/fsmGF1hp
//------------------------------------------------------------------------------
#include "Circle.h"

#include <iostream>

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
// Uncomment ONE array element type
#define TYPE_INT = 1
//#define TYPE_DOUBLE = 1
//#define TYPE_CIRLE = 1

const int ERR_NOT_FOUND = -1;  // search value not found

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
template <typename T>
inline void displayIndexes(T array[], int low, int mid, int high);

template <typename T>
int binarySearch(T array[], int size, T searchValue);

//------------------------------------------------------------------------------
// template function binarySearch()
//------------------------------------------------------------------------------
// Iterative binary search in sorted array[] of type T
//      - size parameter is number of T elements in passed array[]
//      - searchValue parameter is value to find in array[]
// Requirements:
//      = array[] must be sorted in ascending order
//      = type T must overload the ==, >, and << operators
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
//      - the array index where passed searchValue was found, or
//      - -1 if searchValue was not found
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
template <typename T>
int binarySearch(T array[], int size, T searchValue)
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
#ifdef TYPE_INT
    int a[] = { 12, 22, 34, 47, 55, 67, 82, 98 };
#endif
#ifdef TYPE_DOUBLE 
    double a[] = { 12.2, 22.2, 34.2, 47.2, 55.2, 67.2, 82.2, 98.2 };
#endif
#ifdef TYPE_CIRCLE
    Circle a[] = { Circle(12), Circle(22), Circle(34), Circle(47),
                   Circle(55), Circle(67), Circle(82), Circle(98) };
#endif

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

#ifdef TYPE_INT
        int elements = sizeof(a) / sizeof(int);
        int result = binarySearch<int>(a, elements, userValue);
#endif
#ifdef TYPE_DOUBLE
        int elements = sizeof(a) / sizeof(double);
        int result = binarySearch<double>(a, elements, userValue);
#endif
#ifdef TYPE_CIRCLE
        int elements = sizeof(a) / sizeof(Circle);
        int result = binarySearch<Circle>(a, elements, userValue);
#endif

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
template <typename T>
inline void displayIndexes(T array[], int low, int mid, int high)
{
    std::cout << "low index = " << low
        << ", high index = " << high
        << ", mid index = " << mid << '\n';

    std::cout << "array[mid] = " << array[mid] << '\n';
}

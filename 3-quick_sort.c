#include "sort.h"
/**
*swap - the positions of two elements into an array
*@array: array
*@item1: array element
*@item2: array element
*/
void swap(int *array, ssize_t item1, ssize_t item2)
{
int tmp;
tmp = array[item1];
array[item1] = array[item2];
array[item2] = tmp;
}
/**
 *lomuto_partition - lomuto partition sorting scheme implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: size array
 *Return: return the position of the last element sorted
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
int pivot;
ssize_t i, j;
pivot = array[last];
i = first - 1;
for (j = first; j <= last - 1; j++)
{
if (array[j] <= pivot)
{
i++;
if (i != j)
{
swap(array, i, j);
print_array(array, size);
}
}
}
if (array[last] < array[i + 1])
{
swap(array, i + 1, last);
print_array(array, size);
}
return (i + 1);
x}
/**
 *quicksort - qucksort algorithm implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: array size
 */
void quicksort(int *array, ssize_t first, ssize_t last, int size)
{
ssize_t pivot;
if (first < last)
{
pivot = lomuto_partition(array, first, last, size);
quicksort(array, first, pivot - 1, size);
quicksort(array, pivot + 1, last, size);
}
}
/**
 *quick_sort - prepare the terrain to quicksort algorithm
 *@array: array
 *@size: array size
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
quicksort(array, 0, size - 1, size);
}

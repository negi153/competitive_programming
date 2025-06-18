arr1 = [2,3,4,5,6]
arr2 = [3,4,9]

array 2 will be subset of array1, if all the elements of arr2 is present in array 1

Solution - 

    1. brute force - o(n*m) - iterate on each element of arr2 and check if that is present in arr1 or not.

    2. sorting - o(nlogn) - iterate on each element of arr2 and search in sorted arr1.

    3. hashmap - o(n) - store all the elements of arr1 and it's frequency in map. then iterate on arr2 and decrement the frequency from map if it exists.
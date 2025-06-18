question - we have array - 3,4,5,6,7,8,

return true or false if a+b = c+b satisfy in aabove arry.

solution
    1. brute force - 4 nested loop, check every possible combination and verify - o(n^4)
    2. optimize - 
        create pair of 2 elements in array by 2 nested loop.
        check if sum of 2 elements is present in map, then that means it exist.
        if sum of 2 elemnts is not present in map, then store the sum in map,
1. **Binary Search Introduction** 
- Binary search is only applicable in sorted array (it is that kind of algorithm only)
- Real Life Example :
We have a dictionary and we want to find a word "learning" then if we search page by page then it is a linear search algorithm, but if search a word in dictionary via binary search, then the algorithm will be in a way, we will each time divide the dictionary in half and we know dictionary is sorted so either in the half we will find out word or either it will be on right (if target word is higher then the mid page) or left(if target word is lesser then the mid page).
- Binary search code can be written iteratively or recursively.
- the time complexity id O(logn)
- For the overflow case : If at any point we will point the last index of the array and we are given the size as INT_MAX then if low = high = INT_MAX then mid = (low +high)/2 where (low + high) = 2*INT_MAX which cannot be stored in the int , so the alternative is to use long long instead of int else we can use mid = low+(high-low)/2.

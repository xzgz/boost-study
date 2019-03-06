//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
//You are given a target value to search. If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//Example 1:
//
//Input: nums = [4,5,6,7,0,1,2], target = 0
//Output: 4
//Example 2:
//
//Input: nums = [4,5,6,7,0,1,2], target = 3
//Output: -1

#include <vector>
#include <iostream>

using namespace std;


class Solution
{
 public:
  int search(const vector<int>& nums, int target)
  {
      int first = 0, last = nums.size() - 1;
      while (first != last + 1)
      {
          const int mid = first + (last - first) / 2;
          if (nums[mid] == target)
              return mid;
          if (nums[first] <= nums[mid])
          {
              if (nums[first] <= target && target < nums[mid])
                  last = mid;
              else
                  first = mid + 1;
          }
          else
          {
              if (nums[mid] < target && target <= nums[last])
                  first = mid + 1;
              else
                  last = mid;
          }
      }
      return -1;
  }
};


int main()
{
    int a[] = {2, 5, 6, 0, 1};
//    int a[] = {2,5,6,0,0,1,2};
    Solution solu;
    vector<int> vec_arr(a, a+5);
//    vector<int> vec_arr(a, a+7);
    int index = solu.search(vec_arr, 2);
    cout << "target index: " << index << endl;

    return 0;
}

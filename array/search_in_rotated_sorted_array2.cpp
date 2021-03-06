//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
//
//You are given a target value to search. If found in the array return true, otherwise return false.
//
//Example 1:
//
//Input: nums = [2,5,6,0,0,1,2], target = 0
//Output: true
//Example 2:
//
//Input: nums = [2,5,6,0,0,1,2], target = 3
//Output: false
//Follow up:
//
//This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
//Would this affect the run-time complexity? How and why?

#include <vector>
#include <iostream>

using namespace std;


class Solution
{
 public:
  bool search(const vector<int>& nums, int target)
  {
    int first = 0, last = nums.size() - 1;
    while (first != last + 1)
    {
      const int mid = first + (last - first) / 2;
      if (nums[mid] == target)
      {
        return true;
//        return mid;
      }
      if (nums[first] < nums[mid])
      {
        if (nums[first] <= target && target < nums[mid])
        {
          last = mid;
        }
        else
        {
          first = mid + 1;
        }
      }
      else if (nums[first] > nums[mid])
      {
        if (nums[mid] < target && target <= nums[last])
        {
          first = mid + 1;
        }
        else
        {
          last = mid;
        }
      }
      else
      {
        first++;
      }
    }
    return false;
//    return -1;
  }
};


int main()
{
    int a[] = {2, 2, 5, 6, 0, 1, 2};
    Solution solu;
    vector<int> vec_arr(a, a+7);
    bool index = solu.search(vec_arr, 6);
    cout << "target index: " << index << endl;

    return 0;
}

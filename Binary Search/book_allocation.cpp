/*Book Allocation
Given an array nums of n integers, where nums[i] represents the number of pages in the i-th book, 
and an integer m representing the number of students, 
allocate all the books to the students so that each student gets at least one book, 
each book is allocated to only one student, and the allocation is contiguous.

Allocate the books to m students in such a way that the maximum number of pages assigned to a student is minimized. 
If the allocation of books is not possible, return -1.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int> &nums, int pages) {
        int stu = 1, pagesStudent = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (pagesStudent + nums[i] <= pages) {
                pagesStudent += nums[i];
            } else {
                stu++;
                pagesStudent = nums[i];
            }
        }
        return stu;  
    }

    int findPages(vector<int> &nums, int m) {
        int n = nums.size();
        if (m > n) return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int students = countStudents(nums, mid);

            if (students > m) {
                low = mid + 1;
            } else {
                ans = mid;      
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {12, 34, 67, 90}; 
    int m = 2;
    int result = sol.findPages(nums, m);
    cout << "Minimum number of maximum pages allocated: " << result << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &nums, int m, int maxAllow)
{
   int student = 1, pages = 0;
   for (int i = 0; i < nums.size(); i++)
   {
      // Edge case
      if(nums[i] > maxAllow) return false;

      // Here pages allocating for students
      if(pages + nums[i]  <= maxAllow){
         pages += nums[i];
      }
      // Pages Allocate for next student, when exceeds the maxAllow
      else{
         student++;
         pages = nums[i];
      }
   }
   if(student == m){
      return true;
   }
   else return false;
   
}
int allocateBooks(vector<int>&nums, int m){
   if(m > nums.size()) return -1;
   int sum = 0;
   for (int i = 0; i < nums.size(); i++)
   {
      sum += nums[i];
   }
   int low = 0, high = sum, ans = -1;
   while(low <= high){
      int mid = low + (high - low) /2;
      if(isValid(nums, m, mid)){
         ans = mid;
         high = mid - 1;
      }
      else{
         low = mid + 1;
      }
   }
   return ans;
}
int main()
{
   vector<int> pages = {2, 1, 3, 4};
   int m = 2;
   cout<<allocateBooks(pages, m);
   
   
   return 0;
}

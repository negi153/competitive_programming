// find total occurance of a number in sorted array

#include <iostream>
#include<vector>
# include<algorithm>


using namespace std;

// time complexity -> o(log n) as it is using binary search to find first occurance and last occurance of an element.
void find_total_occurance_of_a_number(vector<int> &v, int target){

  int first_occurance_index = lower_bound(v.begin(),v.end(),target) - v.begin();
  int last_occurance_index = upper_bound(v.begin(),v.end(),target) - v.begin() -1;

  cout<<"first occurence is at index - "<<first_occurance_index<<endl;
  cout<<"last occurance is at index - "<<last_occurance_index<<endl;

  cout<<"Total occurance of target number - "<< last_occurance_index - first_occurance_index + 1<<endl;
}

int main() {
  vector<int> v{2,3,4,4,4,4,4,7,8};
  int target = 4;

  find_total_occurance_of_a_number(v,target);

  return 0;
}
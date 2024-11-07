#include <vector>
#include <util.h>
using namespace std;

void insertion_sort(vector<int>& array)
{
  if (array.size() <= 1)
    return;

  for (int i = 1; i < array.size(); i++) {
    int key = array[i];
    int ptr = i-1;
    while (ptr >= 0 && array[ptr] > key) {
      array[ptr+1] = array[ptr];
      ptr--;
    }
    array[ptr+1] = key;
  }
}

int main()
{
  vector<int> data = {55, 27, 36, 90, 1, 8, 47, 65, 87, 24, 30, 6};
  printContainer(data);

  insertion_sort(data);
  printContainer(data);
  return 0;
}
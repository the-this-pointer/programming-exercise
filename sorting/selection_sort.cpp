#include <vector>
#include <util.h>
using namespace std;

void swap(vector<int>& array, int u, int v) {
  int temp = array[u];
  array[u] = array[v];
  array[v] = temp;
}

void selection_sort(vector<int>& array)
{
  int minLoc = -1;
  for (int unsorted = 0; unsorted < array.size(); unsorted++)
  {
    minLoc = unsorted;
    for (int check = unsorted + 1; check < array.size(); check++)
    {
      if (array[check] < array[minLoc]) {
        minLoc = check;
      }
    }

    if (minLoc != unsorted)
    {
      swap(array, minLoc, unsorted);
    }
  }
}

int main()
{
  vector<int> data = {55, 27, 36, 90, 1, 8, 47, 65, 87, 24, 30, 6};
  printContainer(data);

  selection_sort(data);
  printContainer(data);
  return 0;
}
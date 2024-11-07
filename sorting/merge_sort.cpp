#include <vector>
#include <util.h>
using namespace std;

void merge(vector<int>& array, int from, int middle, int to)
{
  vector<int> temp; temp.resize(to-from+1);
  int i = from, j = middle+1, k, l = 0;
  for (k = from; k < to; k++) {
    temp[l++] = array[i] > array[j]? array[j++]: array[i++];
    if (i > middle) {
      for (; j <= to;) {
        temp[l++] = array[j++];
      }
      break;
    }
    if (j > to) {
      for (; i < middle + 1;) {
        temp[l++] = array[i++];
      }
      break;
    }
  }

  i = 0;
  for(const auto& elem: temp) {
    array[from + i] = temp[i];
    i++;
  }
}

void merge_sort(vector<int>& array, int from, int to)
{
  if (from < to) {
    int middle = (from + to) / 2;
    merge_sort(array, from, middle);
    merge_sort(array, middle+1, to);
    merge(array, from, middle, to);
  }
}

int main()
{
  vector<int> data = {55, 27, 36, 90, 1, 8, 47, 65, 87, 24, 30, 6};
  printContainer(data);

  merge_sort(data, 0, data.size()-1);
  printContainer(data);
  return 0;
}
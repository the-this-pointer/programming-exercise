#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  void deleteNode(ListNode* node) {
    ListNode* lastNode;
    while (node->next)
    {
      node->val = node->next->val;
      lastNode = node;
      node = node->next;
    }
    lastNode->next = nullptr;
  }
};

int main() {
  ListNode _9(9);
  ListNode _1(1); _1.next = &_9;
  ListNode _5(5); _5.next = &_1;
  ListNode _4(4); _4.next = &_5;

  Solution s;
  s.deleteNode(&_5);
  cout << "Output: " << endl;
  ListNode* ll = &_4;
  while(ll)
    cout << ll->val << " " << endl, ll = ll->next;
  getchar();
  return 0;
}

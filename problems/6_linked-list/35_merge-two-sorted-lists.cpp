#include "headers.hpp"

/*
Example 1:

Input: list1 = [1,2,4], list2 = [1,3,5]

Output: [1,1,2,3,4,5]

Example 2:

Input: list1 = [], list2 = [1,2]

Output: [1,2]

Example 3:

Input: list1 = [], list2 = []

Output: []
*/

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  ListNode dummy;
  ListNode *tail = &dummy;
  while (list1 && list2) {
    if (list1->val <= list2->val) {
      tail->next = list1;
      list1 = list1->next;
    } else {
      tail->next = list2;
      list2 = list2->next;
    }
    tail = tail->next; // advance tail in both cases
  }
  tail->next = list1 ? list1 : list2; // attach remainder once, after the loop
  return dummy.next;
}

#ifdef TESTING
#include <gtest/gtest.h>

ListNode *buildList(const vector<int> &values) {
  ListNode dummy;
  ListNode *tail = &dummy;
  for (int value : values) {
    tail->next = new ListNode(value);
    tail = tail->next;
  }
  return dummy.next;
}

vector<int> listToVector(ListNode *head) {
  vector<int> values;
  while (head) {
    values.push_back(head->val);
    head = head->next;
  }
  return values;
}

void deleteList(ListNode *head) {
  while (head) {
    ListNode *next = head->next;
    delete head;
    head = next;
  }
}

TEST(MergeTwoSortedLists, MergesInterleavedLists) {
  ListNode *list1 = buildList({1, 2, 4});
  ListNode *list2 = buildList({1, 3, 4});

  ListNode *merged = mergeTwoLists(list1, list2);

  EXPECT_EQ(listToVector(merged), (vector<int>{1, 1, 2, 3, 4, 4}));
  deleteList(merged);
}

TEST(MergeTwoSortedLists, ReturnsOtherListWhenOneInputIsEmpty) {
  ListNode *list2 = buildList({0, 5, 9});

  ListNode *merged = mergeTwoLists(nullptr, list2);

  EXPECT_EQ(listToVector(merged), (vector<int>{0, 5, 9}));
  deleteList(merged);
}

TEST(MergeTwoSortedLists, HandlesBothInputsEmpty) {
  ListNode *merged = mergeTwoLists(nullptr, nullptr);

  EXPECT_EQ(merged, nullptr);
}

TEST(MergeTwoSortedLists, PreservesDuplicatesAcrossLists) {
  ListNode *list1 = buildList({1, 1, 2});
  ListNode *list2 = buildList({1, 3, 3});

  ListNode *merged = mergeTwoLists(list1, list2);

  EXPECT_EQ(listToVector(merged), (vector<int>{1, 1, 1, 2, 3, 3}));
  deleteList(merged);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#else

int main() {
  return 0;
}

#endif
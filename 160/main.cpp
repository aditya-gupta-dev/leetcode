//
// Created by hyper on 26-09-2026.
//
#include <iostream>
#include <vector>

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::vector<ListNode*> first_vec;
        std::vector<ListNode*> second_vec;

        auto a_temp = headA;
        while (a_temp != nullptr) {
            first_vec.push_back(a_temp);
            a_temp = a_temp -> next;
        }

        auto b_temp = headB;
        while (b_temp != nullptr) {
            second_vec.push_back(b_temp);
            b_temp = b_temp -> next;
        }

        int i = static_cast<int>(first_vec.size() - 1);
        int j = static_cast<int>(second_vec.size() - 1);
        ListNode *last_common = nullptr;

        while (i >= 0 && j >= 0 && first_vec[i] == second_vec[j]) {
            last_common = first_vec[i];
            i--;
            j--;
        }

        return last_common;
    }
};
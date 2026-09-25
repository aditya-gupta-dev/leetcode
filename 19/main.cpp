#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            ListNode *prev = new ListNode(0, head);
            ListNode *slow = prev;
            ListNode *fast = prev;

            for (int i = 0; i < n; i++) {
                fast = fast->next;
            }

            while (fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next;
            }

            ListNode *removalNode = slow->next;
            slow->next = removalNode->next;

            delete removalNode;

            head = prev->next;
            return head;
        }
};

int main(void) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *temp = head;

    while (temp != nullptr) {
        std::cout << temp->val << " -> ";
        temp = temp->next;
    }
    std::cout << "\n";

    Solution sol;
    sol.removeNthFromEnd(head, 2);

    ListNode *dummy = head;
    while (dummy != nullptr) {
        std::cout << dummy->val << " -> ";
       dummy = dummy->next;
    }
    std::cout << "\n";
}

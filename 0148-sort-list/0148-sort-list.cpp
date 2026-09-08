class Solution {
public:

    ListNode* merge(ListNode* left, ListNode* right) {

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (left && right) {

            if (left->val < right->val) {
                tail->next = left;
                left = left->next;
            }
            else {
                tail->next = right;
                right = right->next;
            }

            tail = tail->next;
        }

        if (left) {
            tail->next = left;
        }

        if (right) {
            tail->next = right;
        }

        return dummy.next;
    }


    ListNode* sortList(ListNode* head) {

        // Base case
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {

            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Cut the list
        prev->next = nullptr;

        // Sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        // Merge
        return merge(left, right);
    }
};
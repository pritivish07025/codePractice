#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int i = 1;
        int sz = 0;
        int p0 = -1, p = -1;
        int minD = INT_MAX;

        int x0 = head->val;
        int x1 = head->next->val;

        bool less = x1 < x0;
        bool bigger = x1 > x0;

        for (ListNode* Next = head->next->next; Next != nullptr; i++, Next = Next->next) {
            int x = Next->val;
            bool bigger1 = x > x1;
            bool less1 = x < x1;

            // Check if current node is a critical point
            if ((less && bigger1) || (bigger && less1)) {
                if (sz == 0) p0 = i;
                sz++;
                if (p != -1) minD = min(i - p, minD);
                p = i;
            }

            bigger = bigger1;
            less = less1;
            x1 = x;
        }

        if (sz <= 1) return {-1, -1};
        return {minD, p - p0};
    }
};

int main() {
    vector<int> values = {5, 3, 1, 2, 5, 1, 2};

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int value : values) {
        ListNode* newNode = new ListNode(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Solution obj;
    vector<int> ans = obj.nodesBetweenCriticalPoints(head);

    cout << "Minimum Distance: " << ans[0] << endl;
    cout << "Maximum Distance: " << ans[1] << endl;

    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

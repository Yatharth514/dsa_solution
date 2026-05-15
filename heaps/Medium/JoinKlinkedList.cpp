class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int n = lists.size();
        if (n == 0)
            return NULL;
        if (n == 1)
            return lists[0];
        priority_queue<int, vector<int>, greater<int>> minh;
        for (int i = 0; i < n; i++)
        {
            ListNode *temp = lists[i];
            while (temp != NULL)
            {
                minh.push(temp->val);
                temp = temp->next;
            }
        }
        if (minh.empty())
            return NULL;
        ListNode *head = new ListNode(minh.top());
        ListNode *temp = head;
        minh.pop();
        while (!minh.empty())
        {
            int d = minh.top();
            minh.pop();
            ListNode *cur = new ListNode(d);
            temp->next = cur;
            temp = temp->next;
        }
        return head;
    }
};
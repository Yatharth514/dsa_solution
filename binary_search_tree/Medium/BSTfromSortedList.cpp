class Solution {
public:
    TreeNode*divide(ListNode*head)
    {
        if(!head)
        return NULL;
        else if(!head->next)
        {
            return new TreeNode(head->val);
        }
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*mid=NULL;
        while(fast&&fast->next)
        {  
            mid=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        mid->next=NULL;
        TreeNode* root=new TreeNode(slow->val);
        ListNode*temp=slow->next;
        root->left=divide(head);
        root->right=divide(temp);
        return root;


    }
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode*root=NULL;
        root=divide(head);
        return root;
        
    }
};
class Solution {
  public:
    int countNodes(Node*tree)
    {
        if(!tree)
        return 0;
        int leftTree=countNodes(tree->left);
        int rightTree=countNodes(tree->right);
        
        return 1+leftTree+rightTree;
    }
    bool isCBT(Node* tree,int index,int total)
    {
        if(!tree)
        return true;
        
        if(index>total)
        return false;
        
        bool leftTree=isCBT(tree->left,2*index,total);
        bool rightTree=isCBT(tree->right,2*index+1,total);
        
        return leftTree && rightTree;
    }
    bool isMaxHeap(Node* tree)
    {
        if(!tree)
        return true;
        
        if(tree->left&&tree->right)
        {
           if((tree->left)->data>tree->data||(tree->right)->data>tree->data)
           return false;
           else
           return isMaxHeap(tree->left)&&isMaxHeap(tree->right);
        }
        else if(tree->left)
        {
            if((tree->left)->data>tree->data)
            return false;
            else
            return isMaxHeap(tree->left);
        }
        else if(tree->right)
        {
            if((tree->right)->data>tree->data)
            return false;
            else
            return isMaxHeap(tree->right);
        }
        else
        {
            return true;
        }
        
    }
    
    bool isHeap(Node* tree) {
        // code here
        if(!tree)
        return true;
        if(!isCBT(tree,1,countNodes(tree)))
        return false;
        
        return isMaxHeap(tree);
        
    }
};
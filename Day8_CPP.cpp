class Solution {
public:
    int answer;
    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL)
            return 0;
        answer = 0;
        string curr = "";
        traverse(root, curr);
        return answer;
    }

    void traverse(TreeNode* root, string curr)
    {
        if(root == NULL)
            return;


        if(root->left == NULL and root->right == NULL)
        {
            curr+=to_string(root->val);
            answer+=convertToNum(curr);
            return;
        }
       // cout << root->val << endl;
        curr+=to_string(root->val);
        traverse(root->left, curr);
        traverse(root->right, curr);
    }



    int convertToNum(string s)
    {
        int number = 0;
        int powCount = 0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i] == '1')
                number = number + pow(2, powCount);
            powCount++;
        }
        return number;
    }
};


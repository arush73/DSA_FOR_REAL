#include <bits/stdc++.h>
using namespace std;

vector<int> preOrderTraversal(TreeNode *root)
{
    vector<int> preOrder;
    if (root == NULL)
        return preOrder;

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        root = st.pop();

        st.pop();
        preOrder.push_back(root->val);
        if (root->right != NULL)
        {
            st.push(root->right);
        }
        if (root->left != NULL)
        {
            st.push(root->left);
        }
        return preOrder;
    }
}

int main()
{

    return 0;
}
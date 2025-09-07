#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) return root; 
    return left ? left : right;     
}

TreeNode* buildTree(vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    TreeNode* left = findNode(root->left, val);
    if (left) return left;
    return findNode(root->right, val);
}

int main() {
    int n;
    cout << "Enter number of nodes in level-order (use -1 for null): ";
    cin >> n;

    vector<int> nodes(n);
    cout << "Enter tree nodes in level-order: ";
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }

    int pVal, qVal;
    cout << "Enter value of node p: ";
    cin >> pVal;
    cout << "Enter value of node q: ";
    cin >> qVal;

    TreeNode* root = buildTree(nodes);
    TreeNode* p = findNode(root, pVal);
    TreeNode* q = findNode(root, qVal);

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca) {
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    } else {
        cout << "LCA not found." << endl;
    }

    return 0;
}

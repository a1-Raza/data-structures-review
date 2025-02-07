#include <iostream>
#include <queue>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void traverseTree(TreeNode* node, int method){
    if (!node) return;

    if (method == 0){ // preorder
        cout << node->val << " ";
        traverseTree(node->left, method);
        traverseTree(node->right, method);
    }

    else if (method == 1){ // inorder
        traverseTree(node->left, method);
        cout << node->val << " ";
        traverseTree(node->right, method);
    }

    else if (method == 2){ // postorder
        traverseTree(node->left, method);
        traverseTree(node->right, method);
        cout << node->val << " ";
    }
}

void levelOrderTraverse(queue<TreeNode*>& nodeQueue) {
    if (nodeQueue.empty()) return;

    TreeNode* currentNode = nodeQueue.front();
    nodeQueue.pop();
    cout << currentNode->val << " ";
    
    if (currentNode->left) nodeQueue.push(currentNode->left);
    if (currentNode->right) nodeQueue.push(currentNode->right);
    
    levelOrderTraverse(nodeQueue);
}

int heightBalanceCheck(TreeNode* node){ // return -1 if not height-balanced
    if (!node) return 0;
    int leftHeight = heightBalanceCheck(node->left);
    if (leftHeight == -1) return -1;
    int rightHeight = heightBalanceCheck(node->right);
    if (rightHeight == -1) return -1;
    if (abs(leftHeight - rightHeight) > 1) return -1;
    return max(leftHeight, rightHeight) + 1;
}

TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* n1, TreeNode* n2){
    if (!node) return nullptr;

    if (node == n1 || node == n2) return node;

    TreeNode* left = lowestCommonAncestor(node->left, n1, n2);
    TreeNode* right = lowestCommonAncestor(node->right, n1, n2);
    if (left && right) return node;
    
    return left ? left : right;
}

int main(int argc,char **argv) {

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);

    /*traverseTree(root1, 0);
    cout << endl;
    traverseTree(root1, 1);
    cout << endl;
    traverseTree(root1, 2);
    cout << endl;
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root1);
    levelOrderTraverse(nodeQueue);
    cout << endl;*/

    cout << heightBalanceCheck(root1) << endl;

    return 0;

}
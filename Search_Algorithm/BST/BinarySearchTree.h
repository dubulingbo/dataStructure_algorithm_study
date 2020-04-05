//
// Created by DubLBo on 2020/2/23.
//

#ifndef BST_BINARY_SEARCH_TREE_H
#define BST_BINARY_SEARCH_TREE_H

#include<iostream>
#include<queue>
#include <cassert>
// 二分搜索树
// 二叉树，不一定是完全二叉树
// 每个节点的键值大于左孩子，每个节点的键值小于右孩子
// 以左右孩子为根的子树仍为二分搜索树
template<typename Key, typename Value>
class BST {
private :
    struct Node {
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            left = right = NULL;
        }

        Node(Node* node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };

    int count;
    Node *root;

public :
    BST() {
        count = 0;
        root = NULL;
    }

    ~BST() {
        destroy(root);
    }

    int size() { return count; }

    bool isEmpty() { return count == 0; }

    // 插入操作
    void insert(Key key, Value value) {
        root = insert(root, key, value);
    }

    // 查找操作
    Value *search(Key key) {
        return search(root, key);
    }

    // 包含操作
    bool contain(Key key) {
        return contain(root, key);
    }

    // 遍历操作
    // 1.前序遍历操作
    void preOrder() { preOrder(root); }

    // 2.中序遍历操作
    void inOrder() { inOrder(root); }

    // 3.后序遍历操作
    void postOrder() { postOrder(root); }

    // 层序遍历
    void levelOrder() {
        std::queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            Node *node = q.front();
            q.pop();

            std::cout << node->key << std::endl;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    // 删除最小值节点
    void removeMin() { if (root) root = removeMin(root); }

    // 删除最大键值节点
    void removeMax() { if (root) return removeMax(root); }

    // 寻找最小的键值
    Key minimum() {
        assert(count != 0);
        Node *minNode = minimum(root);
        return minNode->key;
    }

    // 寻找最大的键值
    Key maximum() {
        assert(count != 0);
        Node *maxNode = maximum(root);
        return maxNode->key;
    }

    // 删除任意节点
    void removeNode(Key key){

        root = removeNode(root,key);
    }



private :
    // 向以 node 为根的二叉搜索树中，插入节点 (key,value)
    // 返回插入新节点后的二叉搜索树的根
    // 递归实现
    Node *insert(Node *node, Key key, Value value) {
        if (node == NULL) {
            ++count;
            return new Node(key, value);
        }

        if (key == node->key)
            node->value = value;
        else if (key < node->key)
            node->left = insert(node->left, key, value);
        else
            node->right = insert(node->right, key, value);

        return node;
    }

    // 查看以 node 为根的二叉搜索树中是否包含键值为 key 的节点
    // 递归实现
    bool contain(Node *node, Key key) {
        if (node == NULL)
            return false;

        if (key == node->key)
            return true;
        else if (key < node->key)
            return contain(node->left, key);
        else
            return contain(node->right, key);
    }

    // 在以 node 为根的二叉搜索树中查找 key 对应的 value
    // 递归实现
    Value *search(Node *node, Key key) {
        if (node == NULL)
            return NULL;
        if (key == node->key)
            return &(node->value);
        else if (key < node->key)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    // 先遍历根节点，再左子树，最后右子树
    void preOrder(Node *node) {
        if (node != NULL) {
            std::cout << node->key << std::endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    // 先遍历左子树，再遍历根节点，最后遍历右子树
    void inOrder(Node *node) {
        if (node != NULL) {
            inOrder(node->left);
            std::cout << node->key << std::endl;
            inOrder(node->right);
        }
    }

    // 先遍历左子树，再遍历右子树，最后遍历根节点
    void postOrder(Node *node) {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            std::cout << node->key << std::endl;
        }
    }

    // 释放节点 node 的所占空间
    void destroy(Node *node) {
        if (node != NULL) {
            destroy(node->left);
            destroy(node->right);
            delete node;
            --count;
        }
    }

    // 在以 node 为根的二叉搜索树中，返回最小键值的节点
    Node *minimum(Node *node) {
        if (node->left = NULL)
            return node;
        return minimum(node->left);
    }

    // 在以 node 为根的二叉搜索树中，返回最大键值的节点
    Node *maximum(Node *node) {
        if (node->right == NULL)
            return node;
        return maximum(node->right);
    }

    // 删除以 node 为根的二分搜索树中最小节点
    // 返回删除节点后新的二分搜索树的根
    Node *removeMin(Node *node) {
        if (node->left == NULL) {
            Node *rightNode = node->right;
            delete node;
            --count;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }

    // 删除以 node 为根的二分搜索树中最大节点
    // 返回删除节点后新的二分搜索树的根
    Node *removeMax(Node *node) {
        if (node->right == NULL) {
            Node *leftNode = node->left;
            delete node;
            --count;
            return leftNode;
        }
        node->right = removeMax(node->right);
        return node;
    }

    // 删除以 node 为根的二分搜索树中键值为 key 的节点
    // 返回删除节点后新的二分搜索树的根
    Node* removeNode(Node* node,Key key){
        if(node == NULL) return NULL;

        if(key < node->key){
            node->left = removeNode(node->left,key);
            return node;
        }
        else if(key > node->key){
            node->right = removeNode(node->right,key);
            return node;
        }
        else{  // key == node->key
            // 1.该节点没有左子树
            if(node->left == NULL){
                Node* rightNode = node->right;
                delete node;
                -- count;
                return rightNode;
            }
                // 2.该节点没有右子树
            else if(node->right == NULL){
                Node* leftNode = node->left;
                delete node;
                -- count;
                return leftNode;
            }
            else{
                // 3.该节点有左右子树
                // 法一：寻找右子树中键值最小的节点，替代当前要删除的节点
                // 法二：寻找左子树中键值最大的节点，替代当前要删除的节点

                Node* minRightNode = new Node(minimum(node->right)); //拷贝一份当前节点右子树中最小值的节点，因为待会要将最小值的节点删除
                ++ count;
                minRightNode->right = removeMin(node->right);
                minRightNode->left = node->left;
                delete node;
                -- count;
                return minRightNode;

                /*
                Node* maxLeftNode = new Node(maximum(node->left));
                ++ count;
                maxLeftNode->left = removeMax(node->left);
                maxLeftNode->right = node->right;
                delete node;
                -- count;
                return maxLeftNode;
                 */
            }

        }
    }
};

#endif //BST_BINARY_SEARCH_TREE_H

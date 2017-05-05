
#ifndef _BINRAYSEARCHTREE_H_
#define _BINRAYSEARCHTREE_H_

#include <memory>

namespace DS
{

    /// TreeNode is a struct that holds the value of the elements of the list
    /// and maintains links to the left and right nodes of the Binary Search Tree.
    template<typename K>
    struct TreeNode;

    template<typename K>
    typedef std::unique_ptr<TreeNode<K>> PTreeNode;

    template<typename K>
    struct TreeNode
    {
        TreeNode(const K& key): m_key(key), m_right(NULL), m_left(NULL), m_parent(NULL) {}

        PTreeNode m_right;
        PTreeNode m_left;
        PTreeNode m_parent;

        K m_key;
    };


    template<typename K>
    class BST
    {
        public:
            /// Method that does the in order transversal on the Binary Search Tree.
            void InOrderTreeWalk() const;

            void PostOrderTreeWalk() const;

            void PreOrderTreeWalk() const;

            PTreeNode& Search(K key) const;

            PTreeNode& Minimum() const;

            PTreeNode& Maximum() const;

            PTreeNode& Successor(PTreeNode& node);

            PTreeNode& Predecessor(PTreeNode& node);

            void Insert(PTreeNode& node);

            void Delete(PTreeNode& node);


        private:

            void Transplant(PTreeNode& u, PTreeNode& v);

            /// Pointer to the root element.
            PTreeNode m_root;

    };
}

template<typename K>
void DS::BST<K>::Insert(PTreeNode& node)
{
    assert(node);
    assert(node->key);

    if (m_root == NULL)
    {
        m_root = node;
    }

    TreeNode<K>* curr = m_root;
    TreeNode<K>* prev = NULL;

    while (curr != NULL)
    {
        prev = curr;
        if (curr->key >= node->key)
        {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    node->parent = prev;
    if (prev->key >= node->key)
    {
        prev->left = node;
    } else {
        prev->right = node;
    }
}

#endif

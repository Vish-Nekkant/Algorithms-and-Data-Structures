
#include "gtest/gtest.h"
#include "BST.hpp"
    
using namespace DS;

/// @brief simple test to test the insertion, inserting NULL Node or Node with NULL key
/// results assertion violation.
TEST(BSTTest, InsertingNullNode)
{
    BST<unsigned int> bst;

    // can't add Null element to tree.
    ASSERT_DEATH(bst.Insert(NULL), "");

    TreeNode<unsigned int>* node = new TreeNode<unsigned int>;
    ASSERT_DEATH(bst.Insert(node), "");
    delete node;
}
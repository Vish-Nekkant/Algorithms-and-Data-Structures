#include "gtest\gtest.h"
#include "List.hpp"

/// Unit tests to check the list<int> methods
/// for empty(), size(), push_front(), push_back()
/// and pop_front() and pop_back().
TEST(List_Test, test1)
{
    DS::List<int> m_list;

    //list should be empty;
    ASSERT_TRUE(m_list.empty());
    ASSERT_EQ(0, m_list.size());

    m_list.push_front(3);
    ASSERT_EQ(1, m_list.size());
    ASSERT_EQ(3, m_list.pop_back());

    //list should be empty;
    ASSERT_TRUE(m_list.empty());
    ASSERT_EQ(0, m_list.size());

    m_list.push_back(3);
    ASSERT_EQ(1, m_list.size());
    ASSERT_EQ(3, m_list.pop_back());

    //list should be empty;
    ASSERT_TRUE(m_list.empty());
    ASSERT_EQ(0, m_list.size());

    m_list.push_front(15);
    m_list.push_back(20);
    m_list.push_back(30);
    ASSERT_EQ(3, m_list.size());

    m_list.push_front(4);
    m_list.push_front(5);
    ASSERT_EQ(5, m_list.size());

    ASSERT_EQ(30, m_list.pop_back());
    ASSERT_EQ(5, m_list.pop_front());
    ASSERT_EQ(3, m_list.size());

    m_list.push_front(1);

    ASSERT_EQ(20, m_list.pop_back());
    ASSERT_EQ(1, m_list.pop_front());
    ASSERT_EQ(4, m_list.pop_front());
    ASSERT_EQ(15, m_list.pop_front());

    //list should be empty;
    ASSERT_TRUE(m_list.empty());
    ASSERT_EQ(0, m_list.size());

    //Since list is empty, it should return 
    // NULL While poping back or front.
    ASSERT_EQ(NULL, m_list.pop_back());
    ASSERT_EQ(NULL, m_list.pop_front());
}

/// Unit test to test the lists reverse method
TEST(List_Test, reverseMethodTest)
{
    DS::List<int> m_list;

    m_list.print();

    //std::cout << m_list;

    // reverse an empty list and retrieving should return NULL elements.
    m_list.reverse();
    m_list.print();
    ASSERT_EQ(NULL, m_list.pop_front());

    // Reversing single elments.
    m_list.push_front(1);
    m_list.print();
    ASSERT_EQ(1, m_list.size());
    m_list.reverse();
    m_list.print();
    ASSERT_EQ(1, m_list.pop_front());
    ASSERT_EQ(0, m_list.size());
    m_list.print();


    // push front 1, 2, 3, 4, 5
    // reverse , then pop front should return
    // the elements 5 4 3 2 1 in that order
    m_list.push_front(1);
    m_list.push_front(2);
    m_list.push_front(3);
    m_list.push_front(4);
    m_list.push_front(5);
    m_list.print();
    m_list.reverse();
    m_list.print();
    ASSERT_EQ(1, m_list.pop_front());
    ASSERT_EQ(2, m_list.pop_front());
    ASSERT_EQ(3, m_list.pop_front());
    ASSERT_EQ(4, m_list.pop_front());
    ASSERT_EQ(5, m_list.pop_front());
    ASSERT_EQ(0, m_list.size());

    // push back 1, 2, 3, 4, 5
    // reverse , then pop back should return
    // the elements 5 4 3 2 1 in that order
    m_list.push_back(1);
    m_list.push_back(2);
    m_list.push_back(3);
    m_list.push_back(4);
    m_list.push_back(5);
    m_list.print();
    m_list.reverse();
    m_list.print();
    ASSERT_EQ(1, m_list.pop_back());
    ASSERT_EQ(2, m_list.pop_back());
    ASSERT_EQ(3, m_list.pop_back());
    ASSERT_EQ(4, m_list.pop_back());
    ASSERT_EQ(5, m_list.pop_back());
    ASSERT_EQ(0, m_list.size());

    // push front 1, 2, 3, 4, 5
    // reverse , then pop back should return
    // the elements 5 4 3 2 1 in that order
    m_list.push_back(1);
    m_list.push_back(2);
    m_list.push_back(3);
    m_list.push_back(4);
    m_list.push_back(5);
    m_list.print();
    m_list.reverse();
    m_list.print();
    ASSERT_EQ(5, m_list.pop_front());
    ASSERT_EQ(4, m_list.pop_front());
    ASSERT_EQ(3, m_list.pop_front());
    ASSERT_EQ(2, m_list.pop_front());
    ASSERT_EQ(1, m_list.pop_front());
    ASSERT_EQ(0, m_list.size());

}
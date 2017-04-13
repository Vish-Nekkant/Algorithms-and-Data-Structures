
#ifndef _MYLIST_H_
#define _MYLIST_H_

#include <iostream>

namespace DS
{
    /// Node is a struct that holds the value of the elements of the list
    /// and maintains links to the left and right nodes in the list.
    template<typename ElementType>
    struct Node
    {
        Node()
        {
            next = NULL;
            prev = NULL;
            element = NULL;
        }

        Node* next;
        Node* prev;
        ElementType element;
    };
   
    template<typename ElementType>
    class List
    {
        public:

            /// Constructor of the list.
            /// When the list is empty, all the head, tail and curr points
            /// to a Dummy node that has null value. It is just a place holder.
            List();

            /// Destructor
            ~List();

            /// Retruns true if the list is empty.
            bool empty();

            /// Removes the last element of the list.
            /// 
            /// @return an element of type ElementType 
            ElementType pop_back();

            /// Removes the front element of the list.
            /// 
            /// @return an element of type ElementType.
            ElementType pop_front();

            /// Adds the element to the back of the list.
            /// 
            /// @param element that has to be appended.
            void push_back(const ElementType& element);

            /// Adds the elment to the fron to the list.
            /// 
            /// @param element that has to be appended.
            void push_front(const ElementType& element);

            /// Remove all the elements that are equal to elements from the lsit.
            ///
            /// @param element that has to be removed.
            void remove(const ElementType& element);

            /// Reverse the order the elements in the list
            /// 
            void reverse();

            /// Returns the size of this list. Zero if list is empty.
            /// 
            /// @return size, current size of the list.
            size_t size();

            /// Prints the elements in the list to the standard output
            /// 
            void print();

        private:
            Node<ElementType>* m_head;
            Node<ElementType>* m_tail;
            size_t m_size;
    };

    /// Constructor of the list
    template <typename ElementType>
    List<ElementType>::List()
    {
        m_size = 0;
        // head always points to the sentinel node.
        // List is empty if head and tail point to 
        // same sentinel node. Using Sentinel incurs extra
        // space, but it eliminates lots of code checking!
        Node<ElementType>* temp = new Node<ElementType>();
        m_head = temp;
        m_tail = m_head;

        m_head->next = NULL;
        m_head->prev = NULL;
        m_head->element = NULL;
    }

    /// Destructor of the list
    template <typename ElementType>
    List<ElementType>::~List()
    {
        while (NULL != pop_back())
        {
            // Do nothing;
        }

        // Still have to delete the sentinel.
        delete m_head;
    }

    /// Implementation of empty() 
    template <typename ElementType>
    inline bool List<ElementType>::empty()
    {
        assert(m_size >= 0);

        return (m_size == 0);
    }

    /// Implementation of size
    template <typename ElementType>
    inline size_t List<ElementType>::size()
    {
        assert(m_size >= 0);

        return m_size;
    }

    /// Implementation of push_front
    template <typename ElementType>
    inline void List<ElementType>::push_front(const ElementType& element)
    {
        // Create new Node with the element
        Node<ElementType>* temp = new Node<ElementType>;
        temp->element = element;

        // Attach the new node to the list.
        temp->next = m_head->next;
        temp->prev = m_head;

        // Update the links in the list
        if (temp->next != NULL)
        {
            temp->next->prev = temp;
        }
        m_head->next = temp;

        // if the list is empty, tail has to be moved to point the newly inserted
        // element.
        if (m_head == m_tail)
        {
            m_tail = temp;
        }

        m_size++;
    }

    /// implementation of push_back.
    template <typename ElementType>
    inline void List<ElementType>::push_back(const ElementType& element)
    {
        assert(m_size >= 0);

        // Create new Node with the element
        Node<ElementType>* temp = new Node<ElementType>;
        temp->element = element;

        // Insert the element into the list.
        temp->next = NULL;
        temp->prev = m_tail;
        temp->prev->next = temp;
        // move the tail on to the newly attached element.
        m_tail = temp;

        m_size++;
    }

    /// implementation of pop_back.
    template <typename ElementType>
    inline ElementType List<ElementType>::pop_back()
    {
        assert(m_size >= 0);
        
        // If the list is empty return null.
        if (m_head == m_tail)
        {
            return NULL;
        }

        /// At this stage there will be atleast one element
        m_tail = m_tail->prev;
        ElementType element = m_tail->next->element;
        delete m_tail->next;
        m_size--;
        m_tail->next = NULL;
        return element;
    }

    /// implementation of pop_front.
    template <typename ElementType>
    inline ElementType List<ElementType>::pop_front()
    {
        assert(m_size >= 0);

        if (m_head == m_tail)
        {
            return NULL;
        }

        /// At this stage there will be atleast one element
        Node<ElementType>* temp = m_head->next;

        m_head->next = m_head->next->next;
        if (m_head->next != NULL)
        {
            m_head->next->prev = m_head;
        }

        ElementType element = temp->element;
        delete temp;
        m_size--;

        // If list is empty, then tail
        // has to be made pointed to sentinel.
        if (m_head->next == NULL)
        {
            m_tail = m_head;
            assert(m_size == 0);
        }

        return element;
    }

    /// Implementation of list reverse, 
    /// reverses the elements in place
    template <typename ElementType>
    inline void List<ElementType>::reverse()
    {
        // if list is empty, then just return
        if (m_head == m_tail)
        {
            return;
        }

        // Move the head to the back of the list
        m_tail->next = m_head;
        m_head->next->prev = NULL;
        m_head->next = m_tail;

        // update the links of the nodes
        Node<ElementType>* curr = m_head;
        while (curr->next != NULL)
        {
            Node<ElementType>* temp = curr->next->prev;
            curr->next->prev = curr;
            curr->next->next = temp;
            curr = curr->next;
        }

        // update the tail
        // if curr->next is true then it is tail
        m_tail = curr;
    }

    // implementation of printing the list
    template <typename ElementType>
    inline void List<ElementType>::print()
    {
        std::cout << std::endl << "head -> ";
        Node<ElementType>* curr = m_head->next;
        while (curr != NULL)
        {
            std::cout << curr->element << " -> ";
            curr = curr->next;
        }
        std::cout << " tail " << std::endl;
    }
}

#endif

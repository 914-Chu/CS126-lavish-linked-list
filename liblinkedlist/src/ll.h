#ifndef LL_H
#define LL_H

#include <iostream>
#include <vector>
#include <exception>

using namespace std;

namespace cs126linkedlist {
/*
 *  Declare any struct, class, or enum types you need to use here
 */

    //Linked List Node
    template<typename ElementType>
    struct LinkedListNode {
        ElementType data_;
        LinkedListNode* next_;
        LinkedListNode();
        LinkedListNode(ElementType data);
        LinkedListNode(ElementType data, LinkedListNode next);
        bool operator!=(const LinkedListNode<ElementType> &node) const;
    };

    // Template linked list class
    template<typename ElementType>
    class LinkedList {
    /*
     *  Declare any struct, class, or enum types you need to use here
     */
    private:
        int size_;
        LinkedListNode<ElementType> *head_;
        LinkedListNode<ElementType> *tail_;
    public:
        LinkedList();                                                   // Default constructor
        explicit LinkedList(const std::vector<ElementType> &values);    // Initilize from vector

        // Big 5
        LinkedList(const LinkedList &source);                                           // Copy constructor
        LinkedList(LinkedList &&source) noexcept;                                       // Move constructor
        ~LinkedList();                                                                  // Destructor
        LinkedList<ElementType> &operator=(const LinkedList<ElementType> &source);      // Copy assignment operator
        LinkedList<ElementType> &operator=(LinkedList<ElementType> &&source) noexcept;  // Move assignment operator

        void PushFront(ElementType value);                                       // Push value on front
        void PushBack(ElementType value);                                        // Push value on back
        ElementType front() const throw(exception);                       // Access the front value
        ElementType back() const throw(exception);                        // Access the back valueW
        void PopFront();                                                         // remove front element
        void PopBack();                                                          // remove back element
        void Remove(LinkedListNode<ElementType> *node);                          // remove element at the node
        int size() const;                                                        // return number of elements
        bool empty() const;                                                      // check if empty
        void Clear();                                                            // clear the contents
        void RemoveOdd();                                                        // remove the odd elements from the list 0 indexed
        bool operator==(const LinkedList<ElementType> &rhs) const;

        // iterator
        class iterator : std::iterator<std::forward_iterator_tag, ElementType> {
            LinkedListNode<ElementType> *current_;
        public:
            iterator() : current_(nullptr) {};

            iterator(LinkedListNode<ElementType> *ptr) { current_ = ptr; };

            iterator &operator++();

            ElementType &operator*() const;

            bool operator!=(const iterator &other) const;

            bool operator==(const iterator &other) const;
        };

        iterator begin();

        iterator end();

        // const_iterator
        class const_iterator : std::iterator<std::forward_iterator_tag, ElementType> {
            const LinkedListNode<ElementType> *current_;
        public:
            const_iterator() : current_(nullptr) {};

            const_iterator(LinkedListNode<ElementType> *ptr) { current_ = ptr; };

            const_iterator &operator++();

            const ElementType &operator*() const;

            bool operator!=(const const_iterator &other) const;

            bool operator==(const const_iterator &other) const;
        };

        const_iterator begin() const;

        const_iterator end() const;
    };

    template<typename ElementType>
    std::ostream &operator<<(std::ostream &os, const LinkedList<ElementType> &list);

    template<typename ElementType>
    bool operator!=(const LinkedList<ElementType> &lhs, const LinkedList<ElementType> &rhs);


} // namespace cs126linkedlist

// Needed for template instantiation
#include "ll.hpp"

#endif //LL_H

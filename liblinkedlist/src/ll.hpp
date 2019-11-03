#include <utility>
#include <cassert>
#include "ll.h"

namespace cs126linkedlist {
    template<typename ElementType>
    LinkedList<ElementType>::LinkedList() {
        this->size = 0;
        this->empty = true;
        this->begin() = NULL;
    }

    template<typename ElementType>
    LinkedList<ElementType>::LinkedList(const std::vector<ElementType> &values) {
        this->size = values.size();
        LinkedListNode* head = new LinkedListNode;
        head->data = values[0];
        head->next = new LinkedListNode;
        this->begin() = head;
        for(int i = 1; i < values.size(); i++){
            push_back(values[i]);
        }
    }

    // Copy constructor
    template<typename ElementType>
    LinkedList<ElementType>::LinkedList(const LinkedList<ElementType> &source) {

    }

    // Move constructor
    template<typename ElementType>
    LinkedList<ElementType>::LinkedList(LinkedList<ElementType> &&source) noexcept {

    }

    // Destructor
    template<typename ElementType>
    LinkedList<ElementType>::~LinkedList() {
    }

    // Copy assignment operator
    template<typename ElementType>
    LinkedList<ElementType> &LinkedList<ElementType>::operator=(const LinkedList<ElementType> &source) {

    }

    // Move assignment operator
    template<typename ElementType>
    LinkedList<ElementType> &LinkedList<ElementType>::operator=(LinkedList<ElementType> &&source) noexcept {

    }

    template<typename ElementType>
    void LinkedList<ElementType>::push_front(ElementType value) {
        LinkedListNode temp = new LinkedListNode;
        temp.data = value;
        temp.next = this->begin();
        this->begin() = temp;
    }

    template<typename ElementType>
    void LinkedList<ElementType>::push_back(ElementType value) {
        LinkedListNode temp = new LinkedListNode;
        temp.data = value;
        temp.next = this->end();
        this->end() = temp;
    }

    template<typename ElementType>
    ElementType LinkedList<ElementType>::front() const {

    }

    template<typename ElementType>
    ElementType LinkedList<ElementType>::back() const {

    }

    template<typename ElementType>
    void LinkedList<ElementType>::pop_front() {

    }

    template<typename ElementType>
    void LinkedList<ElementType>::pop_back() {

    }

    template<typename ElementType>
    int LinkedList<ElementType>::size() const {

    }

    template<typename ElementType>
    bool LinkedList<ElementType>::empty() const {

    }

    template<typename ElementType>
    void LinkedList<ElementType>::clear() {

    }

    template<typename ElementType>
    std::ostream &operator<<(std::ostream &os, const LinkedList<ElementType> &list) {

    }

    template<typename ElementType>
    void LinkedList<ElementType>::RemoveOdd() {

    }

    template<typename ElementType>
    bool LinkedList<ElementType>::operator==(const LinkedList<ElementType> &rhs) const {

    }

    template<typename ElementType>
    bool operator!=(const LinkedList<ElementType> &lhs, const LinkedList<ElementType> &rhs) {

    }

    template<typename ElementType>
    typename LinkedList<ElementType>::iterator &LinkedList<ElementType>::iterator::operator++() {

    }

    template<typename ElementType>
    ElementType &LinkedList<ElementType>::iterator::operator*() const {

    }

    template<typename ElementType>
    bool LinkedList<ElementType>::iterator::operator!=(const LinkedList<ElementType>::iterator &other) const {

    }

    template<typename ElementType>
    typename LinkedList<ElementType>::iterator LinkedList<ElementType>::begin() {

    }

    template<typename ElementType>
    typename LinkedList<ElementType>::iterator LinkedList<ElementType>::end() {

    }

    template<typename ElementType>
    typename LinkedList<ElementType>::const_iterator &LinkedList<ElementType>::const_iterator::operator++() {

    }

    template<typename ElementType>
    const ElementType &LinkedList<ElementType>::const_iterator::operator*() const {

    }

    template<typename ElementType>
    bool
    LinkedList<ElementType>::const_iterator::operator!=(const LinkedList<ElementType>::const_iterator &other) const {

    }

    template<typename ElementType>
    typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::begin() const {

    }

    template<typename ElementType>
    typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::end() const {

    }

}
#include <utility>
#include <cassert>
#include "ll.h"

using namespace std;


namespace cs126linkedlist {

    template <typename ElementType>
    LinkedListNode<ElementType>::LinkedListNode() {
        data_ = NULL;
        next_ = NULL;
    }

    template <typename ElementType>
    LinkedListNode<ElementType>::LinkedListNode(ElementType data) {
        data_ = data;
        next_ = NULL;
    }

    template <typename ElementType>
    LinkedListNode<ElementType>::LinkedListNode(ElementType data, LinkedListNode next) {
        data_ = data;
        next_ = next;
    }

    template<typename ElementType>
    LinkedList<ElementType>::LinkedList() {
        size_ = 0;
        head_ = new LinkedListNode<ElementType>();
        tail_ = new LinkedList();
    }

    template<typename ElementType>
    LinkedList<ElementType>::LinkedList(const std::vector<ElementType> &values) {
        size_ = values.size();
        for(int i = 0; i < values.size(); i++){
            push_back(values[i]);
        }
    }

    // Copy constructor
    template<typename ElementType>
    LinkedList<ElementType>::LinkedList(const LinkedList<ElementType> &source) {
        if(source == nullptr) {
            return;
        }

        LinkedListNode<ElementType> *temp = source.begin().current();
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
        LinkedListNode<ElementType> *temp = new LinkedListNode<ElementType>(value,head_);
        head_ = temp;
        size_++;
    }

    template<typename ElementType>
    void LinkedList<ElementType>::push_back(ElementType value) {
        LinkedListNode<ElementType> *temp = new LinkedListNode<ElementType>(value);
        if(head_ == NULL){
            head_ = temp;
            tail_ = temp;
        }else {
            tail_->next_ = temp;
            tail_ = tail_->next_;
        }
        size_++;
    }

    template<typename ElementType>
    ElementType LinkedList<ElementType>::front() const {
        return head_->data_;
    }

    template<typename ElementType>
    ElementType LinkedList<ElementType>::back() const {
        return tail_->data_;
    }

    template<typename ElementType>
    void LinkedList<ElementType>::pop_front() {

        if(head_ != NULL) {
            LinkedListNode<ElementType> *temp = head_;
            head_ = head_->next_;
            delete temp;
            size_--;
        }
    }

    template<typename ElementType>
    void LinkedList<ElementType>::pop_back() {

        if(head_ != NULL){
            if(head_->next_ == NULL){
                delete head_;
            }else{
                LinkedListNode<ElementType> *current = head_;
                while(current->next_->next_ != NULL){
                    current = current->next_;
                }
                delete current->next_;
                current->next_ = NULL;
                tail_ = current;
            }
            size_--;
        }
    }

    template<typename ElementType>
    int LinkedList<ElementType>::size() const {
        return size_;
    }

    template<typename ElementType>
    bool LinkedList<ElementType>::empty() const {
        return size_ == 0;
    }

    template<typename ElementType>
    void LinkedList<ElementType>::clear() {

        while(head_ != NULL){
            pop_front();
        }
        size_ = 0;
    }

    template<typename ElementType>
    std::ostream &operator<<(std::ostream &os, const LinkedList<ElementType> &list) {

        if(list.head_ == NULL){
            os << "The list is empty." << endl;
        }else {
            LinkedListNode<ElementType> *current = list->head_;
            for(int i = 0; i < list.size_-1; i++){
                os << current->data_ << ",";
                current = current->next_;
            }
            os << current->data_ << ".";
        }
    }

    template<typename ElementType>
    void LinkedList<ElementType>::RemoveOdd() {

        if(head_->next_ != NULL){
            LinkedListNode<ElementType> *current = head_;
            LinkedListNode<ElementType> *previous = new LinkedListNode<ElementType>();
            int count = 0;
            while(current != NULL){
                if(count % 2 == 0){
                    previous = current;
                    current = current->next_;
                }else {
                    previous->next_ = current->next_;
                    
                }
                count ++;
            }
        }
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
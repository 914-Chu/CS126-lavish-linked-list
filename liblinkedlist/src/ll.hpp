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

    template <typename ElementType>
    bool LinkedListNode<ElementType>::operator != (const LinkedListNode<ElementType> &node) const {
        return data_ != node.data_;
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
    void LinkedList<ElementType>::PushFront(ElementType value) {
        LinkedListNode<ElementType> *temp = new LinkedListNode<ElementType>(value,head_);
        head_ = temp;
        size_++;
        delete temp;
    }

    template<typename ElementType>
    void LinkedList<ElementType>::PushBack(ElementType value) {
        LinkedListNode<ElementType> *temp = new LinkedListNode<ElementType>(value);
        if(head_ == NULL){
            head_ = temp;
            tail_ = temp;
        }else {
            tail_->next_ = temp;
            tail_ = tail_->next_;
        }
        delete temp;
        size_++;
    }

    template<typename ElementType>
    ElementType LinkedList<ElementType>::front() const throw(exception){

        if (head_ == NULL) {
            throw exception();
        }
        return head_->data_;
    }

    template<typename ElementType>
    ElementType LinkedList<ElementType>::back() const throw(exception){
        if (tail_ == NULL) {
            throw exception();
        }
        return tail_->data_;
    }

    template<typename ElementType>
    void LinkedList<ElementType>::PopFront() {

        if(head_ != NULL) {
            LinkedListNode<ElementType> *temp = head_;
            head_ = head_->next_;
            delete temp;
            size_--;
        }
    }

    template<typename ElementType>
    void LinkedList<ElementType>::PopBack() {

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
    void LinkedList<ElementType>::Remove(LinkedListNode<ElementType> *node) {

        if(head_ != NULL && node != NULL) {
            if (head_ == node) {
                PopFront();
            } else {
                LinkedListNode<ElementType> *current = head_;
                LinkedListNode<ElementType> *temp;
                while(current->next_ != NULL && current->next_ != node){
                    current = current->next_;
                }
                if(current->next_ != NULL){
                    temp = current->next_;
                    current->next_ = temp->next_;
                    delete temp;
                }
            }
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
    void LinkedList<ElementType>::Clear() {

        while(head_ != NULL){
            PopFront();
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
            LinkedListNode<ElementType> *previous;
            int count = 0;
            while(current != NULL){
                if(count % 2 == 0){
                    previous = current;
                    current = current->next_;
                }else {
                    previous->next_ = current->next_;
                    delete current;
                    current = previous->next_;
                }
                count ++;
            }
        }
    }

    template<typename ElementType>
    bool LinkedList<ElementType>::operator==(const LinkedList<ElementType> &rhs) const {
        if (size_ != rhs.size()){
            return false;
        }else if(head_ == NULL && rhs.front() == NULL) {
            LinkedListNode<ElementType> *this_list = head_;

            const_iterator other_list = rhs.begin();
            while(this_list != NULL){
                if(this_list != other_list){
                    return false;
                }
                this_list = this_list->next_;
                other_list++;
            }
        }
    }

    template<typename ElementType>
    bool operator!=(const LinkedList<ElementType> &lhs, const LinkedList<ElementType> &rhs) {

    }

    template<typename ElementType>
    typename LinkedList<ElementType>::iterator &LinkedList<ElementType>::iterator::operator++() {

    }

    template<typename ElementType>
    ElementType &LinkedList<ElementType>::iterator::operator*() const {
        return current_->data_;
    }

    template<typename ElementType>
    bool LinkedList<ElementType>::iterator::operator!=(const LinkedList<ElementType>::iterator &other) const {

    }

    template<typename ElementType>
    typename LinkedList<ElementType>::iterator LinkedList<ElementType>::begin() {
        return iterator(head_);
    }

    template<typename ElementType>
    typename LinkedList<ElementType>::iterator LinkedList<ElementType>::end() {
        return iterator(tail_);
    }

    template<typename ElementType>
    typename LinkedList<ElementType>::const_iterator &LinkedList<ElementType>::const_iterator::operator++() {

    }

    template<typename ElementType>
    const ElementType &LinkedList<ElementType>::const_iterator::operator*() const {
        return current_->data_;
    }

    template<typename ElementType>
    bool
    LinkedList<ElementType>::const_iterator::operator!=(const LinkedList<ElementType>::const_iterator &other) const {

    }

    template<typename ElementType>
    typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::begin() const {
        return const_iterator(head_);
    }

    template<typename ElementType>
    typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::end() const {
        return const_iterator(tail_);
    }
}
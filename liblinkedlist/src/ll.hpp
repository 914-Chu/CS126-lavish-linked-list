#include <utility>
#include <cassert>
#include <iostream>
#include "ll.h"

using namespace std;

namespace cs126linkedlist {

    template <typename ElementType>
    LinkedListNode<ElementType>::LinkedListNode() {
        data_ = NULL;
        next_ = nullptr;
    }

    template <typename ElementType>
    LinkedListNode<ElementType>::LinkedListNode(ElementType data) {
        data_ = data;
        next_ = nullptr;
    }

    template <typename ElementType>
    LinkedListNode<ElementType>::LinkedListNode(ElementType data, LinkedListNode<ElementType>* next) {
        data_ = data;
        next_ = next;
    }

    template <typename ElementType>
    bool LinkedListNode<ElementType>::operator != (const LinkedListNode<ElementType> &node) const {
        return data_ != node.data_;
    }

    template<typename ElementType>
    void LinkedList<ElementType>::init() {
        size_ = 0;
        head_ = nullptr;
        tail_ = nullptr;
    }

    template<typename ElementType>
    LinkedList<ElementType>::LinkedList() {
        init();
    }

    template<typename ElementType>
    LinkedList<ElementType>::LinkedList(const std::vector<ElementType> &values) {

        init();
        for(ElementType element : values){
            PushBack(element);
        }
    }

    // Copy constructor
    template<typename ElementType>
    LinkedList<ElementType>::LinkedList(const LinkedList<ElementType> &source) {

        if(source.head_ != nullptr) {
            init();
            LinkedListNode<ElementType> *temp = source.head_;
            while (temp != nullptr) {
                PushBack(temp->data_);
                tail_ = temp;
                temp = temp->next_;
            }
            size_ = source.size();
        }
    }

    // Move constructor
    template<typename ElementType>
    LinkedList<ElementType>::LinkedList(LinkedList<ElementType> &&source) noexcept {

        if(source.begin() != nullptr) {
            init();
            head_ = source.head_;
            tail_ = source.tail_;
            size_ = source.size();
        }
        source.init();
    }

    // Destructor
    template<typename ElementType>
    LinkedList<ElementType>::~LinkedList() {

        Clear();
        cout << "destructor called" << endl;
    }

    // Copy assignment operator
    template<typename ElementType>
    LinkedList<ElementType> &LinkedList<ElementType>::operator=(const LinkedList<ElementType> &source) {

        this(source);
        return *this;
    }

    // Move assignment operator
    template<typename ElementType>
    LinkedList<ElementType> &LinkedList<ElementType>::operator=(LinkedList<ElementType> &&source) noexcept {

        if(*this != source){
            Clear();
            if(source.head_ != nullptr){
                head_ = source.head_;
                tail_ = source.tail_;
                size_= source.size();
            }
        }
        source.init();
        return *this;
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
        if(head_ == nullptr){
            head_ = temp;
            tail_ = temp;
        }else {
            tail_->next_ = temp;
            tail_ = tail_->next_;
        }
        size_++;
    }

    template<typename ElementType>
    ElementType LinkedList<ElementType>::front() const noexcept(false){

        if (head_ == nullptr) {
            throw std::runtime_error("Empty list");
        }
        return head_->data_;
    }

    template<typename ElementType>
    ElementType LinkedList<ElementType>::back() const noexcept(false){
        if (tail_ == nullptr) {
            throw std::runtime_error("Empty list");
        }
        return tail_->data_;
    }

    template<typename ElementType>
    void LinkedList<ElementType>::PopFront() {

        if(head_ != nullptr) {
            LinkedListNode<ElementType> *temp = head_;
            head_ = head_->next_;
            delete temp;
            size_--;
        }
    }

    template<typename ElementType>
    void LinkedList<ElementType>::PopBack() {

        if(head_ != nullptr){
            if(head_->next_ == nullptr){
                delete head_;
            }else{
                LinkedListNode<ElementType> *current = head_;
                while(current->next_->next_ != nullptr){
                    current = current->next_;
                }
                delete current->next_;
                current->next_ = nullptr;
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
    void LinkedList<ElementType>::Clear() {

        while(head_ != nullptr){
            PopFront();
        }
        size_ = 0;
    }

    template<typename ElementType>
    std::ostream &operator<<(std::ostream &os, const LinkedList<ElementType> &list) {

        if(list.begin() == nullptr){
            os << "The list is empty." << endl;
        }else {
            for(typename LinkedList<ElementType>::const_iterator itr = list.begin(); itr != list.end(); ++itr){
                os << *itr << " ";
            }

        }
        return os;
    }

    template<typename ElementType>
    void LinkedList<ElementType>::RemoveOdd() {

        if(head_->next_ != nullptr){
            LinkedListNode<ElementType> *current = head_;
            LinkedListNode<ElementType> *previous;
            int count = 0;
            while(current != nullptr){
                if(count % 2 == 0){
                    previous = current;
                    current = current->next_;
                }else {
                    previous->next_ = current->next_;
                    delete current;
                    size_ --;
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
        }else if(head_ == nullptr && rhs.begin() == nullptr) {
            return true;
        }else{
            const_iterator this_list = this->begin();
            const_iterator other_list = rhs.begin();
            while(this_list != nullptr){
                if(this_list != other_list){
                    return false;
                }
                ++this_list;
                ++other_list;
            }
            return true;
        }
    }

    template<typename ElementType>
    ElementType LinkedList<ElementType>::GetElementAt(int index) {

        LinkedListNode<ElementType> *current = head_;
        int count = 0;
        while(current != nullptr) {
            if(count == index) {
                return current->data_;
            }
            count++;
            current = current->next_;
        }
    }

    template<typename ElementType>
    bool operator!=(const LinkedList<ElementType> &lhs, const LinkedList<ElementType> &rhs) {

        return !(lhs ==  rhs);
    }

    template<typename ElementType>
    typename LinkedList<ElementType>::iterator &LinkedList<ElementType>::iterator::operator++() {

        if(current_ != nullptr){
            current_ = current_->next_;
        }
        return *this;
    }

    template<typename ElementType>
    ElementType &LinkedList<ElementType>::iterator::operator*() const {
        return current_->data_;
    }

    template<typename ElementType>
    bool LinkedList<ElementType>::iterator::operator!=(const LinkedList<ElementType>::iterator &other) const {
        return current_ != other.current_;
    }

    template<typename ElementType>
    bool LinkedList<ElementType>::iterator::operator==(const LinkedList<ElementType>::iterator &other) const {
        return current_ == other.current_;
    }

    template<typename ElementType>
    typename LinkedList<ElementType>::iterator LinkedList<ElementType>::begin() {
        return iterator(head_);
    }

    template<typename ElementType>
    typename LinkedList<ElementType>::iterator LinkedList<ElementType>::end() {
        return iterator(nullptr);
    }

    template<typename ElementType>
    typename LinkedList<ElementType>::const_iterator &LinkedList<ElementType>::const_iterator::operator++() {

        if(current_ != nullptr){
            current_ = current_->next_;
        }
        return *this;
    }

    template<typename ElementType>
    const ElementType &LinkedList<ElementType>::const_iterator::operator*() const {
        return current_->data_;
    }

    template<typename ElementType>
    bool
    LinkedList<ElementType>::const_iterator::operator!=(const LinkedList<ElementType>::const_iterator &other) const {
        return current_ != other.current_;
    }

    template<typename ElementType>
    bool LinkedList<ElementType>::const_iterator::operator==(const LinkedList<ElementType>::const_iterator &other) const {
        return current_ == other.current_;
    }

    template<typename ElementType>
    typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::begin() const {
        return const_iterator(head_);
    }

    template<typename ElementType>
    typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::end() const {
        return const_iterator(nullptr);
    }
}
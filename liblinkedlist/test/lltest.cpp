#include "catch.hpp"
#include "ll.h"

using namespace std;
using namespace cs126linkedlist;

TEST_CASE("LinkedListNode") {

    SECTION("operator !=") {
        LinkedListNode<int> *node1 = new LinkedListNode<int>(1);
        LinkedListNode<int> *node2 = new LinkedListNode<int>(2);
        REQUIRE(node1!=node2);
    }
}

TEST_CASE("LinkedList Constructors") {

    SECTION("Default constructor") {
        LinkedList<int> *list = new LinkedList<int>();
        REQUIRE(list->front() == NULL);
        REQUIRE(list->back() == NULL);
        REQUIRE(list->size() == 0);
    }

    SECTION("Initialize constructor") {
        vector<int> vec{1,2,3,4,5};
        LinkedList<int> *list = new LinkedList<int>(vec);
        REQUIRE(list->front() == 1);
        REQUIRE(list->get(1) == 2);
        REQUIRE(list->get(2) == 3);
        REQUIRE(list->get(3) == 4);
        REQUIRE(list->back() == 5);
        REQUIRE(list->size() == 5);
    }

    SECTION("Copy constructor") {
        vector<int> vec{1,2,3,4,5};
        LinkedList<int> *list = new LinkedList<int>(vec);
        LinkedList<int> *list1 = new LinkedList<int>(*list);
        REQUIRE(list == list1);
    }

    SECTION("Move constructor") {
        vector<int> vec{1,2,3,4,5};
        LinkedList<int> *list = new LinkedList<int>(vec);
        LinkedList<int> *list1(move(list));
        REQUIRE(list->empty());
        REQUIRE(list->size() == 5);
    }

    SECTION("Destructor") {

    }

    SECTION("Copy assignment operator") {

    }

    SECTION("Move assignment operator") {

    }
}

TEST_CASE("LinkedList methods") {

    vector<int> vec{1,2,3,4,5};
    LinkedList<int> *list = new LinkedList<int>(vec);

    SECTION(" Push value on front") {
        list->PushFront(0);
        REQUIRE(list->front() == 0);
    }

    SECTION("Push value on back") {
        list->PushBack(6);
        REQUIRE(list->back() == 6);
    }

    SECTION(" Access the front/back value") {
        LinkedList<int> *list1 = new LinkedList<int>();
        REQUIRE_THROWS_AS(list1->front(),exception);
        REQUIRE_THROWS_AS(list1->back(),exception);

    }

    SECTION("remove front element") {
        list->PopFront();
        REQUIRE(list->front() == 1);
    }

    SECTION("remove back element") {
        list->PopBack();
        REQUIRE(list->back() == 5);
    }

    SECTION("remove element at the node") {
        LinkedListNode<int> *node1 = new LinkedListNode<int>(3);
        list->Remove(node1);
        REQUIRE(list->get(2) == 4);
    }

    SECTION("return number of elements") {
        REQUIRE(list->size() == 4);
    }

    SECTION("check if empty") {
        REQUIRE(!list->empty());
    }

    SECTION("clear the contents") {
        list->Clear();
        REQUIRE(list->empty());
    }

    SECTION("remove the odd elements from the list 0 indexed") {
        vector<int> vec{0,1,2,3,4,5,6};
        LinkedList<int> *list1 = new LinkedList<int>(vec);
        list1->RemoveOdd();
        REQUIRE(list1->size() == 4);
        REQUIRE(list->front() == 0);
        REQUIRE(list->get(1) == 2);
        REQUIRE(list->get(2) == 4);
        REQUIRE(list->back() == 6);
    }
}

TEST_CASE("LinkedList Iterator"){

    SECTION("Default constructor") {
        LinkedList<int>::const_iterator cit;
    }

    SECTION("Initialize constructor") {

    }

    SECTION("operator++") {

    }

    SECTION("operator*") {

    }

    SECTION("operator !=") {

    }

    SECTION("operator ==") {

    }

}

TEST_CASE("LinkedList Const Iterator"){

    SECTION("Default constructor") {

    }

    SECTION("Initialize constructor") {

    }

    SECTION("operator++") {

    }

    SECTION("operator*") {

    }

    SECTION("operator !=") {

    }

    SECTION("operator ==") {

    }

}

TEST_CASE("LinkedList external methods"){

    vector<int> vec{0,1,2,3,4,5,6};
    LinkedList<int> *list = new LinkedList<int>(vec);
    vector<int> vec1{6,5,4,3,2,1,0};
    LinkedList<int> *list1 = new LinkedList<int>(vec);
    vector<int> vec2{0,1};
    LinkedList<int> *list2 = new LinkedList<int>(vec);
    LinkedList<int> *list3 = new LinkedList<int>();

    SECTION("operator <<") {
        cout << list << endl;
    }

    SECTION("operator !=") {
        REQUIRE(list != list1);
        REQUIRE(list != list2);
        REQUIRE(list != list3);
    }

}
#include "catch.hpp"
#include "ll.h"
#include <exception>
#include <iostream>

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
        LinkedList<int> list;
        REQUIRE_THROWS_AS(list.front(), std::runtime_error);
        REQUIRE_THROWS_AS(list.back(), std::runtime_error);
        REQUIRE(list.size() == 0);
    }

    SECTION("Initialize constructor") {
        vector<int> vec{1,2,3,4,5};
        LinkedList<int> list(vec);
        REQUIRE(list.front() == 1);
        REQUIRE(list.GetElementAt(1) == 2);
        REQUIRE(list.GetElementAt(2) == 3);
        REQUIRE(list.GetElementAt(3) == 4);
        REQUIRE(list.back() == 5);
        REQUIRE(list.size() == 5);
    }

    SECTION("Copy constructor") {
        vector<int> vec{1,2,3,4,5};
        LinkedList<int> list(vec);
        LinkedList<int> list1(list);
        REQUIRE(list.size() == list1.size());
    }

    SECTION("Move constructor") {
        vector<int> vec{1,2,3,4,5};
        LinkedList<int> list(vec);
        LinkedList<int> list1 = std::move(list);
        REQUIRE(list.empty());
        REQUIRE(list1.size() == 5);
    }

    SECTION("Destructor") {
        vector<int> vec{1,2,3,4,5};
        LinkedList<int> list(vec);
        list.~LinkedList<int>();
    }

    SECTION("Copy assignment operator") {
        vector<int> vec{1,2,3,4,5};
        LinkedList<int> list(vec);
        LinkedList<int> list2 = list;
        REQUIRE(list.size() == list2.size());
    }

    SECTION("Move assignment operator") {
        vector<int> vec{1,2,3,4,5};
        LinkedList<int> list(vec);
        LinkedList<int> list2;
        list2 = std::move(list);
        REQUIRE(list.size() == 0);
        REQUIRE(list2.size() == 5);
    }
}

TEST_CASE("LinkedList methods") {

    vector<int> vec{1,2,3,4,5};
    LinkedList<int> list(vec);

    SECTION(" Push value on front") {
        list.PushFront(0);
        REQUIRE(list.front() == 0);
    }

    SECTION("Push value on back") {
        list.PushBack(6);
        REQUIRE(list.back() == 6);
    }

    SECTION(" Access the front/back value") {
        LinkedList<int> list1;
        REQUIRE_THROWS_AS(list1.front(), std::runtime_error);
        REQUIRE_THROWS_AS(list1.back(), std::runtime_error);
    }

    SECTION("remove front element") {
        list.PopFront();
        REQUIRE(list.front() == 2);
    }

    SECTION("remove back element") {
        list.PopBack();
        REQUIRE(list.back() == 4);
    }


    SECTION("return number of elements") {
        list.PopBack();
        list.PopBack();
        REQUIRE(list.size() == 3);
    }

    SECTION("check if empty") {
        REQUIRE(!list.empty());
    }

    SECTION("clear the contents") {
        list.Clear();
        REQUIRE(list.empty());
    }

    SECTION("remove the odd elements from the list 0 indexed") {
        vector<int> vec{0,1,2,3,4,5,6};
        LinkedList<int> list2(vec);
        list2.RemoveOdd();
        REQUIRE(list2.size() == 4);
        REQUIRE(list2.front() == 0);
        REQUIRE(list2.GetElementAt(1) == 2);
        REQUIRE(list2.GetElementAt(2) == 4);
        REQUIRE(list2.back() == 6);
    }
}

TEST_CASE("LinkedList Iterator"){

    vector<int> vec{1,2,3,4,5};
    LinkedList<int> list(vec);

    SECTION("Default constructor") {
        LinkedList<int>::const_iterator itr1;
        REQUIRE(itr1 == nullptr);
    }

    SECTION("operator++") {
        for(int i : list){
            REQUIRE(i == vec[i-1]);
        }
    }

    SECTION("operator*") {
        LinkedListNode<int> node(1);
        LinkedList<int>::iterator itr1 = LinkedList<int>::iterator(&node);
        REQUIRE(*itr1 == 1);
    }

    SECTION("operator !=") {
        REQUIRE(list.begin() != list.end());
    }
}

TEST_CASE("LinkedList external methods"){

    vector<int> vec{0,1,2,3,4,5,6};
    LinkedList<int> list(vec);
    vector<int> vec1{6,5,4,3,2,1,0};
    LinkedList<int> list1(vec1);
    vector<int> vec2{0,1};
    LinkedList<int> list2(vec2);
    LinkedList<int> list3;

    SECTION("operator <<") {
        cout << list << endl;
    }

    SECTION("operator !=") {
        REQUIRE(list != list1);
        REQUIRE(list != list2);
        REQUIRE(list != list3);
    }

}
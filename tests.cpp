#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "BSTree.h"
#include "Node.h"

BSTree *t1 = new BSTree();

TEST_CASE("recursive search"){
	t1->setup();
	CHECK(t1->searchr(10)==10);
	CHECK(t1->searchr(15)==15);
	CHECK(t1->searchr(30)==30);
	CHECK(t1->searchr(5)==5);
	CHECK(t1->searchr(8)==8);
}

TEST_CASE("delete nodes"){
	t1->setup();
	t1->deleten(30);
	CHECK(t1->get_debug_string()==", 3, , 5, , 8, , 10, , 15, , 20, ");
	t1->deleten(5);
	CHECK(t1->get_debug_string()==", 3, , 8, , 10, , 15, , 20, ");
	t1->deleten(10);
	CHECK(t1->get_debug_string()==", 3, , 8, , 15, ");
}

TEST_CASE("leaves and height"){
	t1->setup();
	CHECK(t1->countLeaves()==4);
	CHECK(t1->height()==3);
}


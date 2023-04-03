#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include<iostream>
#include "Header.h"
#include "doctest.h"

using namespace std;


TEST_CASE("Test #2") {
	HashTable a;
	a.insert("one", -1000);
	a.insert("two", 99);
	a.insert("tree", 3);
	CHECK(a.get("one") == -1000);
	CHECK(a.get("two") == 99);
	CHECK(a.get("tree") == 3);
}
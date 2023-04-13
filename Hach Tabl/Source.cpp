#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include<iostream>
#include "Header.h"
#include "doctest.h"

using namespace std;

TEST_CASE("Ttable addition test") {
	HashTable a;
	a.insert("one", -1000);
	a.insert("two", 99);
	a.insert("tree", 3);
	CHECK(a.get("one") == -1000);
	CHECK(a.get("two") == 99);
	CHECK(a.get("tree") == 3);
}

TEST_CASE("table deletion test") {
	HashTable a;
	a.insert("one", -1000);
	a.insert("two", 99);
	a.insert("tree", 3);

	a.del("one");
	a.del("two");
	a.del("tree");

	CHECK(a.get("one") == 0);
	CHECK(a.get("two") == 0);
	CHECK(a.get("tree") == 0);
}

TEST_CASE("table empty test") {
	HashTable a;

	CHECK(a.isEmpty() == true);
}


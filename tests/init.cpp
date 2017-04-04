#include <tree.h>
#include <catch.hpp>

SCENARIO ("init", "[init]")
{
  Tree<int> test;
  REQUIRE(test.root_() == NULL);
  REQUIRE(test.get_count() == 0);
}
SCENARIO("insert", "[init]")
{
  Tree<int> test;
  test.insert_node(5);
  REQUIRE(test.get_count() == 1);
  REQUIRE(test.find_node(5, test.root_())->key == 5);
}
SCENARIO("find_node", "[init]")
{
  Tree<int> test;
  test.insert_node(4);
  REQUIRE(test.find_node(4, test.root_()) != NULL);
  REQUIRE(test.find_node(4, test.root_())->key == 4);
}
SCENARIO("get root", "[init]")
{
  Tree<int> test;
  test.insert(4);
  REQUIRE(test.root_() != 0);
}
SCENARIO ("reading", "[init]")
{
   Test<int> test;
   test.reading("file1.txt");
   REQUIRE(test.search_result(3) == 1);
   REQUIRE(test.search_result(4) == 1);
   REQUIRE(test.get_count() == 2);
}

SCENARIO ("writing", "[init]")
{
  Test<int> test1;
  test1.insert(4);
  test1.writing("file2.txt");
  Test<int> test2;
  test2.reading("file2.txt");
  REQUIRE(test.get_count() == test2.get_count());
}

#include <tree.h>
#include <catch.hpp>

SCENARIO ("init", "[init]")
{
  Tree<int> test;
  REQUIRE(test.root_() == nullptr);
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
  REQUIRE(test.find_node(4, test.root_()) != nullptr);
  REQUIRE(test.find_node(4, test.root_())->key == 4);
}
SCENARIO("get root", "[init]")
{
  Tree<int> test;
  test.insert_node(4);
  REQUIRE(test.root_() != 0);
}
SCENARIO("insert equal elements", "[insert]")
 {
   Tree<int> test;
   test.insert_node(4);
   test.insert_node(4);
   REQUIRE(test.get_count() == 1);
 }
SCENARIO ("reading/writing", "[init]")
{
  Tree<int> test1;
  test1.insert_node(4);
  test1.insert_node(3);
  test1.writing("file2.txt");
  Tree<int> test2;
  test2.reading("file2.txt");
  REQUIRE(test2.find_node(4, test2.root_())!= nullptr);
  REQUIRE(test2.find_node(3, test2.root_())!= nullptr);
  REQUIRE(test1.get_count() == test2.get_count());
}

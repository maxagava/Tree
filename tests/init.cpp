#include "tree.hpp"
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

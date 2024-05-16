#include <gtest/gtest.h>
#include "../src/main.h"

// Initialization of the Tokens class
TEST(Tokens, Initialization) {

  OperatorList operators;

  TokenList tokens(&operators);
  EXPECT_EQ(tokens.left.size(),  0);
  EXPECT_EQ(tokens.right.size(), 0);

  AtomBase a("3.4");
  tokens.append(ATOM_TOKEN, &a);
  EXPECT_EQ(tokens.right.size(), 1);
  EXPECT_EQ(tokens.right.front().atom->value, (float)3.4);

}

// Test get and put tokenss
TEST(Tokens, GetAndPut) {

  OperatorList operators;
  
  // prepare tokens
  TokenList tokens(&operators);

  // test empty arrays
  EXPECT_EQ(tokens.get_left().type,  EMPTY_TOKEN);  
  EXPECT_EQ(tokens.get_right().type, EMPTY_TOKEN);  

  // fill with some dummy values
  AtomList<AtomBase> atoms;
  int nitems = 4;
  for (int i=0; i<nitems; i++) {
    AtomBase *a = atoms.append(std::to_string(i));
    tokens.append(ATOM_TOKEN, a);
  }
  
  // pass 2 strings from right to left
  Token token = tokens.get_right();
  tokens.put_left(token);
  EXPECT_EQ(token.atom->value, (float)0.);

  token = tokens.get_right();
  tokens.put_left(token);
  EXPECT_EQ(token.atom->value, (float)1.);
  EXPECT_EQ(tokens.right.size(), nitems-2);
  EXPECT_EQ(tokens.left.size(), 2);

  // make sure that items are selected in a correct order
  token = tokens.get_left();
  tokens.put_right(token);
  EXPECT_EQ(token.atom->value, (float)1.);
  EXPECT_EQ(tokens.right.size(), nitems-1);
  EXPECT_EQ(tokens.left.size(), 1);
}

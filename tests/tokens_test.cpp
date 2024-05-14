#include <gtest/gtest.h>
#include "../src/main.h"

// Initialization of the Tokens class
TEST(Tokens, Initialization) {

  TokenListClass tokens;
  EXPECT_EQ(tokens.left.size(),  0);
  EXPECT_EQ(tokens.right.size(), 0);

  TokenClass token(ATOM_TOKEN, "3.4");
  tokens.append(token);
  EXPECT_EQ(tokens.right.size(), 1);
  EXPECT_EQ(tokens.right.front().atom->value, (float)3.4);

}

// Test get and put tokenss
TEST(Tokens, GetAndPut) {

  // prepare tokens
  TokenListClass tokens;

  // test empty arrays
  EXPECT_EQ(tokens.get_left().type,  EMPTY_TOKEN);  
  EXPECT_EQ(tokens.get_right().type, EMPTY_TOKEN);  

  // fill with some dummy values
  int nitems = 4;
  for (int i=0; i<nitems; i++) {
    tokens.append(TokenClass(ATOM_TOKEN, std::to_string(i)));
  }
  
  // pass 2 strings from right to left
  TokenClass token = tokens.get_right();
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

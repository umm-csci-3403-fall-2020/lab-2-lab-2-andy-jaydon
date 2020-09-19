#include <gtest/gtest.h>

#include "disemvowel.h"
char *test;

TEST(Disemvowel, HandleEmptyString) {
	test = disemvowel((char*) "");
	ASSERT_STREQ("", test);
	if (strcmp(test, "") != 0){
	free(test);
	}
}

TEST(Disemvowel, HandleNoVowels) {
  	test = disemvowel((char*) "pqrst");
	ASSERT_STREQ("pqrst", test);
}

TEST(Disemvowel, HandleOnlyVowels) {
  	test = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
	ASSERT_STREQ("", test);
	free(test);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  	test = disemvowel((char*) "Mrrs, Mnnst");
	ASSERT_STREQ("Mrrs, Mnnst", test);
}

TEST(Disemvowel, HandlePunctuation) {
  	test = disemvowel((char*) "n (nxplnd) lphnt!");
	ASSERT_STREQ("n (nxplnd) lphnt!", test);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  test = disemvowel(str);
  ASSERT_STREQ("xyz", test);
  free(test);
  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

// jdh CS3010 Fall 2023

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "warmup.jmgottli.h"

int createAndCheck(char *testname, char *name, int value, int weight, bool expectFail, Collectible **collectibleReturn) {
  Collectible *collectible;
  int rc = 0;

  collectible = createCollectible(name, value, weight);
  if ( expectFail ) {
    if (collectible != NULL) {
      printf("error: test %s fails; expected NULL return value\n", testname);
      rc = 1;
    }
  } else {
    *collectibleReturn = collectible;
    if ( strcmp(collectible->name, name) ) {
      printf("error: test %s fails; name is not correct\n", testname);
      rc = 1;
    }
    if (collectible->value != value) {
      printf("error: test %s fails; value is not correct\n", testname);
      rc = 1;
    }
    if (collectible->weight != weight) {
      printf("error: test %s fails; weight is not correct\n", testname);
      rc = 1;
    }
  }

  if (rc == 0)
    printf("pass test %s\n", testname);

  return rc;
} // createAndCheck()

//------------------------------------------------------

int compareCheck(char *testname, Collectible *collectible1, Collectible *collectible2, int expectedValue) {
  int res, fail;

  fail = 0;
  res = compareCollectibles(collectible1, collectible2);
  if (expectedValue == 0) {
    if (res != 0) {
      printf("error: test %s fails; expected zero from comparison; got %d\n", testname, res);
      fail = 1;
    }
  } else if (expectedValue > 0) {
    if (res != 1) {
      printf("error: test %s fails; expected return value = 1 from comparison; got %d\n", testname, res);
      fail = 1;
    }
  } else {
    if (res != -1) {
      printf("error: test %s fails; expected negative return value = -1 from comparison; got %d\n", testname, res);
      fail = 1;
    }
  }

  if (fail == 0)
    printf("pass test %s\n", testname);

  return fail;
} // compareCheck()

//------------------------------------------------------

int main() {
  Collectible *collectible1, *collectible2, *collectible3, *collectible4, *collectible5;
  int numfails = 0;
  int rc;

  collectible1 = NULL;
  collectible2 = NULL;
  collectible3 = NULL;
  collectible4 = NULL;
  collectible5 = NULL;

  // this should fail: name is NULL
  rc = createAndCheck("T1", NULL, 34, 10, true, NULL);
  if (rc)
    numfails = numfails + 1;

  // this should fail: strlen(name) is zero
  rc = createAndCheck("T2", "", 81, 1, true, NULL);
  if (rc)
    numfails = numfails + 1;

  // this should fail: value is zero
  rc = createAndCheck("T3", "rock", 0, 10, true, NULL);
  if (rc)
    numfails = numfails + 1;

  // this should fail: weight is zero
  rc = createAndCheck("T4", "rock", 8, 0, true, NULL);
  if (rc)
    numfails = numfails + 1;

  // this should pass
  rc = createAndCheck("T5", "rock", 121, 5, false, &collectible1);
  if (rc)
    numfails = numfails + 1;

  // this should pass
  rc = createAndCheck("T6", "book", 10, 6, false, &collectible2);
  if (rc)
    numfails = numfails + 1;

  // this should pass
  rc = createAndCheck("T7", "book", 12, 7, false, &collectible3);
  if (rc)
    numfails = numfails + 1;

  // this should pass
  rc = createAndCheck("T8", "cat", 10, 10, false, &collectible4);
  if (rc)
    numfails = numfails + 1;

  // this should pass
  rc = createAndCheck("T9", "egg",  4, 9, false, &collectible5);
  if (rc)
    numfails = numfails + 1;

  if (collectible1 != NULL && collectible2 != NULL && collectible3 != NULL && collectible4 != NULL && collectible5 != NULL) {
    rc = compareCheck("T10", collectible1, collectible2, 1);
    if (rc)
      numfails = numfails + 1;

    rc = compareCheck("T11", collectible3, collectible2, 1);
    if (rc)
      numfails = numfails + 1;

    rc = compareCheck("T12", collectible3, collectible3, 0);
    if (rc)
      numfails = numfails + 1;

    rc = compareCheck("T13", collectible5, collectible4, -1);
    if (rc)
      numfails = numfails + 1;

    rc = compareCheck("T14", collectible4, collectible5, 1);
    if (rc)
      numfails = numfails + 1;

    rc = compareCheck("T15", collectible1, collectible4, 1);
    if (rc)
      numfails = numfails + 1;

    rc = compareCheck("T16", collectible1, collectible1, 0);
    if (rc)
      numfails = numfails + 1;
  } else {
    printf("was not able to run some tests\n");
  }

  if (numfails == 0) {
    printf("all tests pass\n");
    return 0;
  } else {
    printf("%d test(s) failed\n", numfails);
    return 8;
  }

} // main()

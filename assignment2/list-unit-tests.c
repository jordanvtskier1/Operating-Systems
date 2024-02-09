// jdh CS3010 Spring 2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.jmgottli.h"

Collectible *createCollectible(char *name, unsigned int value, unsigned int weight) {
  if (name != NULL) {
    if (strlen(name) > 0 && strlen(name) <= MAX_NAME_LENGTH &&
        value > 0 && weight > 0) {
      Collectible *newCollectible = malloc(sizeof(Collectible));
      strcpy(newCollectible->name, name);
      newCollectible->value = value;
      newCollectible->weight = weight;
      return newCollectible;
    }
  }

  return NULL;
} // createCollectible()

//--------------------------------------------------------------------------

bool findTest(char *testname, ListNode *theList, char *itemName, Collectible *expCollectible) {
  Collectible *c;
  bool fail;

  fail = false;
  c = findItem(theList, itemName, compareNames);
  if (expCollectible == NULL) {
    if (c != NULL) {
      printf("%s: bad result from find; expected result != NULL for finding '%s'\n", testname, itemName);
      fail = true;
    }
  } else {
    if (c == NULL) {
      printf("%s: bad result from find; expected result != NULL for finding '%s'\n", testname, itemName);
      fail = true;
    } else {
      if (strcmp(c->name, expCollectible->name)) {
        printf("%s: bad result from find; expected name='%s' got '%s'\n", testname, expCollectible->name, c->name);
        fail = true;
      }
      if (c->value != expCollectible->value) {
        printf("%s: bad result from find; expected value='%d' got '%d'\n", testname, expCollectible->value, c->value);
        fail = true;
      }
      if (c->weight != expCollectible->weight) {
        printf("%s: bad result from find; expected weight='%d' got '%d'\n", testname, expCollectible->weight, c->weight);
        fail = true;
      }
    }
  }
  return fail;
} // findTest()

//---------------------------------------------------------------

int listTests() {
  ListNode *theList = NULL;
  Collectible *collectible;
  int rc, numfails, idx, fail;

  numfails = 0;

  Collectible *rock = createCollectible("rock", 5, 10);
  rc = insertItem(&theList, rock, compareValues);
  if (rc != 0) {
    printf("ERROR: expected rc = 0 from insertItem(); got %d\n", rc);
    ++numfails;
  }

  Collectible *toad = createCollectible("toad", 3, 1);
  rc = insertItem(&theList, toad, compareValues);
  if (rc != 0) {
    printf("ERROR: expected rc = 0 from insertItem(); got %d\n", rc);
    ++numfails;
  }

  Collectible *macBook = createCollectible("laptop", 6, 2);
  insertItem(&theList, macBook, compareValues);

  Collectible *corgi = createCollectible("corgi", 900, 25);
  insertItem(&theList, corgi, compareValues);

  Collectible *textbook = createCollectible("textbook", 55, 8);
  insertItem(&theList, textbook, compareValues);

  Collectible *brick = createCollectible("brick", 1, 3);
  insertItem(&theList, brick, compareValues);

  Collectible *shovel = createCollectible("shovel", 2, 12);
  insertItem(&theList, shovel, compareValues);

  Collectible *couch = createCollectible("couch", 75, 45);
  insertItem(&theList, couch, compareValues);

  Collectible *hondaCivic = createCollectible("Honda Civic", 1500, 3200);
  insertItem(&theList, hondaCivic, compareValues);

  printList(theList, printCollectible);

  printf("--------------------------------------------------\n");

  rc = findTest("T1", theList, couch->name, couch);
  if (rc != 0)
    ++numfails;

  rc = findTest("T2", theList, "cupcake", NULL);
  if (rc != 0)
    ++numfails;

  rc = findTest("T3", theList, hondaCivic->name, hondaCivic);
  if (rc != 0)
    ++numfails;

  rc = findTest("T4", theList, rock->name, rock);
  if (rc != 0)
    ++numfails;

  printf("--------------------------------------------------\n");

  Collectible *table = createCollectible("table", 56, 40);
  insertItem(&theList, table, compareValues);

  Collectible *cake = createCollectible("cake", 4, 2);
  insertItem(&theList, cake, compareValues);

  Collectible *candle = createCollectible("candle", 8, 1);
  insertItem(&theList, candle, compareValues);

  printList(theList, printCollectible);

  printf("--------------------------------------------------\n");

  Collectible *expectedList[] = {hondaCivic, corgi, couch, table, textbook, candle, macBook, rock, cake, toad, shovel, brick};
  int numItems = sizeof(expectedList) / sizeof(Collectible *);

  char *notInList = "not in list";
  rc = deleteItem(&theList, notInList, compareNames);
  if (rc == 0) {
    printf("%s fail: expected rc != 0 from deleteItem('%s'); got %d\n", "T5", notInList, rc);
    ++numfails;
  }

  idx = 0;
  fail = 0;
  while ( ! fail && idx < numItems ) {
    rc = deleteItem(&theList, expectedList[idx]->name, compareNames);
    if (rc != 0) {
      printf("%s fail: expected rc = 0 from deleteItem('%s'); got %d\n", "T6", expectedList[idx]->name, rc);
      ++numfails;
      fail = 1;
    }
    idx = idx + 1;
  }

  // list should be NULL now
  if (theList != NULL) {
    printf("%s fail: expected list to be NULL\n", "T7");
    ++numfails;
  }

  if (numfails == 0)
    printf("SUCCESS! All tests pass.\n");
  else
    printf("Fail: %d test(s) did not pass\n", numfails);

  return numfails;
}

//--------------------------------------------------------------------------

int main() {
  listTests();
}

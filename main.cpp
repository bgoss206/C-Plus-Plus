/**
 *  
 * @file main.cpp
 * 
 * @brief driver file for the library class, including tests and asserts
 * 
 * @author Braxton Goss
 * 
 * @date 4/9/2021
 * 
 */

#include "library.h"

#include <cassert>
#include <iostream>


using namespace std;

void test1() {
  Library Libs("UWB");
  Libs.addBook("Don Quixote");
  Libs.addBook("In Search of Lost Time");
  Libs.addBook("Ulysses");
  Libs.addBook("The Odyssey");
  Libs.listAllBooks();

  cout << "\nTesting ostream overload" << endl << Libs << endl;

  // should generate already in library message and return true
  bool Result = Libs.isInLibrary("The Odyssey");
  assert(Result);

  // cannot add book twice, result should be false
  Result = Libs.addBook("The Odyssey");
  assert(!Result);

  // test remove, result should be true
  Result = Libs.removeBook("The Odyssey");
  assert(Result);

  // not in library, result should be false
  Result = Libs.isInLibrary("The Odyssey");
  assert(!Result);

  // cannot remove twice, result should be false
  Result = Libs.removeBook("The Odyssey");
  assert(!Result);

  // Self-Made Tests (not given in first file)
  Result = Libs.removeBook("Don Quixote");
  assert(Result);

  Libs.addBook("Testing Book");

  Result = Libs.isInLibrary("Testing Book");
  assert(Result);

  cout << "\nThe library is now:" << endl; 

  Libs.listAllBooks();

}

void testAll() {
  test1();
  cout << "Successfully completed all tests." << endl;
}

int main() {
  testAll();
  return 0;
}
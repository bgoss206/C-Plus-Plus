/**
 *  
 * @file library.cpp
 * 
 * @brief library class demonstrating partially filled arrays 
 * 
 * @author Braxton Goss
 * 
 * @date 4/9/2021
 * 
 */

#include "library.h"
#include <iostream>

// constructor with default name
// set initial number of books to zero
// create Library with given Name
Library::Library(const string &Name) {
  numberOfBooks = 0;
  LibraryName = Name;
}

// destructor
// nothing on heap
Library::~Library() {
  // destructor
}

// true if book found in library
// false if book is not found in library
bool Library::isInLibrary(const string &BookName) const {

  bool bookPresent = false;
  for (int i = 0; i < numberOfBooks; i++) {
    if (bookPresent) {
      break;
    } else if (arrayOfBooks[i] == BookName) {
      bookPresent = true;
    }
  }
  return bookPresent;
}

// add a new book
// return true if successful, false if
// book already in library
bool Library::addBook(const string &BookName) {
  if ((numberOfBooks < getMaxLength()) && (!isInLibrary(BookName))) {
    arrayOfBooks[numberOfBooks] = BookName;
    numberOfBooks++;
    return true;
  } else {
    return false;
  }
}

// find a book index
// return index if found,
// return -1 if not found
int Library::findBook(const string &Bookname) const {
  for (int i = 0; i < numberOfBooks; i++) {
    if (arrayOfBooks[i] == Bookname) {
      return i;
    } else {
      continue;
    }
  }
  return -1;
}

// remove a book
// return true if successfully removed
// false if book not in library
bool Library::removeBook(const string &BookName) {
  if (!isInLibrary(BookName)) {
    return false;
  } else {
    int indexOfRemoval = findBook(BookName);
    arrayOfBooks[indexOfRemoval] = arrayOfBooks[numberOfBooks - 1];
    numberOfBooks--;
    return true;
  }
}

// list all books to standard output
// no return value
void Library::listAllBooks(void) const {
  for (int i = 0; i < numberOfBooks; i++) {
    std::cout << "Book #" << i + 1 << ": " << arrayOfBooks[i] << std::endl;
  }
}

// return private data member: MAX_LENGTH
// does not change the length of array
int Library::getMaxLength() const { 
  return MAX_LENGTH; 
}

// return overloaded ostream operator << 
// with comma-separated list of book names
// within brackets
// library is not modified or changed
ostream &operator<<(ostream &Out, const Library &Lib) {
  Out << "[";
  for (int i = 0; i < Lib.numberOfBooks - 1; i++){
    Out << Lib.arrayOfBooks[i] << ", ";
  }
  Out << Lib.arrayOfBooks[Lib.numberOfBooks - 1] << "]"; // last one outside of loop to format within brackets more cleary (no extra comma-space)

  return Out;
}


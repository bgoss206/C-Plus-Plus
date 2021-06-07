/**
 *  
 * @file library.h
 * 
 * @brief header file for the library class
 * 
 * @author Braxton Goss
 * 
 * @date 4/9/2021
 * 
 */

#pragma once

#include <string>

// Only for class code, OK to use namespace
using namespace std;

// Library holds books - can add, remove and list books
class Library {

private:
  static const int MAX_LENGTH = 100;  // Absolute Maximum length of array
  int numberOfBooks; // counter for number of current books
  string arrayOfBooks[MAX_LENGTH]; // initialize empty array with length of absolute maximum
  string LibraryName; // name of current library

  // input: book name we're searching for
  // output: return index of the book,
  // if not found, return -1
  // private because it is only used within the class
  int findBook(const string& name) const;

public:
  // constructor with default name
  explicit Library(const string &Name);

  // destructor
  virtual ~Library();

  // add a new book
  // return true if successful, false if
  // book already in library
  bool addBook(const string &BookName);

  // remove a book
  // return true if successfully removed
  // false if book not in library
  bool removeBook(const string &BookName);

  // list all books
  void listAllBooks() const;

  // true if book found in library
  bool isInLibrary(const string &BookName) const;

  // retreival method for MAX_LENGTH constant
  int getMaxLength() const;
  
  // display all books in library by overloading << operator 
  friend ostream &operator<<(ostream &Out, const Library &Lib);
  
};




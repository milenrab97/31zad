#include "Library.h"
#include <iostream>



void Library::resizeLibrary()
{
	Book* oldb = books;
	books = new Book[2 * size];
	copy(oldb);
	size *= 2;
	delete[] oldb;
}

Library::Library()
{
	books = new Book[size];
}

Library::Library(const Library & lib)
{
	copyLibrary(lib);
}

Library & Library::operator=(Library const & lib)
{
	if (this != &lib)
	{
		clearLibrary();
		copyLibrary(lib);
	}
	return *this;
}


Library::~Library()
{
	clearLibrary();
}

void Library::add(const Book & book)
{
	if (numberOfBooks == size) {
		resizeLibrary();
	}
	books[numberOfBooks++] = book;
}

bool Library::remove(const Book & book)
{
	for (int i = 0; i < numberOfBooks; i++)
	{
		if (books[i].getTitle() == book.getTitle())
		{
			shiftElementsFrom(i);
			numberOfBooks--;
			return true;

		}
	}
	return false;
}

void Library::shiftElementsFrom(int index)
{
	for (int i = index; i < numberOfBooks - 1; i++)
	{
		books[i] = books[i + 1];
	}
}

void Library::copy(Book const * other)
{
	for (int i = 0; i < size; i++)
	{
		books[i] = other[i];
	}
}

void Library::copyLibrary(Library const & lib)
{
	this->size = lib.size;
	this->numberOfBooks = lib.numberOfBooks;
	this->books = new Book[size];
	copy(lib.books);
}

void Library::clearLibrary()
{
	delete[] books;
}

double Library::averagePages()
{
	double avg = 0;
	for (int i = 0; i < numberOfBooks; i++)
	{
		avg += books[i].getPages();
	}
	return avg / numberOfBooks;
}

Book & Library::operator[](int index)
{
	return books[index];
}

void Library::sort_by_title()
{
	for (int i = 0; i < numberOfBooks - 1; i++)
	{
		for (int j = i + 1; j < numberOfBooks; j++)
		{
			if (books[i] > books[j]) {
				Book temp;
				temp = books[i];
				books[i] = books[j];
				books[j] = temp;
			}
		}
	}
}

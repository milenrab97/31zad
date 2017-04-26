#pragma once
#include "Book.h";

class Library
{
private:
	Book* books;
	int size = 4;
	int numberOfBooks = 0;

	void resizeLibrary();
public:
	Library();
	Library(Library const& lib);
	Library& operator=(Library const& lib);
	~Library();

	void add(const Book& book);
	bool remove(const Book& book);
	void shiftElementsFrom(int index);
	void copy(Book const* other);
	void copyLibrary(Library const& lib);
	void clearLibrary();
	double averagePages();
	Book& operator[] (int index);
	void sort_by_title();
};


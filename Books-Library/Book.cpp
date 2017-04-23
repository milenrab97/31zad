#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstring>
#include "Book.h"


Book::Book(char const* t, int p) : title(nullptr), pages(p) 
{
	setTitle(t);
}

Book::Book(Book const& b) : title(nullptr), pages(b.pages)
{
	setTitle(b.title);
}

Book & Book::operator=(Book const & b)
{
	if (this != &b) {
		setTitle(b.getTitle());
		setPages(b.getPages());
	}
	return *this;
}

Book::~Book()
{
	delete[] title;
}

char* Book::getTitle() const
{
	return this->title;
}

int Book::getPages()  const
{
	return this->pages;
}

void Book::setTitle(char const* n) {
	delete[] title;
	title = new char[strlen(n) + 1];
	strcpy(title, n);
}

void Book::setPages(int p) {
	this->pages = p;
}

std::istream& operator>>(std::istream & i, Book & b)
{
	const int MAX = 1000;
	char title[MAX];
	int pages;
	i.getline(title, MAX) >> pages;
	b.setTitle(title);
	b.setPages(pages);
	return i;
}

std::ostream& operator<<(std::ostream & o, Book const & b)
{
	return o << "Title: " << b.getTitle() << std::endl <<
		"Number of pages: " << b.getPages() << std::endl;
}

bool operator<(const Book & a, const Book & b)
{
	if (strcmp(a.getTitle(), b.getTitle()) < 0)
		return true;
	
	return false;
}

bool operator>(const Book & a, const Book & b)
{
	if (strcmp(a.getTitle(), b.getTitle()) > 0)
		return true;
	return false;
}


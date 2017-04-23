#pragma once
#include <iostream>

class Book
{
private:
	char* title;
	int pages;

public:
	//������ ��������
	Book(char const* title = "No Name", int pages = 0);
	Book(Book const&);
	Book& operator=(Book const& b);
	~Book();	
	
	//���������
	char* getTitle() const;
	int getPages() const;

	//��������
	void setTitle(char const* n);
	void setPages(int p);

};

std::istream& operator>>(std::istream& i, Book& b);
std::ostream& operator<<(std::ostream& o, Book const& b);
bool operator<(const Book& a, const Book& b);
bool operator>(const Book& a, const Book& b);

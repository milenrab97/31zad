#include <iostream>
#include "Book.h"
#include "Library.h"

int main() {
	Book kniga1("Kniga1", 10);
	Book kniga2("Kniga3", 5);
	Book kniga3("Kniga2", 10);
	Book kniga4("Kniga4", 5);
	Book kniga5("Kniga5", 10);
	Book kniga6("Kniga6", 5);

	Library lib;
	lib.add(kniga1);
	lib.add(kniga2);
	lib.add(kniga3);
	lib.add(kniga4);
	lib.add(kniga5);
	lib.add(kniga6);

	std::cout << lib.averagePages() << std::endl;

	std::cout << lib[0] << std::endl;
	std::cout << lib[1] << std::endl;
	lib.sort_by_title();
	std::cout << lib[0] << std::endl;
	std::cout << lib[1] << std::endl;

	system("pause");
	return 0;
}
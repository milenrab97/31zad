#include <iostream>
#include "Book.h"

int main() {
	Book kniga1("Kniga1", 10);
	std::cout << kniga1.getTitle() << std::endl;
	Book kniga2("Kniga2", 5);
	Book TheJungleBook;

	std::cout << kniga2;
	std::cin >> TheJungleBook;
	std::cout << TheJungleBook;
	std::cout << (kniga2 < kniga1) << std::endl << (kniga2 > kniga1) << std::endl;
	system("pause");
	return 0;
}
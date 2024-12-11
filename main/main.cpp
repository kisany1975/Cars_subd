#include <iostream>
#include "../List/List.h"


int main()
{
	List<int> ll1;

	ll1.push_back(5);
	std::cout << ll1 << '\n';
	std::cout << "ll1 Size: " << ll1.getSize() << "\n\n";


	ll1.push_front(6);
	std::cout << ll1 << '\n';
	std::cout << "ll1 Size: " << ll1.getSize() << "\n\n";

	ll1.push_back(7);
	std::cout << ll1 << '\n';
	std::cout << "ll1 Size: " << ll1.getSize() << "\n\n";

	ll1.push_front(8);
	std::cout << ll1 << '\n';
	std::cout << "ll1 Size: " << ll1.getSize() << "\n\n";

	ll1.push(9, 2);
	std::cout << ll1 << '\n';
	std::cout << "ll1 Size: " << ll1.getSize() << "\n\n";

	ll1.pop_back();
	std::cout << ll1 << '\n';
	std::cout << "ll1 Size: " << ll1.getSize() << "\n\n";

	ll1.pop_front();
	std::cout << ll1 << '\n';
	std::cout << "ll1 Size: " << ll1.getSize() << "\n\n";

	List<int> ll2(ll1);
	std::cout << "ll2 " << ll2 << '\n';

	List<int> ll3;
	ll3 = ll1;
	std::cout << "ll3 " << ll3 << '\n';

	List<int> ll4 = List<int>(std::move(ll3));
	std::cout << "ll4 " << ll4 << "\n";

	List<int> ll5 = std::move(ll4);
	std::cout << "ll5 " << ll5 << "\n";
	std::cout << "ll4 " << ll4 << "\n";

	return 0;
}

#include "Zombie.hpp"

#include <string>
#include <iostream>

int	main(void)
{
	Zombie	*heapZombie;

	// Heap allocation
	heapZombie = newZombie("HeapZ");
	heapZombie->announce();
	delete heapZombie;

	// Stack allocation
	randomChump("StackZ");

	return (0);
}
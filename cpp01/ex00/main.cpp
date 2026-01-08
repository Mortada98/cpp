#include "Zombie.hpp"

#include <string>
#include <iostream>

int	main(void)
{
	Zombie	*heapZombie;

	heapZombie = newZombie("HeapZ");
	heapZombie->announce();
	delete heapZombie;

	randomChump("StackZ");

	return (0);
}
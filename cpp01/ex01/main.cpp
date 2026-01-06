#include "Zombie.hpp"

#define HORDE_SIZE 10

int	main(void)
{
	Zombie	*horde;

	horde = zombieHorde(HORDE_SIZE, "HordeMember");
	
	if (horde == NULL)
		return (1);

	for (int i = 0; i < HORDE_SIZE; i++)
	{
		horde[i].announce();
	}

	delete [] horde;

	return (0);
}
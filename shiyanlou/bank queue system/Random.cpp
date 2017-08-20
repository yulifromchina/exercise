#include "Random.h"

Random::Random()
{
}


Random::~Random()
{

}

double Random::uniform(int max)
{
	return ((double)std::rand() / RAND_MAX)*max;
}
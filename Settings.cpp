#include "Settings.h"

std::string crossover_Method_String(bool abreviated) {

	if (abreviated)
	{
		switch (Settings::crossoverMethod)
		{
		case CrossoverMethod::ORDER:
			return ("OX");
		case CrossoverMethod::EDGE_RECOMBINATION:
			return ("ER");
		}
	}
	else {
		switch (Settings::crossoverMethod)
		{
		case CrossoverMethod::ORDER:
			return ("ORDER");
		case CrossoverMethod::EDGE_RECOMBINATION:
			return ("EDGE_RECOMBINATION");
		}
	}

}


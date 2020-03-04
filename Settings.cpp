#include "Settings.h"

std::string Settings::selection_Method_String() {
	switch (Settings::selectionMethod)
	{
	case SelectionMethod::TOURNAMENT:
		return ("Tournament");
	default:
		break;
	}
}

std::string Settings::mutation_Method_String() {
	switch (Settings::mutationMethod)
	{
	case MutationMethod::SWAP:
		return ("Swap");
	default:
		break;
	}
}

std::string Settings::crossover_Method_String(bool abreviated) {

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
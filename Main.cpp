// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include "GeneticAlgorithm.h"

int main()
{
	GeneticAlgorithm *ga = new GeneticAlgorithm;

	ga->main_Menu();

	delete ga;
}
// SDLTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Made by Henrik Thomasson @ BTH 2018
/*
/This program uses the SDL library to process an image.
*/

/*Gör ett program som applicerar filter på en PNG-fil.(Filen kommer att vara tillgänglig senare).
Programmet ska ta bildens filnamn som argument, en sträng som bestämmer filtret, och visa ett fönster med bilden samt spara en kopia på disk. Koden ska vara objektorienterad och det ska vara lätt att lägga till nya filter som en ny klass.
- Läs in bitmap bild
- Applicera inställningar (ex monokrom-filter).
- Gör modifierad image.
- Visa image //Done
- Exportera filtrerad image till ny image fil. //Done
*/
#include "pch.h"
#include <iostream>
#include "Image.h"
#include <string>
#include <fstream>

int main(int argc, char ** argv)
{
	//Check if too few arguments
	if (argc < 2)
		std::cout << "Too few arguments,you must enter a filename and a filter.";

	char* fileName = new char[30];
	char* filterName = new char[10];
	strcpy(filterName, argv[2]);
	strcpy(fileName, argv[1]);

	
	std::string outputFile = "outputFile.png";
	Image img;
	
	img.Initialize();
	img.loadImage(fileName);
	img.applyFilter(filterName);
	img.displayImage();
	img.Save();
	img.Clear();


	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

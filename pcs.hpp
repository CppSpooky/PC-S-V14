#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <stdio.h>

long double integration(std::string path, long double lb, long double ub) {

	/*
	int lower_bound = 330; //Untere Grenze der Intgration
	int upper_bound = 500; //Obere Grenze der Intgration

	std::string path = "C:/";
	std::vector<std::string> paths(0);
	std::string line;
	std::ofstream path_write; //Path write

	//Finde alle Dateien unter path und schreibe diese in paths.txt

	path_write.open("paths.txt");

	for (const auto & entry : std::experimental::filesystem::directory_iterator(path)) {
	path_write << entry.path() << std::endl;
	}

	path_write.close();

	//Erstelle Vektor paths mit den Paths aller Dateien aus path.txt, lösche anschließend paths.txt

	std::ifstream path_read; //Path read
	path_read.open("paths.txt");
	if (path_read.is_open()) {
	while (std::getline(path_read, line)) {
	paths.push_back(line);
	}
	}

	path_read.close();
	std::remove("paths.txt");


	for (size_t i = 0; i < paths.size(); i++) {
	std::cout << paths[i] << "\t" << integration(paths[i], lower_bound, upper_bound) << std::endl;
	}
	*/

	long double integral = 0;
	long double x = 0;
	long double y = 0;

	std::string read;
	std::string part_1;
	std::string part_2;
	std::string delimiter = "\t";
	int delimiter_position = 0;

	std::ifstream file;
	file.open(path);
	if (file.is_open()) {

		while (std::getline(file, read)) {

			delimiter_position = read.find(delimiter);
			part_1 = read.substr(0, delimiter_position);
			part_2 = read.substr(delimiter_position +1, read.length());

			try {
				x = std::stold(part_1);
				y = std::stold(part_2);
			}
			catch (const std::exception& e)
			{
				std::cerr << "Skipping invalid file " << path << ": " << std::endl;
				break; 
			}

			if (x >= lb && x <= ub) {
				integral = integral + (0.5 * stold(part_2));
				//std::cout << "i";
			}
			
			//std::cout << std::endl;
		}
	}

	else {

		std::cerr << "Error 1" << std::endl;
	}
	file.close();

	return integral;
}

long double find_max(std::string path) {

	//find_max("C:/");

	long double x_max = 0;
	long double y_max = 0;

	std::string read;
	std::string part_1;
	std::string part_2;
	std::string delimiter = "\t";
	int delimiter_position = 0;

	std::ifstream file;
	file.open(path);
	if (file.is_open()) {

		while (std::getline(file, read)) {

			delimiter_position = read.find(delimiter);
			part_1 = read.substr(0, delimiter_position);
			part_2 = read.substr(delimiter_position + 1, read.length());

			std::cout << stold(part_1) << "\t" << stold(part_2) << std::endl;

			if (std::stold(part_2) > y_max) {
				x_max = std::stold(part_1);
				y_max = std::stold(part_2);
			}
		}

	

	}

	//std::cout << x_max << "\t" << y_max << std::endl;

	return y_max;
}

long double find_intensity(std::string path, long double wavelenght) {

	long double intensity = 0;
	bool value_found = false;

	std::string read;
	std::string part_1;
	std::string part_2;
	std::string delimiter = "\t";
	int delimiter_position = 0;

	std::ifstream file;
	file.open(path);
	if (file.is_open()) {

		while (std::getline(file, read)) {

			delimiter_position = read.find(delimiter);
			part_1 = read.substr(0, delimiter_position);
			part_2 = read.substr(delimiter_position + 1, read.length());

			std::cout << stold(part_1) << "\t" << stold(part_2) << std::endl;

			if (std::stold(part_2) > y_max) {
				x_max = std::stold(part_1);
				y_max = std::stold(part_2);
			}
		}



	}





	return 0;
}

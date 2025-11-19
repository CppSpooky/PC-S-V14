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
			part_2 = read.substr(delimiter_position + 1, read.length());

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
			part_2 = read.substr(delimiter_position + 1, read.length());

			try {
				x = std::stold(part_1);
				y = std::stold(part_2);
			}
			catch (const std::exception& e)
			{
				std::cerr << "Skipping invalid file " << path << ": " << std::endl;
				break;
			}

			std::cout << x << "\t" << y << std::endl;

			if (std::stold(part_2) > y_max) {
				x_max = x;
				y_max = y;
			}
		}



	}

	std::cout << x_max << "\t" << y_max << std::endl;

	return y_max;
}

long double find_intensity(std::string path, long double wavelenght) {

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
			part_2 = read.substr(delimiter_position + 1, read.length());

			try {
				x = std::stold(part_1);
				y = std::stold(part_2);
			}
			catch (const std::exception& e)
			{
				std::cerr << "Skipping invalid file " << path << ": " << std::endl;
				break;
			}

			//std::cout << x << "\t" << y << std::endl;

			if (x == wavelenght) {
				return y;
			}

		}

	}

	std::cerr << "Wavelenght not found! : " << wavelenght << " in " << path << std::endl;

	return 0;
}

void log(long double x, long double y, std::string path, bool log_path) {

	std::ofstream file;
	file.open("devcpp360nm_at 416.txt", std::ios::app);

	if (file.is_open()) {
		if (log_path) {
			//file << x << "\t" << y << "\t" << path << "\n";
			file << path << "\t" << y << "\n";
		}
		else {
			//file << x << "\t" << y << "\n";
		}
	}

	else {
		std::cerr << "log fehlgeschlagen" << std::endl;

	}

	file.close();

}

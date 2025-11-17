#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <stdio.h>

long double integration(std::string path, long double lb, long double ub) {
	long double integral = 0;

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

			//std::cout << stold(part_1) << "\t" << stold(part_2);

			if (std::stold(part_1) >= lb && std::stold(part_1) <= ub) {
				integral = integral + (0.5 * stold(part_2));
				//std::cout << "i";
			}
			
			else{
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
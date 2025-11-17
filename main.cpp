#include "pcs.hpp"
#include <vector>
#include <filesystem>

int main(void) {
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

	for (int i = 0; i < paths.size(); i++) {
		std::cout << paths[i]  << "\t" <<integration(paths[i], lower_bound, upper_bound) <<std::endl;
	}

	return 0;
}
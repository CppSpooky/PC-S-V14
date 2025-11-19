#include "pcs.hpp"
#include <vector>
#include <filesystem>

int main(void) {

	std::string filename;
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

		filename = paths[i].substr(paths[i].find("ph") + 2, paths[i].length());
		filename = filename.substr(0, filename.length() - 10);
		std::cout << filename << std::endl;
		
		log(416, find_intensity(paths[i], 416), filename, true);

	}

	return 0;
}

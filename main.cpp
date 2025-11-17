#include "pcs.hpp"
#include <vector>
#include <filesystem>

int main(void) {
	int lower_bound = 330; //Untere Grenze der Intgration
	int upper_bound = 500; //Obere Grenze der Intgration

	std::string path = "C:/";
	std::vector<std::string> paths(0);
	std::string line;
	std::ofstream pw; //Path write

	//Finde alle Dateien unter path und schreibe diese in paths.txt

	pw.open("paths.txt");

	for (const auto & entry : std::experimental::filesystem::directory_iterator(path)) {
		pw << entry.path() << std::endl;
	}

	pw.close();

	//Erstelle Vektor paths mit den Paths aller Dateien aus path.txt, lösche anschließend paths.txt

	std::ifstream pr; //Path read
	pr.open("paths.txt");
	if (pr.is_open()) {
		while (std::getline(pr, line)) {
			paths.push_back(line);
		}
	}

	pw.close();
	std::remove("paths.txt");

	for (int i = 0; i < paths.size(); i++) {
		std::cout << paths[i]  << "\t" <<integration(paths[i], lower_bound, upper_bound) <<std::endl;
	}

	return 0;
}
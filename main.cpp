#include <iostream>
#include <string>
#include <random>

int main(int argc, char* argv[]) {

	int len = 12; // length of password
	bool digits = false; //0123456789
	bool SpecSymbols = false; //!@#$%^&*()-_=+[]{};:,.<>?/
	bool upper = false; //ABCDEFGHIJKLMNOPQRSTUVWXYZ
	int count = 1; //how much password will be generating

	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];
		
		if (arg == "--len" || arg == "-l") {
			if (i + 1 < argc) {
				len = std::stoi(argv[++i]);
			}
		} 
		else if (arg == "--digits") {
			digits = true;
		} 
		else if (arg == "--SpecSymbols") {
			SpecSymbols = true;
		} 
		else if (arg == "--upper") {
			upper = true;
		}
		else if (arg == "--count") {
			if (i + 1 < argc) {
				count = std::stoi(argv[++i]);
			}
		}
	}

	std::string charset = "abcdefghijklmnopqrstuvwxyz";
	if (digits) charset += "0123456789";
	if (SpecSymbols) charset += "!@#$%^&*()-_=+[]{};:,.<>?/";
	if (upper) charset += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	//Random number generator
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, charset.size() - 1);

	for (int i = 0; i < count; ++i) {
		std::string password;
		for (int j = 0; j < len; ++j) {
			password += charset[dist(gen)];
		}
		std::cout << password << std::endl;
	}


	return 0;
}


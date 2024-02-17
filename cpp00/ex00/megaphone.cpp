#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::string output;
	for (int i = 1; i < argc; i++)
	{
		std::string Megaphone(argv[i]);
		for (int len = 0; Megaphone[len]; len++)
			Megaphone[len] = toupper(Megaphone[len]);
		output += Megaphone;
        output += " ";
	}
	if (output.empty()) 
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		std::cout << output << std::endl;
	return (0);
}
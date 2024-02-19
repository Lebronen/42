/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:36:59 by lebronen          #+#    #+#             */
/*   Updated: 2024/02/18 13:37:00 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

std::string replace(std::string& str, const std::string& target, const std::string& replacement)
{
	if (target.empty())
		return str;

	std::string result;
	std::string::size_type pos = 0;
	std::string::size_type prevPos = 0;

	pos = str.find(target, pos);
	while (pos != std::string::npos)
	{
		result.append(str, prevPos, pos - prevPos);  // Copie la partie non affectée par le remplacement
		result.append(replacement);  // Ajoute la chaîne de remplacement
		pos += target.length();  // Passe à la prochaine occurrence de target
		prevPos = pos;  // Mémorise la position actuelle pour la prochaine itération
		pos = str.find(target, pos);
	}

	if (prevPos < str.length())
		result.append(str, prevPos, std::string::npos);

	return result;
}

int main(int argc, char const *argv[])
{
	if (argc != 4)
	{
		std::cout << "Usage: " << argv[0] << " <filename> <string> <replacement>" << std::endl;
		return 1;
	}

	std::string path = argv[1];
	std::string target = argv[2];
	std::string replacement = argv[3];
	std::ifstream input(path.c_str());

	if (!input || input.bad() || !input.is_open())
	{
		std::cout << "Failed to open " << path << "." << std::endl;
		return 2;
	}

	std::ostringstream oss;
	std::string line;

	while (std::getline(input, line))
        oss << line << '\n';
	
	std::string content = oss.str();
	input.close();
	std::string replaced = replace(content, target, replacement);
	std::ofstream output((path + ".replace").c_str());
	
	if (!output || output.bad() || !output.is_open())
	{
		std::cout << "Failed to create output file." << std::endl;
		return 3;
	}

	output << replaced;
	output.close();
	std::cout << "Replacement done!" << std::endl;

	return 0;
}
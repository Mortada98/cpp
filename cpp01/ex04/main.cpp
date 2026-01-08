#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


std::string replaceOccurrences(std::string content, std::string s1, std::string s2)
{
	if (s1.empty())
		return (content);

	size_t	pos = 0;

	while ((pos = content.find(s1, pos)) != std::string::npos)
	{
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos += s2.length();
	}
	return (content);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
	std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
		return (1);
	}

	std::string content;
	std::string line;
	while (std::getline(inputFile, line))
	{
			content += line;
		if (!inputFile.eof())
			content += "\n";
	}
	inputFile.close();

	std::string result = replaceOccurrences(content, s1, s2);

	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: Could not create output file" << std::endl;
		return (1);
	}

	outputFile << result;
	outputFile.close();

	return (0);
}
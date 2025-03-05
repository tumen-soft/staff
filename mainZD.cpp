#include <iostream>
#include <fstream>
#include <regex>
int main(){
std::ifstream file("sample.html");  
std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

std::regex p_tag_pattern("<p>(.*?)</p>");

std::smatch matches;
while (std::regex_search(content, matches, p_tag_pattern)) {
    std::cout << "Found <p> content: " << matches[1].str() << std::endl;
    content = matches.suffix().str();  // Move to the next part of the string
}
}

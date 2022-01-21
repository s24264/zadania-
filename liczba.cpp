#include <iostream>
#include <string>
auto ask_user_for_integer(std::string const prompt) -> int
{
    if (not prompt . empty()) {
    std::cout << prompt;
}
    auto value = std::string{};
    std::getline(std::cin, value);
    return std::stoi(value);

}
auto main()->int
{
auto a = ask_user_for_integer("a=");
auto b = ask_user_for_integer("b=");
if(a==b){
std::cout << a << "=" << b << std::endl;
return 0;}

else if(a>b){
std::cout << a << ">" << b << std::endl;
return 0;
}
else if(a<b){
std::cout << a << "<" << b << std::endl;
return 0;}
}

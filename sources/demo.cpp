#include <print.hpp>
#include <cstdlib>

int main(int argc, char** argv) {
        std::string text;
std::string log_path = std::getenv("LOG_PATH");
	std::ofstream out(log_path, std::ios_base::app);
        while(std::cin >> text) {
                print(text, out);
                out << std::endl;
        }
}

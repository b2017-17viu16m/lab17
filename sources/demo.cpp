#include <print.hpp>

int main(int argc, char** argv) {
        std::string text;
        while(std::cin >> text) {
                std::ofstream out("log.txt", std::ios_base::app);
                print(text, out);
                out << std::endl;
        }
}

#include <vector>
#include <iostream>
#include <string>


bool IsPalindrom(std::string& str) {
    std::string::iterator lhs = str.begin(), rhs = str.end() - 1;
    while (lhs < rhs) {
        if (*lhs != *rhs) {
            return false;
        }
        ++lhs;
        --rhs;
    }
    return true;
}

std::vector<std::string> PalindromFilter(std::vector<std::string> words, int minLength) {
    std::vector<std::string> result;
    for (auto&& it : words) {
        if (it.size() >= minLength && IsPalindrom(it)) {
            result.push_back(it);
        }
    }
    return result;
}


int main() {
    std::vector<std::string> src;
    std::vector<std::string> pal;
    std::string buffer;
    int minSize;

    std::cout << "Input words (break on empty):\n";
    while (true)
    {
        std::getline(std::cin, buffer);

        if (buffer.empty()) {
            break;
        }
        src.push_back(buffer);
        buffer.clear();
    }
    std::cout << "Input min word length: ";
    std::cin >> minSize;

    pal = PalindromFilter(src, minSize);
    for (auto& it : pal) {
        std::cout << it << '\n';
    }

    std::cout << '\n';
    system("pause");
    return 0;
}
#include <string>
#include <unordered_map>
#include <utility>
#include <iostream>
#include <ctime>

void unordered_map_insert (std::unordered_map<std::string, int> &, const std::string &);

int main(){

    std::unordered_map<std::string, int> words;
    std::string w;
    auto time = clock();
    while (std::cin >> w)
        unordered_map_insert(words, w);
    time = clock() - time;

    for (std::pair<std::string, int> x : words)
        std::cout << x.first << ": " << x.second << std::endl;
    std::cout << "\n=============================\n" << "elapsed time: " << double(time)/CLOCKS_PER_SEC << "\n=============================\n";

}

void unordered_map_insert(std::unordered_map<std::string, int> &m, const std::string &word){

    std::unordered_map<std::string, int>::iterator it = m.find(word);

    if (it == m.end())
        m.emplace(word, 1);
    else
        it->second += 1;
}

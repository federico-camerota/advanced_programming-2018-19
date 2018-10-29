#include <string>
#include <vector>
#include <iostream>
#include <ctime>

void binary_insert (std::vector<std::string> &, const std::string &);

int main(){

    std::vector<std::string> words;
    std::string w;
    auto time = clock();
    while (std::cin >> w)
        binary_insert(words, w);
    time = clock() - time;

    for (const std::string a : words)
        std::cout << a << std::endl;
    std::cout << "\n=============================\n" << "elapsed time: " << double(time)/CLOCKS_PER_SEC << "\n=============================\n";

}

void binary_insert(std::vector<std::string> &v, const std::string &word){

    std::size_t lo, hi;
    lo = 0, hi = v.size();
    if (hi == 0U)
        v.push_back(word);
    else{
        while (lo < hi){
    
            std::size_t mid = (lo + hi)/2;
            if (v.at(mid) > word)
                hi = mid;
            else if (v.at(mid) < word)
                lo = mid + 1;
            else
                return;
        }
        v.insert(v.begin() + lo, word);
    }
}

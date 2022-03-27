#include <iostream>
#include <string>


template <size_t bitset_size>
std::string foo(std::string source, std::bitset<bitset_size> key) {
    int step = bitset_size - 8;
    int last_saved = 0;
    std::string result;

    for(auto c : source) {
        
        std::bitset<8> cur_key = std::bitset<8>(key.to_ulong()) << last_saved;
        cur_key = cur_key ^ (std::bitset<8>)(key.to_ulong() >> (bitset_size - last_saved));
        
        std::cout << cur_key <<  " ";
        
        last_saved = (last_saved + step) % bitset_size;
        
        char converted_char = c ^ char(key.to_ulong());
        result.push_back(converted_char);
    }
    std::cout << std::endl;
    return result;
}

int main() {
    std::string source = "Hello world!";
    std::bitset<10> key = 0b1111100000;
    std::string result = foo<10>(source, key);
    
    std::cout << result << std::endl;
    std::cout << foo<10>(result, key) << std::endl;
    
    for(auto c : source) {
        std::cout << std::bitset<8>(c) << " ";
    }
    std::cout << std::endl;

    for(auto c : result) {
        std::cout << std::bitset<8>(c) << " ";
    }
    std::cout << std::endl;


    return 0;
   
}



//
// Created by pokam on 24.02.2023.
//

#ifndef DATASET_DATASET_H
#define DATASET_DATASET_H

#include <bitset>
#include <array>
#include <vector>

class Dataset{
public:
    Dataset();
    explicit Dataset(int n);
    static std::bitset<8> setByte(const std::bitset<8>&);
    static bool isValidateByte(const std::bitset<8>&);
    void setDataset();
    void print();
private:
    static const int MAX=100;
    //std::array<std::bitset<8>, MAX>m_Dataset;

    std::vector<std::bitset<8>>m_Dataset;
    std::bitset<8> random_bitset( double p = 0.5);
    
};
#endif //DATASET_DATASET_H

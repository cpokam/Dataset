//
// Created by pokam on 24.02.2023.
//

#ifndef DATASET_DATASET_H
#define DATASET_DATASET_H

#include <bitset>
#include <array>

class Dataset{
public:
    Dataset();
    explicit Dataset(int n);
    static std::bitset<8> setByte(std::bitset<8>);
    static bool isByte(std::bitset<8>);
    void sortDataset();
    void print();
private:
    static const int MAX=10;
    std::bitset<8> random_bitset( double p = 0.5);
    std::array<std::bitset<8>, MAX>m_Dataset;
};
#endif //DATASET_DATASET_H

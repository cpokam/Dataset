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
    /**
     * @brief Construct a new Dataset object with 100 elements
     * 
     */
    Dataset();

    /**
     * @brief Construct a new Dataset object with n elements
     * 
     * @param n number of elements
     */
    explicit Dataset(int n);

    /**
     * @brief Set the Byte object if it is a valid one.
     * 
     * @return std::bitset<8> The changed byte
     */
    static std::bitset<8> setByte(const std::bitset<8>&);

    /**
     * @brief check the validity of a byte, according to the given rule
     * 
     * @return true if the validity was checked, false otherwise.
     */
    static bool isValidateByte(const std::bitset<8>&);

    /**
     * @brief Modify the Dataset object if it is valid
     * 
     */
    void setDataset();

    /**
     * @brief print the dataset
     * 
     */
    void print();
private:
    static const int MAX=100;
    //std::array<std::bitset<8>, MAX>m_Dataset;

    std::vector<std::bitset<8>>m_Dataset;
    std::bitset<8> random_bitset( double p = 0.5);
    
};
#endif //DATASET_DATASET_H

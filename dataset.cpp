//
// Created by pokam on 24.02.2023.
//
#include <iostream>
#include <bitset>
#include <random>
#include <cassert>
#include "dataset.h"

Dataset::Dataset():m_Dataset(MAX){
    for( size_t i = 0; i < m_Dataset.size(); ++i) {
        m_Dataset.at(i)=random_bitset();
    }
}

Dataset::Dataset(int n):m_Dataset(n) {
    assert(n<=MAX);
    for( size_t i = 0; i < m_Dataset.size(); ++i) {
        m_Dataset.at(i)=random_bitset();
    }
}

std::bitset<8> Dataset::random_bitset(double p) {

    typename std::bitset<8> bits;
    std::random_device rd;
    std::mt19937 gen( rd());
    std::bernoulli_distribution d( p);

    for( int n = 0; n < 8; ++n) {
        bits[ n] = d( gen);
    }
    return bits;
}

void Dataset::print() {
    std::cout << std::endl;
    for( size_t n = 0; n < m_Dataset.size(); ++n) {
        std::cout << m_Dataset[n]<< '\t';
        if( ((n+1) % 5 == 0) )
            std::cout<<std::endl;
    }
    std::cout<<std::endl<<"========"<<std::endl;
}

bool Dataset::isValidateByte(const std::bitset<8> &byte) {
    bool result = false;

    //Assign new values for the left and right bytes, with the string initialization
    left=std::bitset<4>(byte.to_string(),0,4);
    right=std::bitset<4>(byte.to_string(),4);
    
    if (left.size()-left.count() == right.size()-right.count())
        result = true;
    return result;
}

std::bitset<8> Dataset::setByte() {
    std::bitset<8>result;

    //Assign new values for the left and right bytes, with the binary initialization
    left=std::bitset<4>(left.size()-left.count());
    right=std::bitset<4>(right.count());

    std::string s(left.to_string()+right.to_string());
    result= std::bitset<8>(s);

    return result;
}

void Dataset::setDataset() {
    for(size_t i=0; i<m_Dataset.size();++i){
        if(isValidateByte(m_Dataset[i])){
            m_Dataset[i]= setByte();
        }
    }
}




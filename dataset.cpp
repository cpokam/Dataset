//
// Created by pokam on 24.02.2023.
//
#include <iostream>
#include <bitset>
#include <random>
#include <cassert>
#include "dataset.h"


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

Dataset::Dataset() {
    for( int i = 0; i < MAX; ++i) {
        m_Dataset.at(i)=random_bitset();
    }
}

Dataset::Dataset(int n) {
    assert(n<=MAX);
    for( int i = 0; i < n; ++i) {
        m_Dataset.at(i)=random_bitset();
    }
}

void Dataset::print() {
    std::cout << std::endl;
    for( int n = 0; n < m_Dataset.size(); ++n) {
        std::cout << m_Dataset[n]<< '\t';
        if( (n>1) && (n % 5 == 0) )
            std::cout<<std::endl;
    }
    std::cout << std::endl<<"======================";
}

bool Dataset::isByte(std::bitset<8> byte) {
    bool result = false;
    std::bitset<4>left(byte.to_string(),0,3);
    std::bitset<4>right(byte.to_string(),4);
    if (left.size()-left.count() == right.size()-right.count()){
        result = true;
    }
  return result;
}

std::bitset<8> Dataset::setByte(std::bitset<8> byte) {
    std::bitset<8>result;
    std::bitset<4>left(byte.to_string(),0,3);
    std::bitset<4>right(byte.to_string(),4);

    left=left.size()-left.count();
    right=right.count();
    std::string s(left.to_string()+right.to_string());
    result= std::bitset<8>(s);

    return result;
}

void Dataset::sortDataset() {
    for(int i=0; i<m_Dataset.size();++i){
        if(isByte(m_Dataset[i])){
            m_Dataset[i]= setByte(m_Dataset[i]);
        }
    }
}




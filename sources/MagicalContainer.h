//
// Created by avi on 24/05/2023.
//

#ifndef CPP_EX4_PARTA_MAGICALCONTAINER_H
#define CPP_EX4_PARTA_MAGICALCONTAINER_H

using namespace std;
#include <iostream>
#include <vector>

class MagicalContainer
{
private:
    vector<int> mystical_elements;
public:
    MagicalContainer();
    void addElement(int element);
    void removeElement(int element);
    int size();
};

class AscendingIterator
{
private:
    MagicalContainer* magic_ctr;
public:
    AscendingIterator(MagicalContainer &magic_ctr);
    AscendingIterator(AscendingIterator& other);
    ~AscendingIterator();
    AscendingIterator& operator=(const AscendingIterator& other);
    bool operator==(const AscendingIterator& other);
    bool operator!=(const AscendingIterator& other);
    bool operator>(const AscendingIterator& other);
    bool operator<(const AscendingIterator& other);
    int operator*() const;
    AscendingIterator& operator++();
    AscendingIterator *begin();
    AscendingIterator *end();
};

class SideCrossIterator
{
private:
    MagicalContainer* magic_ctr;
public:
    SideCrossIterator(MagicalContainer &magic_ctr);
    SideCrossIterator(SideCrossIterator& other);
    ~SideCrossIterator();
    SideCrossIterator& operator=(const SideCrossIterator& other);
    bool operator==(const SideCrossIterator& other);
    bool operator!=(const SideCrossIterator& other);
    bool operator>(const SideCrossIterator& other);
    bool operator<(const SideCrossIterator& other);
    int operator*() const;
    SideCrossIterator& operator++();
    SideCrossIterator *begin();
    SideCrossIterator *end();
};

class PrimeIterator
{
private:
    MagicalContainer* magic_ctr;
public:
    PrimeIterator(MagicalContainer &magic_ctr);
    PrimeIterator(PrimeIterator& other);
    ~PrimeIterator();
    PrimeIterator& operator=(const PrimeIterator& other);
    bool operator==(const PrimeIterator& other);
    bool operator!=(const PrimeIterator& other);
    bool operator>(const PrimeIterator& other);
    bool operator<(const PrimeIterator& other);
    int operator*() const;
    PrimeIterator& operator++();
    PrimeIterator *begin();
    PrimeIterator *end();
};

#endif // CPP_EX4_PARTA_MAGICALCONTAINER_H
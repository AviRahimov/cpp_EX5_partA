//
// Created by avi on 24/05/2023.
//

#ifndef CPP_EX4_PARTA_MAGICALCONTAINER_H
#define CPP_EX4_PARTA_MAGICALCONTAINER_H

// using namespace std;
#include <iostream>
#include <vector>

namespace ariel
{
    class MagicalContainer
    {
    private:
        std::vector<int> mystical_elements;

    public:
        MagicalContainer() {}
        void addElement(int element)
        {
            this->mystical_elements.push_back(element);
        }

        void removeElement(int element)
        {
            // Find the element in the vector and remove it
            auto it = std::find(mystical_elements.begin(), mystical_elements.end(), element);
            if (it != mystical_elements.end())
            {
                mystical_elements.erase(it);
            }
        }

        int size()
        {
            return this->mystical_elements.size();
        }

        class AscendingIterator
        {
        private:
            MagicalContainer *magic_ctr;
            std::size_t index;

        public:
            AscendingIterator(MagicalContainer &magic_ctr) : magic_ctr(&magic_ctr), index(0) {}
            AscendingIterator(AscendingIterator &other) : magic_ctr(other.magic_ctr), index(other.index)
            {
            }

            ~AscendingIterator()
            {
            }

            AscendingIterator &operator=(const AscendingIterator &other)
            {
                if (this != &other) {
                    magic_ctr = other.magic_ctr;
                    index = other.index;
                }
                return *this;
            }

            bool operator==(const AscendingIterator &other) const
            {
                return magic_ctr == other.magic_ctr && this->index == other.index;
            }

            bool operator!=(const AscendingIterator &other) const
            {
                return !(*this == other);
            }

            bool operator>(const AscendingIterator &other)
            {
                return this->magic_ctr->mystical_elements[index] == other.magic_ctr->mystical_elements[index];
            }

            bool operator<(const AscendingIterator &other)
            {
                return true;
            }

            int operator*() const
            {
                return this->magic_ctr->mystical_elements[index];
            }

            AscendingIterator &operator++()
            {
                ++index;
                return *this;
            }

            AscendingIterator begin()
            {
                return AscendingIterator(*magic_ctr);
            }

            AscendingIterator end()
            {
                AscendingIterator iter(*magic_ctr);
                iter.index = magic_ctr->mystical_elements.size();
                return iter;
            }
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer *magic_ctr;
            std::size_t index;

        public:
            SideCrossIterator(MagicalContainer &magic_ctr) : magic_ctr(&magic_ctr), index(0)
            {
            }
            SideCrossIterator(SideCrossIterator &other) : magic_ctr(other.magic_ctr), index(other.index)
            {
            }
            ~SideCrossIterator()
            {
            }
            SideCrossIterator &operator=(const SideCrossIterator &other)
            {
                if (this != &other) {
                    magic_ctr = other.magic_ctr;
                    index = other.index;
                }
                return *this;
            }
            bool operator==(const SideCrossIterator &other) const
            {
                return magic_ctr == other.magic_ctr;
            }
            bool operator!=(const SideCrossIterator &other) const
            {
                return !(*this == other);
            }
            bool operator>(const SideCrossIterator &other)
            {
                return this->magic_ctr->mystical_elements[index] == other.magic_ctr->mystical_elements[index];
            }
            bool operator<(const SideCrossIterator &other)
            {
                return true;
            }
            int operator*() const
            {
                return this->magic_ctr->mystical_elements[index];
            }
            SideCrossIterator &operator++()
            {
                ++index;
                return *this;
            }
            SideCrossIterator begin()
            {
                return SideCrossIterator(*magic_ctr);
            }
            SideCrossIterator end()
            {
                SideCrossIterator iter(*magic_ctr);
                iter.index = magic_ctr->mystical_elements.size();
                return iter;
            }
        };

        class PrimeIterator
        {
        private:
            MagicalContainer *magic_ctr;
            std::size_t index;

        public:
            PrimeIterator(MagicalContainer &magic_ctr) : magic_ctr(&magic_ctr), index(0)
            {
            }
            PrimeIterator(PrimeIterator &other) : magic_ctr(other.magic_ctr), index(other.index)
            {
            }
            ~PrimeIterator()
            {
            }
            PrimeIterator &operator=(const PrimeIterator &other)
            {
                if (this != &other) {
                    magic_ctr = other.magic_ctr;
                    index = other.index;
                }
                return *this;
            }
            bool operator==(const PrimeIterator &other) const
            {
                return magic_ctr == other.magic_ctr;
            }
            bool operator!=(const PrimeIterator &other) const
            {
                return !(*this == other);
            }
            bool operator>(const PrimeIterator &other)
            {
                return this->magic_ctr->mystical_elements[index] == other.magic_ctr->mystical_elements[index];
            }
            bool operator<(const PrimeIterator &other)
            {
                return true;
            }
            int operator*() const
            {
                return this->magic_ctr->mystical_elements[index];
            }
            PrimeIterator &operator++()
            {
                ++index;
                return *this;
            }
            PrimeIterator begin()
            {
                return PrimeIterator(*magic_ctr);
            }
            PrimeIterator end()
            {
                PrimeIterator iter(*magic_ctr);
                iter.index = magic_ctr->mystical_elements.size();
                return iter;
            }
        };
    };
}
#endif // CPP_EX4_PARTA_MAGICALCONTAINER_H
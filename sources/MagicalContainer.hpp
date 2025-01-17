//
// Created by avi on 24/05/2023.
//

/**
 * @file MagicalContainer.h
 * @brief Defines the MagicalContainer class and its iterators.
 */

#ifndef CPP_EX4_PARTA_MAGICALCONTAINER_H
#define CPP_EX4_PARTA_MAGICALCONTAINER_H

#include <iostream>
#include <vector>

namespace ariel
{
    /**
     * @class MagicalContainer
     * @brief A container class that holds mystical elements.
     *
     * The MagicalContainer class stores a collection of mystical elements. It provides
     * methods to add and remove elements from the container, as well as access the size
     * of the container.
     */
    class MagicalContainer
    {
    private:
        std::vector<int> mystical_elements; /**< The underlying vector to store the elements. */

    public:
        /**
         * @brief Constructs an empty MagicalContainer object.
         */
        MagicalContainer() {}

        /**
         * @brief Adds an element to the container.
         * @param element The element to be added.
         */
        void addElement(int element)
        {
            this->mystical_elements.push_back(element);
        }

        /**
         * @brief Removes an element from the container.
         * @param element The element to be removed.
         *
         * If the element exists in the container, it will be removed. If there are multiple
         * occurrences of the element, only the first occurrence will be removed.
         */
        void removeElement(int element)
        {
            // Find the element in the vector and remove it
            auto it = std::find(mystical_elements.begin(), mystical_elements.end(), element);

            if (it != mystical_elements.end())
            {
                mystical_elements.erase(it);
            }
            else{
                throw std::out_of_range("The number is not in the container");
            }
        }

        /**
         * @brief Returns the number of elements in the container.
         * @return The size of the container.
         */
        int size()
        {
            return this->mystical_elements.size();
        }

        /**
         * @class AscendingIterator
         * @brief An iterator that iterates over the elements in ascending order.
         *
         * The AscendingIterator class provides an iterator that allows traversing the elements
         * in ascending order in the MagicalContainer.
         */
        class AscendingIterator
        {
        private:
            MagicalContainer *magic_ctr; /**< Pointer to the MagicalContainer object. */
            std::size_t index;           /**< Index indicating the current position in the container. */

        public:
            /**
             * @brief Constructs an AscendingIterator object.
             * @param magic_ctr The MagicalContainer to iterate over.
             */
            AscendingIterator(MagicalContainer &magic_ctr) : magic_ctr(&magic_ctr), index(0) {}

            /**
             * @brief Copy constructor for AscendingIterator.
             * @param other The AscendingIterator to copy from.
             */
            AscendingIterator(const AscendingIterator &other) : magic_ctr(other.magic_ctr), index(other.index) {}

            /**
             * @brief Destructor for AscendingIterator.
             */
            ~AscendingIterator() {}

            /**
             * @brief Assignment operator for AscendingIterator.
             * @param other The AscendingIterator to assign from.
             * @return Reference to the assigned AscendingIterator.
             */
            AscendingIterator &operator=(const AscendingIterator &other)
            {
                if (this != &other)
                {
                    magic_ctr = other.magic_ctr;
                    index = other.index;
                }
                return *this;
            }

            /**
             * @brief Equality comparison operator.
             * @param other The AscendingIterator to compare with.
             * @return True if the iterators are equal, false otherwise.
             */
            bool operator==(const AscendingIterator &other) const
            {
                return magic_ctr == other.magic_ctr && index == other.index;
            }

            /**
             * @brief Inequality comparison operator.
             * @param other The AscendingIterator to compare with.
             * @return True if the iterators are not equal, false otherwise.
             */
            bool operator!=(const AscendingIterator &other) const
            {
                return !(*this == other);
            }

            /**
             * @brief Greater than comparison operator.
             * @param other The AscendingIterator to compare with.
             * @return True if this iterator is greater than the other iterator, false otherwise.
             */
            bool operator>(const AscendingIterator &other)
            {
                return magic_ctr->mystical_elements[index] == other.magic_ctr->mystical_elements[index];
            }

            /**
             * @brief Less than comparison operator.
             * @param other The AscendingIterator to compare with.
             * @return True if this iterator is less than the other iterator, false otherwise.
             */
            bool operator<(const AscendingIterator &other)
            {
                return true;
            }

            /**
             * @brief Dereference operator.
             * @return The element at the current position of the iterator.
             */
            int operator*() const
            {
                return magic_ctr->mystical_elements[index];
            }

            /**
             * @brief Pre-increment operator.
             * @return Reference to the incremented iterator.
             */
            AscendingIterator &operator++()
            {
                ++index;
                return *this;
            }

            /**
             * @brief Returns the beginning iterator of the container.
             * @return The beginning iterator.
             */
            AscendingIterator begin()
            {
                return AscendingIterator(*magic_ctr);
            }

            /**
             * @brief Returns the ending iterator of the container.
             * @return The ending iterator.
             */
            AscendingIterator end()
            {
                AscendingIterator iter(*magic_ctr);
                iter.index = magic_ctr->mystical_elements.size();
                return iter;
            }
        };

        /**
         * @class SideCrossIterator
         * @brief An iterator that iterates over the elements in a side-cross pattern.
         *
         * The SideCrossIterator class provides an iterator that allows traversing the elements
         * in a side-cross pattern in the MagicalContainer.
         */
        class SideCrossIterator
        {
        private:
            MagicalContainer *magic_ctr; /**< Pointer to the MagicalContainer object. */
            std::size_t index;           /**< Index indicating the current position in the container. */

        public:
            /**
             * @brief Constructs a SideCrossIterator object.
             * @param magic_ctr The MagicalContainer to iterate over.
             */
            SideCrossIterator(MagicalContainer &magic_ctr) : magic_ctr(&magic_ctr), index(0) {}

            /**
             * @brief Copy constructor for SideCrossIterator.
             * @param other The SideCrossIterator to copy from.
             */
            SideCrossIterator(const SideCrossIterator &other) : magic_ctr(other.magic_ctr), index(other.index) {}

            /**
             * @brief Destructor for SideCrossIterator.
             */
            ~SideCrossIterator() {}

            /**
             * @brief Assignment operator for SideCrossIterator.
             * @param other The SideCrossIterator to assign from.
             * @return Reference to the assigned SideCrossIterator.
             */
            SideCrossIterator &operator=(const SideCrossIterator &other)
            {
                if (this != &other)
                {
                    magic_ctr = other.magic_ctr;
                    index = other.index;
                }
                return *this;
            }

            /**
             * @brief Equality comparison operator.
             * @param other The SideCrossIterator to compare with.
             * @return True if the iterators are equal, false otherwise.
             */
            bool operator==(const SideCrossIterator &other) const
            {
                return magic_ctr == other.magic_ctr;
            }

            /**
             * @brief Inequality comparison operator.
             * @param other The SideCrossIterator to compare with.
             * @return True if the iterators are not equal, false otherwise.
             */
            bool operator!=(const SideCrossIterator &other) const
            {
                return !(*this == other);
            }

            /**
             * @brief Greater than comparison operator.
             * @param other The SideCrossIterator to compare with.
             * @return True if this iterator is greater than the other iterator, false otherwise.
             */
            bool operator>(const SideCrossIterator &other)
            {
                return magic_ctr->mystical_elements[index] == other.magic_ctr->mystical_elements[index];
            }

            /**
             * @brief Less than comparison operator.
             * @param other The SideCrossIterator to compare with.
             * @return True if this iterator is less than the other iterator, false otherwise.
             */
            bool operator<(const SideCrossIterator &other)
            {
                return true;
            }

            /**
             * @brief Dereference operator.
             * @return The element at the current position of the iterator.
             */
            int operator*() const
            {
                return magic_ctr->mystical_elements[index];
            }

            /**
             * @brief Pre-increment operator.
             * @return Reference to the incremented iterator.
             */
            SideCrossIterator &operator++()
            {
                ++index;
                return *this;
            }

            /**
             * @brief Returns the beginning iterator of the container.
             * @return The beginning iterator.
             */
            SideCrossIterator begin()
            {
                return SideCrossIterator(*magic_ctr);
            }

            /**
             * @brief Returns the ending iterator of the container.
             * @return The ending iterator.
             */
            SideCrossIterator end()
            {
                SideCrossIterator iter(*magic_ctr);
                iter.index = magic_ctr->mystical_elements.size();
                return iter;
            }
        };

        /**
         * @class PrimeIterator
         * @brief An iterator that iterates over the prime elements in the container.
         *
         * The PrimeIterator class provides an iterator that allows traversing the prime
         * elements in the MagicalContainer.
         */
        class PrimeIterator
        {
        private:
            MagicalContainer *magic_ctr; /**< Pointer to the MagicalContainer object. */
            std::size_t index;           /**< Index indicating the current position in the container. */

        public:
            /**
             * @brief Constructs a PrimeIterator object.
             * @param magic_ctr The MagicalContainer to iterate over.
             */
            PrimeIterator(MagicalContainer &magic_ctr) : magic_ctr(&magic_ctr), index(0) {}

            /**
             * @brief Copy constructor for PrimeIterator.
             * @param other The PrimeIterator to copy from.
             */
            PrimeIterator(const PrimeIterator &other) : magic_ctr(other.magic_ctr), index(other.index) {}

            /**
             * @brief Destructor for PrimeIterator.
             */
            ~PrimeIterator() {}

            /**
             * @brief Assignment operator for PrimeIterator.
             * @param other The PrimeIterator to assign from.
             * @return Reference to the assigned PrimeIterator.
             */
            PrimeIterator &operator=(const PrimeIterator &other)
            {
                if (this != &other)
                {
                    magic_ctr = other.magic_ctr;
                    index = other.index;
                }
                return *this;
            }

            /**
             * @brief Equality comparison operator.
             * @param other The PrimeIterator to compare with.
             * @return True if the iterators are equal, false otherwise.
             */
            bool operator==(const PrimeIterator &other) const
            {
                return magic_ctr == other.magic_ctr;
            }

            /**
             * @brief Inequality comparison operator.
             * @param other The PrimeIterator to compare with.
             * @return True if the iterators are not equal, false otherwise.
             */
            bool operator!=(const PrimeIterator &other) const
            {
                return !(*this == other);
            }

            /**
             * @brief Greater than comparison operator.
             * @param other The PrimeIterator to compare with.
             * @return True if this iterator is greater than the other iterator, false otherwise.
             */
            bool operator>(const PrimeIterator &other)
            {
                return magic_ctr->mystical_elements[index] == other.magic_ctr->mystical_elements[index];
            }

            /**
             * @brief Less than comparison operator.
             * @param other The PrimeIterator to compare with.
             * @return True if this iterator is less than the other iterator, false otherwise.
             */
            bool operator<(const PrimeIterator &other)
            {
                return true;
            }

            /**
             * @brief Dereference operator.
             * @return The element at the current position of the iterator.
             */
            int operator*() const
            {
                return magic_ctr->mystical_elements[index];
            }

            /**
             * @brief Pre-increment operator.
             * @return Reference to the incremented iterator.
             */
            PrimeIterator &operator++()
            {
                ++index;
                return *this;
            }

            /**
             * @brief Returns the beginning iterator of the container.
             * @return The beginning iterator.
             */
            PrimeIterator begin()
            {
                return PrimeIterator(*magic_ctr);
            }

            /**
             * @brief Returns the ending iterator of the container.
             * @return The ending iterator.
             */
            PrimeIterator end()
            {
                PrimeIterator iter(*magic_ctr);
                iter.index = magic_ctr->mystical_elements.size();
                return iter;
            }
        };
    };
} // namespace ariel

#endif //CPP_EX4_PARTA_MAGICALCONTAINER_H

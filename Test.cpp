#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;

TEST_CASE("MagicalContainer Tests")
{
    SUBCASE("Adding Elements and Size")
    {
        MagicalContainer container;

        CHECK(container.size() == 0);

        container.addElement(5);
        container.addElement(2);
        container.addElement(7);

        CHECK(container.size() == 3);
    }

    SUBCASE("Removing Elements")
    {
        MagicalContainer container;

        container.addElement(5);
        container.addElement(2);
        container.addElement(7);

        container.removeElement(2);

        CHECK(container.size() == 2);

        // Verify that the removed element is not present in the container
        MagicalContainer::AscendingIterator ascIter(container);
        for (auto it = ascIter.begin(); it != ascIter.end(); ++it)
        {
            CHECK(*it != 2);
        }
    }

    SUBCASE("AscendingIterator")
    {
        MagicalContainer container;

        container.addElement(1);
        container.addElement(5);
        container.addElement(2);
        container.addElement(7);
        container.addElement(4);

        // Test AscendingIterator using CHECK
        std::vector<int> expectedAscendingOrder = {1, 5, 2, 7, 4};
        std::size_t index = 0;
        MagicalContainer::AscendingIterator ascIter(container);
        for (auto it = ascIter.begin(); it != ascIter.end(); ++it)
        {
            CHECK(*it == expectedAscendingOrder[index]);
            index++;
        }
    }

    SUBCASE("SideCrossIterator")
    {
        MagicalContainer container;

        container.addElement(1);
        container.addElement(5);
        container.addElement(2);
        container.addElement(7);
        container.addElement(4);

        // Test SideCrossIterator using CHECK
        std::vector<int> expectedCrossOrder = {1, 7, 2, 5, 4};
        std::size_t index = 0;
        MagicalContainer::SideCrossIterator crossIter(container);
        for (auto it = crossIter.begin(); it != crossIter.end(); ++it)
        {
            std::cout << *it << std::endl;
            CHECK(*it == expectedCrossOrder[index]);
            index++;
        }
    }

    SUBCASE("PrimeIterator")
    {
        MagicalContainer container;

        container.addElement(1);
        container.addElement(5);
        container.addElement(2);
        container.addElement(7);
        container.addElement(4);

        // Test PrimeIterator using CHECK
        std::vector<int> expectedPrimeNumbers = {2, 5, 7};
        std::size_t index = 0;
        MagicalContainer::PrimeIterator primeIter(container);
        for (auto it = primeIter.begin(); it != primeIter.end(); ++it)
        {
            CHECK(*it == expectedPrimeNumbers[index]);
            index++;
        }
    }

    SUBCASE("Prime Numbers")
    {
        MagicalContainer container;

        container.addElement(2);
        container.addElement(3);
        container.addElement(5);
        container.addElement(7);
        container.addElement(11);

        // Test PrimeIterator with prime numbers
        std::vector<int> expectedPrimeNumbers = {2, 3, 5, 7, 11};
        std::size_t index = 0;
        MagicalContainer::PrimeIterator primeIter(container);
        for (auto it = primeIter.begin(); it != primeIter.end(); ++it)
        {
            CHECK(*it == expectedPrimeNumbers[index]);
            index++;
        }
    }

    SUBCASE("Large Container")
    {
        MagicalContainer container;

        for (int i = 1; i <= 1000; i++)
        {
            container.addElement(i);
        }

        // Test AscendingIterator with a large container
        std::size_t index = 1;
        MagicalContainer::AscendingIterator ascIter(container);
        for (auto it = ascIter.begin(); it != ascIter.end(); ++it)
        {
            CHECK(*it == index);
            index++;
        }

        // Test SideCrossIterator with a large container
        std::vector<int> expectedCrossOrder;
        for (int i = 1; i <= 500; i++)
        {
            expectedCrossOrder.push_back(i);
            expectedCrossOrder.push_back(1001 - i);
        }
        if (expectedCrossOrder.size() < 1000)
        {
            expectedCrossOrder.push_back(501);
        }
        index = 0;
        MagicalContainer::SideCrossIterator crossIter(container);
        for (auto it = crossIter.begin(); it != crossIter.end(); ++it)
        {
            CHECK(*it == expectedCrossOrder[index]);
            index++;
        }

        // Test PrimeIterator with a large container
        std::vector<int> expectedPrimeNumbers = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
                                                 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193,
                                                 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311,
                                                 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433,
                                                 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569,
                                                 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683,
                                                 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827,
                                                 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971,
                                                 977, 983, 991, 997};
        index = 0;
        MagicalContainer::PrimeIterator primeIter(container);
        for (auto it = primeIter.begin(); it != primeIter.end(); ++it)
        {
            CHECK(*it == expectedPrimeNumbers[index]);
            index++;
        }
    }
}

TEST_CASE("Exception Tests")
{
    SUBCASE("Adding Elements")
    {
        MagicalContainer container;

        CHECK_NOTHROW(container.addElement(5));
        CHECK_NOTHROW(container.addElement(2));
        CHECK_NOTHROW(container.addElement(0));
        CHECK_NOTHROW(container.addElement(-1));
    }

    SUBCASE("Removing Elements")
    {
        MagicalContainer container;

        container.addElement(5);
        container.addElement(2);
        container.addElement(7);

        CHECK_NOTHROW(container.removeElement(2));
        CHECK_NOTHROW(container.removeElement(5));

        CHECK_THROWS_AS(container.removeElement(10), std::out_of_range);
    }

    SUBCASE("AscendingIterator")
    {
        MagicalContainer container;

        container.addElement(1);
        container.addElement(5);
        container.addElement(2);
        container.addElement(7);
        container.addElement(4);

        MagicalContainer::AscendingIterator ascIter(container);
        CHECK_NOTHROW(ascIter.begin());
        CHECK_NOTHROW(ascIter.end());
    }

    SUBCASE("SideCrossIterator")
    {
        MagicalContainer container;

        container.addElement(1);
        container.addElement(5);
        container.addElement(2);
        container.addElement(7);
        container.addElement(4);

        MagicalContainer::SideCrossIterator crossIter(container);
        CHECK_NOTHROW(crossIter.begin());
        CHECK_NOTHROW(crossIter.end());
    }

    SUBCASE("PrimeIterator")
    {
        MagicalContainer container;

        container.addElement(1);
        container.addElement(5);
        container.addElement(2);
        container.addElement(7);
        container.addElement(4);

        MagicalContainer::PrimeIterator primeIter(container);
        CHECK_NOTHROW(primeIter.begin());
        CHECK_NOTHROW(primeIter.end());
    }
}

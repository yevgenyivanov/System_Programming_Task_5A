#pragma once
#include <set>
#include <vector>
class MagicalContainer
{
private:
    /* data */
    std::set<int, std::less<int>> _elements;

public:
    // ctors & dtor
    MagicalContainer(/* args */);
    MagicalContainer(MagicalContainer &);                       // copy constructor
    MagicalContainer &operator=(const MagicalContainer &);      // copy assignment operator
    MagicalContainer(MagicalContainer &&) = default;            // default move constructor
    MagicalContainer &operator=(MagicalContainer &&) = default; // default move assignment operator
    ~MagicalContainer();                                        // destructor
    // functions
    void addElement(int);
    int size() { return (int)this->_elements.size(); };
    void removeElement(int);
    void print(); // for troubleshooting
    class AscendingIterator
    {
    private:
        std::vector<int *> _ascendingElems;
        // MagicalContainer _container;

    public:
        AscendingIterator(MagicalContainer &);
        AscendingIterator operator++(int); // postfix (int is dummy flag)
        AscendingIterator &operator++();   // prefix
        // logical comparison
        bool operator==(const AscendingIterator &) const;
        bool operator!=(const AscendingIterator &) const;
        bool operator>(const AscendingIterator &) const;
        bool operator<(const AscendingIterator &) const;
        int operator*();
        AscendingIterator &begin();
        AscendingIterator &end();
    };
    //
    //
    //
    class SideCrossIterator
    {
    private:
        std::vector<int *> sidecrossElems;
        MagicalContainer &_container;

    public:
        SideCrossIterator(MagicalContainer &);
        SideCrossIterator operator++(int); // postfix (int is dummy flag)
        SideCrossIterator &operator++();   // prefix
        // logical comparison
        bool operator==(const SideCrossIterator &) const;
        bool operator!=(const SideCrossIterator &) const;
        bool operator>(const SideCrossIterator &) const;
        bool operator<(const SideCrossIterator &) const;
        int operator*();
        SideCrossIterator &begin();
        SideCrossIterator &end();
    };
    //
    //
    //
    class PrimeIterator
    {
    private:
        std::vector<int *> primeElems;
        MagicalContainer &_container;

    public:
        PrimeIterator(MagicalContainer &);
        PrimeIterator operator++(int); // postfix (int is dummy flag)
        PrimeIterator &operator++();   // prefix
        // logical comparison
        bool operator==(const PrimeIterator &) const;
        bool operator!=(const PrimeIterator &) const;
        bool operator>(const PrimeIterator &) const;
        bool operator<(const PrimeIterator &) const;
        int operator*();
        PrimeIterator &begin();
        PrimeIterator &end();
    };
};
//
//
//

// MagicalContainer::MagicalContainer(/* args */)
// {
// }

// MagicalContainer::~MagicalContainer()
// {
// }
namespace ariel
{
};
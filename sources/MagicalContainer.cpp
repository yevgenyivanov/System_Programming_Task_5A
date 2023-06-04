#include "MagicalContainer.hpp"
using namespace ariel;
constexpr int dummyZero= 0;
MagicalContainer::MagicalContainer()
{
}

MagicalContainer::MagicalContainer(MagicalContainer &other)
{
}

MagicalContainer &MagicalContainer::operator=(const MagicalContainer &)
{
    return *this;
    // TODO: insert return statement here
}

MagicalContainer::~MagicalContainer()
{
}

void MagicalContainer::addElement(int _recvVal)
{
}

void MagicalContainer::removeElement(int _recvVal)
{
}

void MagicalContainer::print()
{
}
//
//////////////// iterators
//
// ascending
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &other)
{
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++(int dummy) //postfix
{
    return *this;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    return false;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    return false;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
    return false;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{
    return false;
}

int MagicalContainer::AscendingIterator::operator*()
{
    return dummyZero;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::begin()
{
    return *this;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::end()
{
    return *this;
}
//
//
// sidecross
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &_container) : _container(_container){}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++(int dummy)
{
    return *this;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    return false;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    return false;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    return false;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    return false;
}

int MagicalContainer::SideCrossIterator::operator*()
{
    return dummyZero;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::begin()
{
    return *this;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::end()
{
    return *this;
}
//
//
// primes
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &_container) : _container(_container){}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator++(int dummy)
{
    return *this;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    return false;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return false;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    return false;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    return false;
}

int MagicalContainer::PrimeIterator::operator*()
{
    return dummyZero;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::begin()
{
    return *this;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::end()
{
    return *this;
}
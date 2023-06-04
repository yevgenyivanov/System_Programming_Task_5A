#include "doctest.h"
#include <iostream>
#include "sources/MagicalContainer.hpp"
using namespace ariel;
constexpr int _initialContainerSize = 0;
constexpr int _dummyOne = 1;
constexpr int _dummyTwo = 2;
constexpr int _dummyThree = 3;
constexpr int _dummyFour = 4;
constexpr int _dummyFive = 5;
constexpr int _dummySix = 6;
constexpr int _dummySeven = 7; // prime
constexpr int _dummyEight = 8;
constexpr int _dummyNine = 9;
constexpr int _dummyTen = 10;
constexpr int _dummyEleven = 11;   // prime
constexpr int _dummyThirteen = 13; // prime
constexpr int _dummyNineteen = 19; // prime

TEST_CASE("Container initiation and element addition/removal")
{
    MagicalContainer _magic1;
    CHECK(_magic1.size() == 0); // container is empty upon initialization
    // adding elements
    _magic1.addElement(_dummyThree);
    _magic1.addElement(_dummyOne);
    _magic1.addElement(_dummyFive);
    _magic1.addElement(_dummySix);
    CHECK_FALSE(_magic1.size() == _initialContainerSize); // elements were added
    CHECK(_magic1.size() == _dummyFour);
    CHECK_NOTHROW(_magic1.removeElement(_dummyThree)); // removing first element doesn't cause issues
    // remove arbitreraly
    _magic1.removeElement(_dummySix);
    _magic1.removeElement(_dummyFour);                // 4 was first element
    CHECK_NOTHROW(_magic1.removeElement(_dummyFour)); // removal of final element doesn't throw errors
    CHECK_THROWS(_magic1.removeElement(_dummyFive));  // removing non-existing element throws error
}
TEST_CASE("Ascending iterator on a given container")
{
    MagicalContainer _magic1;
    MagicalContainer::AscendingIterator _ascending1(_magic1);
    CHECK(_ascending1.begin() == _ascending1.end()); // container empty
    _magic1.addElement(_dummyThree);
    _magic1.addElement(_dummyFive);
    _magic1.addElement(_dummyOne);
    _magic1.addElement(_dummyFour);
    // order should be 1,3,4,5
    auto _indx = _ascending1.begin(); // set iterator to start
    CHECK(*_indx == _dummyOne);       // ascending order is enforced
    CHECK_NOTHROW(++_indx);           // incrementing the index works properly
    CHECK(*_indx == _dummyThree);     // same as prev. test
    ++_indx;
    ++_indx;
    CHECK_THROWS(++_indx); // iterating out of bounds throws exception
    _magic1.removeElement(_dummyOne);
    _indx.begin();
    CHECK(*_indx == _dummyThree); // after removal the iterator points to the new, changed value.
}
TEST_CASE("SideCross iterator on a given container")
{
    MagicalContainer _magic1;
    MagicalContainer::SideCrossIterator _sideCross(_magic1);
    CHECK(_sideCross.begin() == _sideCross.end()); // container empty
    _magic1.addElement(_dummyThree);
    _magic1.addElement(_dummyThirteen);
    _magic1.addElement(_dummyTen);
    _magic1.addElement(_dummyFive);
    _magic1.addElement(_dummyOne);
    _magic1.addElement(_dummyFour);
    // order should be: 1,3,4,5,10,13
    auto _indx = _sideCross.begin();    // set iterator to start
    CHECK(*_indx == _dummyOne);         // ascending order is enforced
    CHECK_NOTHROW(++_indx);             // incrementing the index works properly
    CHECK_FALSE(*_indx == _dummyThree); // next isnt three but is
    CHECK(*_indx == _dummyThirteen);    // next element is sidecrossed ->
    ++_indx;
    ++_indx;
    ++_indx;
    ++_indx;
    CHECK_THROWS(++_indx); // iterating out of bounds throws exception
    _magic1.removeElement(_dummyOne);
    _indx.begin();
    CHECK(*_indx == _dummyThree); // after removal the iterator points to the new, changed value.
}
TEST_CASE("Prime numbers iterator on a given container")
{
    MagicalContainer _magic1;
    MagicalContainer::PrimeIterator _primeItr(_magic1);
    CHECK(_primeItr.begin() == _primeItr.end()); // container empty
    _magic1.addElement(_dummyNineteen);          // ninteen should be in the end
    _magic1.addElement(_dummyOne);
    _magic1.addElement(_dummyEleven);
    _magic1.addElement(_dummyFour);
    _magic1.addElement(_dummySeven);
    _magic1.addElement(_dummyTwo);
    _magic1.addElement(_dummyThree);
    _magic1.addElement(_dummyTen);
    // order should be: 2,3,7,11,19
    auto _indx = _primeItr.end();
    CHECK(*_indx == _dummyNineteen); // ascending order is enforced, ninteen is in the last place
    _indx.begin();
    CHECK(*_indx == _dummyTwo); // two is first prime number
    ++_indx;
    ++_indx;
    ++_indx;
    ++_indx;
    CHECK(*_indx == _dummyNineteen);
    CHECK_THROWS(++_indx); // out of bounds exit
}
//
TEST_CASE("Logical Iterator comparisons on a given container")
{
    MagicalContainer _magic1;
    MagicalContainer::SideCrossIterator _sideCross(_magic1);
    MagicalContainer::PrimeIterator _primeItr(_magic1);
    MagicalContainer::AscendingIterator _ascending1(_magic1);
    _magic1.addElement(_dummyEight);
    _magic1.addElement(_dummyNineteen);
    _magic1.addElement(_dummyTen);
    _magic1.addElement(_dummyNine);
    _magic1.addElement(_dummyThree);
    _magic1.addElement(_dummyFour);
    _magic1.addElement(_dummySix);
    _magic1.addElement(_dummyOne);
    _magic1.addElement(_dummySeven);
    _magic1.addElement(_dummyTwo);
    _magic1.addElement(_dummyEleven);
    _magic1.addElement(_dummyFive);
    _magic1.addElement(_dummyThirteen);
    // order should be: 1-11,1,19
    auto _indxAscend1 = _ascending1.begin(), _indxAscend2 = _ascending1.end();
    auto _indxSide1 = _sideCross.begin(), _indxSide2 = _sideCross.end();
    auto _indxPrime1 = _primeItr.begin(), _indxPrime2 = _primeItr.begin();
    // check logical operators for ascending
    CHECK_FALSE(*_indxAscend1 > *_indxAscend2); // ascending order enforced
    CHECK(*_indxAscend1 < *_indxAscend2);       //
    CHECK(*_indxAscend1 != *_indxAscend2);      //
    _indxAscend2.begin();
    CHECK(*_indxAscend1 == *_indxAscend2);
    // check logical operators for sidecross
    CHECK(*_indxSide1 < *_indxSide2);  //
    CHECK(*_indxSide1 != *_indxSide2); // **
    ++_indxAscend1;
    CHECK(*_indxAscend1 == *_indxAscend2); //sidecrossing works on a given container
    //check logical operators for prime
    CHECK(*_indxPrime1 < *_indxPrime2); // **
    _indxPrime2.begin();
    CHECK(*_indxPrime1 == *_indxPrime2);
    ++_indxPrime1;
    CHECK(*_indxPrime1 > *_indxPrime2);
    //
}
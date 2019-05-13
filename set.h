/************************************
This class models an unbounded mathematical set.
*/

#ifndef _SET_H
#define _SET_H

#include <cstdlib>
#include <iostream>

class set
{
public:
    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type INITIAL_CAPACITY = 30;

    set();
// postcondition: empty set has been created

    set (const set& s);
    // postcondition: copy of s has been created

    ~set();
    // postcondition: set has been destroyed with all resources being deallocated

    set& operator = (const set& s);
    // postcondition: current object has been assigned s
    // returned: copy of s

    void insert (const value_type& entry);
    // postcondition: entry is in the set

    void remove (const value_type& entry);
// postcondition: entry is not in the set

    size_type size() const;
// returned: number of elements in the set

    bool contains (const value_type& entry) const;
// returned: whether entry is in the set

    friend set set_union (const set& s1, const set& s2);
    //returned: union of s1 & s2

    friend set set_intersection (const set& s1, const set& s2);
    // returned: intersection of s1 & s2

    friend set set_difference (const set& s1, const set& s2);
// returned: difference of s1 - s2

    friend bool is_subset (const set& s1, const set& s2);
// returned: whether s1 is a subset of s2

    friend bool operator == (const set& s1, const set& s2);
    // returned: whether s1 & s2 are equal

    friend std::ostream& operator << (std::ostream& output, const set& s);
// postcondition: s has been displayed on output

private:
    void resize (size_type new_capacity);
    // postcondition: capacity of set has been modified to new_capacity
    size_type find (const value_type& entry) const;
    // returned location of entry in the set if entry is in the set - used otherwise
    value_type* data;
    size_type used;
    size_type capacity;
};


#endif
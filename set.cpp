//
// Created by Alex on 2/14/2018.
//
//References:
//https://stackoverflow.com/questions/42335200/assignment-operator-overloading-returning-void-versus-returning-reference-param

#include "set.h"
#include <deque>
#include <iostream>
#include <cassert>

using namespace std;

set::set() {
    used = 0;
    capacity = INITIAL_CAPACITY;
    data = new value_type[capacity];

}

set::set (const set& s) {
    used = s.used;
    capacity = s.capacity;
    data = new value_type[capacity];
    copy(s.data, s.data + used, data);
}

set::~set() {
    delete [] data;
}

set& set::operator = (const set& s) {
    if (this == &s) {
        return *this;
    }

    if (capacity != s.capacity) {
        delete [ ] data;
        data = new value_type[s.capacity];
        capacity = s.capacity;
    }

    used = s.used;
    copy(s.data, s.data + used, data);
    return *this;
}

void set::insert (const value_type& entry) {
    if(!contains(entry)){
        if(size() == capacity) {
            resize(capacity + 1);
        }
        data[used] = entry;
        used++;
    }
}

void set::remove (const value_type& entry) {
    data[find(entry)] = data[used - 1];
    used--;
}

set::size_type set::size() const {
    return used;
}

bool set::contains (const value_type& entry) const {
    for(size_type i = 0; i < used; i++) {
        if(data[i] == entry) {
            return true;
        }
    }
    return false;
}

set set_union (const set& s1, const set& s2) {
    set s3;

    for(set::size_type i = 0; i < s1.size(); i++) {
        s3.insert(s1.data[i]);
    }
    for(set::size_type i = 0; i < s2.size(); i++) {
        s3.insert(s2.data[i]);
    }
    return s3;
}

set set_intersection (const set& s1, const set& s2) {
    set s3;
    set largest;
    set smaller;
    if(s1.size() > s2.size()) {
        largest = s1;
        smaller = s2;
    }
    else {
        largest = s2;
        smaller = s1;
    }

    for(set::size_type i = 0; i < smaller.size(); i++) {
        if(largest.contains(smaller.data[i])) {
            s3.insert(smaller.data[i]);
        }
    }
    return s3;
}

set set_difference (const set& s1, const set& s2) {
    set s3;

    for(set::size_type i = 0; i < s2.size(); i++) {
        if(!s1.contains(s2.data[i])) {
            s3.insert(s1.data[i]);
        }
    }
    return s3;
}

bool is_subset (const set& s1, const set& s2) {
    for(set::size_type i = 0; i < s1.size(); i++) {
        if(!s2.contains(s1.data[i])) {
            return false;
        }
    }
    return true;
}

bool operator == (const set& s1, const set& s2) {
    return is_subset(s1, s2) && is_subset(s2, s1);
}

std::ostream& operator << (std::ostream& output, const set& s) {
    for(set::size_type i = 0; i < s.size(); i++) {
        output << s.data[i] << " ";
    }
    return output;
}

void set::resize (size_type new_capacity) {
    value_type *larger_array;

    if (new_capacity == capacity) {
        return;
    }
    if (new_capacity < used) {
        new_capacity = used;
    }

    larger_array = new value_type[new_capacity];
    copy(data, data + used, larger_array);
    delete [ ] data;
    data = larger_array;
    capacity = new_capacity;
}

set::size_type set::find (const value_type& entry) const {
    for(size_type i = 0; i < used; i++) {
        if(data[i] == entry) {
            return i;
        }
        break;
    }
    return used;
}
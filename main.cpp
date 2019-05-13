#include "set.h"
#include <cassert>
#include <iostream>

int main ()
{
  set s;
  assert (!s.contains (7));
  s.insert (7);
  assert (s.contains (7));
  s.remove (7);
  assert (!s.contains (7));
  
  set s1;
  s1.insert (4);
  s1.insert (5);
  s1.insert (-24);
  s1.insert (89);
  s1.insert (34);
  s1.insert (11);
  s1.insert (0);
  s1.insert (3);
  s1.insert (14);
  s1.insert (28);
  std::cout << s1 << std::endl;

  set s2;
  s2.insert (6);
  s2.insert (-5);
  s2.insert (-24);
  s2.insert (-89);
  s2.insert (34);
  s2.insert (-11);
  s2.insert (0);
  s2.insert (3);
  std::cout << s2 << std::endl;

  set s3 = set_union (s1, s2);
  assert (s3.contains (4));
  assert (s3.contains (0));
  assert (s3.contains (-5));
  std::cout << s3 << std::endl;

  set s4 = set_intersection (s1, s2);
  assert (s4.contains (34));
  assert (!s4.contains (4));
  assert (!s4.contains (-5));
  std::cout << s4 << std::endl;

  set s5 = set_difference (s1, s2);
  assert (s5.contains (4));
  assert (!s5.contains (0));
  assert (!s5.contains (-5));
  std::cout << s5 << std::endl;

  assert (is_subset (s5, s1));
  std::cout << "all tests passed" << std::endl;
  return 0;
}

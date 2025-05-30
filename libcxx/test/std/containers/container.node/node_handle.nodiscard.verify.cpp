//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03
// UNSUPPORTED: (c++11 || c++14 || c++17) && !stdlib=libc++

// Make sure the various node handles mark their .empty() method with
// [[nodiscard]] starting with C++20

#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include "test_macros.h"

void test() {
#if TEST_STD_VER >= 17
  {
    std::map<int, int>::node_type node;
    node.empty(); // expected-warning {{ignoring return value of function declared with 'nodiscard' attribute}}
  }
  {
    std::multimap<int, int>::node_type node;
    node.empty(); // expected-warning {{ignoring return value of function declared with 'nodiscard' attribute}}
  }
#endif // TEST_STD_VER >= 17
  {
    std::set<int> node;
    node.empty(); // expected-warning {{ignoring return value of function declared with 'nodiscard' attribute}}
  }
  {
    std::multiset<int> node;
    node.empty(); // expected-warning {{ignoring return value of function declared with 'nodiscard' attribute}}
  }
  {
    std::unordered_map<int, int> node;
    node.empty(); // expected-warning {{ignoring return value of function declared with 'nodiscard' attribute}}
  }
  {
    std::unordered_multimap<int, int> node;
    node.empty(); // expected-warning {{ignoring return value of function declared with 'nodiscard' attribute}}
  }
  {
    std::unordered_set<int> node;
    node.empty(); // expected-warning {{ignoring return value of function declared with 'nodiscard' attribute}}
  }
  {
    std::unordered_multiset<int> node;
    node.empty(); // expected-warning {{ignoring return value of function declared with 'nodiscard' attribute}}
  }
}

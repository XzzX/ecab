// Copyright 2024 Sebastian Eibl
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <iomanip>
#include <iostream>

#include "datatypes.hpp"

namespace mrmd
{
namespace util
{
template <typename HEAD>
void printTable(HEAD head)
{
    std::cout << " │ " << std::setw(10) << std::setprecision(2) << std::fixed << head << " │ "
              << std::endl;
}
template <typename HEAD, typename... TAIL>
void printTable(HEAD head, TAIL... tail)
{
    std::cout << " │ " << std::setw(10) << std::setprecision(2) << std::fixed << head;
    printTable(tail...);
}

template <typename HEAD>
void printTableSep(HEAD /*head*/)
{
    std::cout << "─┼─" << std::setw(10) << std::setprecision(2) << std::fixed << "──────────"
              << "─┼─" << std::endl;
}
template <typename HEAD, typename... TAIL>
void printTableSep(HEAD /*head*/, TAIL... tail)
{
    std::cout << "─┼─" << std::setw(10) << std::setprecision(2) << std::fixed << "──────────";
    printTableSep(tail...);
}

}  // namespace util
}  // namespace mrmd

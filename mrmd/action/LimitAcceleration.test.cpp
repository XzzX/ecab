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

#include "LimitAcceleration.hpp"

#include <gtest/gtest.h>

#include "test/SingleAtom.hpp"

namespace mrmd
{
namespace action
{
using LimitAccelerationTest = test::SingleAtom;

TEST_F(LimitAccelerationTest, AccelerationPerComponent)
{
    limitAccelerationPerComponent(atoms, 0.5_r);

    auto hAoSoA = Cabana::create_mirror_view_and_copy(Kokkos::HostSpace(), atoms.getAoSoA());
    auto force = Cabana::slice<data::Atoms::FORCE>(hAoSoA);

    EXPECT_FLOAT_EQ(force(0, 0), 0.75_r);
    EXPECT_FLOAT_EQ(force(0, 1), 0.75_r);
    EXPECT_FLOAT_EQ(force(0, 2), 0.75_r);
}

}  // namespace action
}  // namespace mrmd
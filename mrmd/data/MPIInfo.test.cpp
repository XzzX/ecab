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

#include "MPIInfo.hpp"

#include <gtest/gtest.h>

#include "datatypes.hpp"

namespace mrmd::data
{
TEST(MPIInfo, Rank)
{
    MPIInfo mpiInfo(MPI_COMM_WORLD);
    int sumRanks = 0;
    MPI_Allreduce(&mpiInfo.rank, &sumRanks, 1, MPI_INT, MPI_SUM, mpiInfo.comm);
    EXPECT_EQ(sumRanks, 1);
}
TEST(MPIInfo, Size)
{
    MPIInfo mpiInfo(MPI_COMM_WORLD);
    EXPECT_EQ(mpiInfo.size, 2);
}

}  // namespace mrmd::data
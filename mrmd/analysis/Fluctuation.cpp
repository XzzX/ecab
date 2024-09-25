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

#include "Fluctuation.hpp"

#include "util/math.hpp"

namespace mrmd
{
namespace analysis
{
real_t getFluctuation(const data::MultiHistogram& hist,
                      const real_t& reference,
                      const idx_t& specimen)
{
    auto ret = 0_r;
    const real_t weighting = hist.binSize / (hist.max - hist.min);
    auto data = hist.data;

    auto policy = Kokkos::RangePolicy<>(0, hist.numBins);
    auto normalizeSampleKernel = KOKKOS_LAMBDA(const idx_t& idx, real_t& fluctuation)
    {
        fluctuation += weighting * util::sqr((data(idx, specimen) - reference) / reference);
    };
    Kokkos::parallel_reduce("getFluctuation", policy, normalizeSampleKernel, ret);
    Kokkos::fence();

    return ret;
}

}  // namespace analysis
}  // namespace mrmd
// Copyright 2020 Junekey Jeon
//
// The contents of this file may be used under the terms of
// the Apache License v2.0 with LLVM Exceptions.
//
//    (See accompanying file LICENSE-Apache or copy at
//     https://llvm.org/foundation/relicensing/LICENSE.txt)
//
// Alternatively, the contents of this file may be used under the terms of
// the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE-Boost or copy at
//     https://www.boost.org/LICENSE_1_0.txt)
//
// Unless required by applicable law or agreed to in writing, this software
// is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.

#include "jkj/fp/dooly.h"
#include "ryu/ryu.h"

#include <chrono>
#include <iostream>
#include <iomanip>
#include <string>
#include <string_view>
#include <stdexcept>
#include <memory>
#include <vector>

int main()
{
	using namespace jkj::fp::detail;

	while (true) {
		int exponent, initial_segment;
		std::cin >> exponent >> initial_segment;

		jkj::fp::dooly_generator<double> gen{ exponent, initial_segment };

		do {
			std::cout << std::setw(9) << std::setfill('0') << gen.current_segment() << " ";
		} while (gen.compute_next_segment());
		std::cout << std::endl;
	}
}
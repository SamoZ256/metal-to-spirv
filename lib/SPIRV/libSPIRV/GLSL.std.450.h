// clang-format off
/*
** Copyright (c) 2015 The Khronos Group Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and/or associated documentation files (the "Materials"),
** to deal in the Materials without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Materials, and to permit persons to whom the
** Materials are furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Materials.
**
** MODIFICATIONS TO THIS FILE MAY MEAN IT NO LONGER ACCURATELY REFLECTS KHRONOS
** STANDARDS. THE UNMODIFIED, NORMATIVE VERSIONS OF KHRONOS SPECIFICATIONS AND
** HEADER INFORMATION ARE LOCATED AT https://www.khronos.org/registry/
**
** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
** OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
** THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM,OUT OF OR IN CONNECTION WITH THE MATERIALS OR THE USE OR OTHER DEALINGS
** IN THE MATERIALS.
*/

//
// Author: Boaz Ouriel, Intel
//

namespace GLSLstd450 {

// TODO: add other functions as well
enum Entrypoints {
    // math functions
    Acos = 0,
    Acosh = 1,
    Asin = 3,
    Asinh = 4,
    Atan = 6,
    Atan2 = 7,
    Atanh = 8,
    Cbrt = 11,
    Ceil = 12,
    Cos = 14,
    Cosh = 15,
    Erfc = 17,
    Erf = 18,
    Exp = 19,
    Exp2 = 20,
    Exp10 = 21,
    Fabs = 23,
    Fdim = 24,
    Floor = 25,
    Fma = 26,
    Fmax = 27,
    Fmin = 28,
    Fmod = 29,
    Fract = 30,
    Frexp = 31,
    Log = 37,
    Log2 = 38,
    Log10 = 39,
    Modf = 45,
    Nan = 46,
    Pow = 48,
    Remainder = 51,
    Round = 55,
    Sin = 57,
    Sincos = 58,
    Sinh = 59,
    Sqrt = 61,
    Tan = 62,
    Tanh = 63,
    Trunc = 66,

    // Common
    FClamp = 95,
    Degrees = 96,
    Mix = 99,
    Radians = 100,
    Step = 101,
    Smoothstep = 102,
    Sign = 103,

    // Geometrics
    Cross = 104,
    Distance = 105,
    Length = 106,
    Normalize = 107,
    Fast_distance = 108,
    Fast_length = 109,
    Fast_normalize = 110,

    // Integers
    SAbs = 141,
    SHadd = 145,
    UHadd = 146,
    SClamp = 149,
    UClamp = 150,
    SMax = 156,
    UMax = 157,
    SMin = 158,
    UMin = 159,

    // more integers
    UAbs = 201,
};

} // end namespace GLSLstd450
// clang-format on

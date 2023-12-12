/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically and a negative shift value results in zero.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES, FOLLOW THE DIRECTIONS in README.md
 */


#endif
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
  return ~((~x)&(~y));
  // De Morgan's Law
  // x = 0110, y = 0101
  // ~x = 1001, ~y = 1010
  // (~x & ~y) = 1000
  // ~(~x & ~y) = 0111
  // x | y = 0111
}
/*
 * isZero - returns 1 if x == 0, and 0 otherwise 
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {
  return !x;
  // logical operator
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
    // goal: 0x7FFFFFFF OR 0111 1111 1111 1111 1111 1111 1111 1111
  return ~(1 << 31); // 1 << 31 = 1000 0000 0000 0000 0000 0000 0000 0000, then ~(1 << 31) = 0x7FFFFFFF
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
    int mask = (0xaa << 24 | 0xaa << 16 | 0xaa << 8 | 0xaa); // 0101 0101 0101 0101 0101 0101 0101 0101
    return !!(x & mask); // double logical negation to get either 1 or 0 depending on if it is odd or even number of bits
    // Ex. x = 0x5 = 0000 0000 0000 0000 0000 0000 0000 0101
    // (x & mask) = 0000 0000 0000 0000 0000 0000 0000 0101
    // !(x & mask) = 0001
    // !!(x & mask) = 0000
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) { ////////////////////////////////
   int tmp = 32 + (~n+1); 
   int y = (x << tmp);
   y = y >> tmp;
   return !(x^y);
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
    int new_x = ~x + 1;
  return (x & new_x);
  // do ~x first then +1 because that will get whatever bit is in the least position with the & operator
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int positive = 0x1 << 31; // gives negative byte EX. 1000 0000 0000 0000 0000 0000 0000 0000 0000
  int upper = ~ (positive | 0x39); // gives upper bound 0111 1111 1111 1111 1111 1111 1111 1100 0110
  int lower = ~0x30; // lower bound 1111 1111 1111 1111 1111 1111 1100 1111
  
  upper =  (upper+x) >> 31; // if x is greater than 0x39 then this would cause this to be 0x1 
  lower = (lower+ (x+1)) >> 31; // if x is less than 0x30 then this would cause this to be 0x1 from overflow after adding 1 
  return !(upper | lower);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {///////////////////////////////
    // check postive/negative
    int isYnegative = (y >> 31) & 1; // if Y is negative variable = 0x1, else 0x0
    int isXnegative = (x >> 31) & 1; // if X is negative variable = 0x1, else 0x0
    int comparison = ((x + ~y) >> 31) & (!(isXnegative ^ isYnegative)); // y - x = ~y + x
    
    
  return ((((!isYnegative) & isXnegative)) | (comparison)); 
  
}
/* 
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {
   int firstbyte = (x >>24) & 0xff;
  
   int secondbyte = (x >> 16) & 0xff;
   
   int thirdbyte = (x >> 8) & 0xff;
   int fourthbyte = x & 0xff;
   int reversebyte = 0x00;
   reversebyte = (reversebyte | (fourthbyte << 24));
   reversebyte = (reversebyte | (thirdbyte << 16));
   reversebyte = (reversebyte | (secondbyte << 8));
   reversebyte = (reversebyte | firstbyte);
  return reversebyte;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) { ////////////////////////////////////////////
int mask = 0x11;
int total = 0x00;
int sum1 = 0x00;
int sum2 = 0x00;
int final1 = 0x0;
int final2 = 0x0;
int final3 = 0x0;
int final4 = 0x0;
int last = 0x00;
mask = (mask | (0x11 << 24) | (0x11 << 16) | (0x11 << 8));
total += (x & mask);
total += (x>>1 & mask);
total += (x>>2 & mask);
total += (x>>3 & mask);

total = total + (total>>16);
total = total & (0xff | 0xff << 8);
final1 = total>>12;
final2 = total >> 8 & 0xf;
final3 = total >> 4 & 0xf;
final4 = total & 0xf;
sum1 = final1 + final2;
sum2 = final3 + final4;

last = sum1 + sum2;

  return last;
}
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
    x = ((~x) & ~(~x+1)); // not x and not 2's complement of x
    x = x >> 31; // shift it over to either get 0x0 or 0x1
  return (x & 0x1); // if x = 0x1 then return 0x1 else 0x0
    //x = 3 OR 0011
    // 1100 & 0010 = 0000
    // 0x0
    
    // x = 0 OR 0000
    // 1111 & 1000 = 1000
    // 0x1
    
}
/*
 * trueFiveEighths - multiplies by 5/8 rounding toward 0,
 *  avoiding errors due to overflow
 *  Examples: trueFiveEighths(11) = 6
 *            trueFiveEighths(-9) = -5
 *            trueFiveEighths(0x30000000) = 0x1E000000 (no overflow)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 4
 */
int trueFiveEighths(int x) ///////////////////////////////////
{
     int new_x = (x >> 3); // divide by 8
    int x_FiveEigths = (new_x << 2) + new_x; // multiply by 4 with left shift, then add x to multiply by 5
    int sign = x >> 31; // chech if negative for special case
    int remain = x & 7; // 0111, focus on the first 3 bits after decimal place
    int remain_x5 = (remain << 2) + remain; // multiply the remainder by 5
    int negCase = remain_x5 + (sign & 7); // special negative case with the remainder
    int remain_FiveEighths = negCase >> 3; // divide by 8 
    
    
    return x_FiveEigths + remain_FiveEighths; // return 5/8 with rounding towards 0 or remainder added
}
/*
 * Extra credit
 */
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) { //////////////////////////////////
 return 2;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) { /////////////////////////////////
  return 2;
}

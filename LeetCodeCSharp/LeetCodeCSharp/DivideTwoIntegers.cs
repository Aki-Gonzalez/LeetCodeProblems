
namespace LeetCodeCSharp
{
    internal class DivideTwoIntegers
    {
        static public int Divide(int dividend, int divisor)
        {
            Int64 absDividend = System.Math.Abs((Int64)dividend);
            Int64 absDivisor = System.Math.Abs((Int64)divisor);

            // Used slow division.
            Int64 remainder = absDividend;
            Int64 count = 0;
            while (remainder >= absDivisor)
            {
                remainder -= absDivisor;
                count++;
            }
            Int64 quotient = count;

            // Might not be allowed to use multiplication/division to figure out sign either.
            //int sign = (dividend / absDividend) * (divisor / absDivisor);
            int sign = (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0) ? -1 : 1;

            // Probably not allowed multiplication to assign sign either?
            //quotient *= sign;
            if (sign < 0)
                quotient = quotient - quotient - quotient;

            if (quotient >= Int32.MaxValue)
                return Int32.MaxValue;

            if (quotient <= Int32.MinValue)
                return Int32.MinValue;

            return (Int32)quotient;
        }

    }
}
/*
    https://leetcode.com/problems/divide-two-integers/
    Constraints:

    -2^31 <= dividend, divisor <= 2^(31) - 1
    divisor != 0

    x/y = z
    Division is: how many times can y fit into x?
    remember the signs, take the absolute values:
    sum += y until sum >= x, count the times y is added to sum. 
    Should give the quotient.
    
    What if abs(y) > abs(x)?
    sum += x uuntil sum >= y
    and then? test the above scenario first.

    ?: is it possible to compare bits.
    Yes but I'll tackle that some other day.

 */

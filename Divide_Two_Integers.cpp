c++ solution for leetcode
29. Divide Two Integers
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
Return the quotient after dividing dividend by divisor.
The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.
Example 1:
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.
Example 2:
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.
My code:
class Solution {
public:
    int divide(int a, int b) {
      long long dividend = (long long)a; 
    long long divisor = (long long)b; 
  
    long long sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
    dividend = abs(dividend); 
    divisor = abs(divisor); 
 long long int res=0;
    
  
    if (dividend == 0) { 
       res=0; 
    } 
  
    if (divisor == 1) { 
             res=sign * dividend ; 
        
    } 
  
    // Using Formula derived above. 

        res= sign * exp(log(dividend) - log(divisor)) ;
        if(res>pow(2,31)-1||res<-pow(2,31))
            return pow(2,31)-1;
  return res;
    }
};

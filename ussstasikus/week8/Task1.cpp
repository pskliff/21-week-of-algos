//
// Created by Stas Don on 29/04/2018.
//

bool isPowerOfThree(int n)
{
    long max_power_of_three = pow(3, (int)(log(INT_MAX)/log(3)));
    cout << max_power_of_three;
    return n > 0 && max_power_of_three % n == 0;
}
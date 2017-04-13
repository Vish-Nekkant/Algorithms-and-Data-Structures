
#include <iostream>

namespace Alg
{
    /// Program that prints the prime numbers less than maxNumber.
    ///
    /// @param maxNumber The upperlimit of the prime number
    /// 
    void Eratosthenes(int maxNumber)
    {
        int *numbers = new int[maxNumber];

        if (numbers == 0)
        {
            std::cout << "Space allocation failed " << std::endl;
        }

        // fill up all the numbers to ones
        int *ptr = numbers;
        for (int i = 0; i < maxNumber; i++)
        {
            *(ptr++) = 1;
        }

        for (int i = 2; i < maxNumber; i++)
        {
            if (numbers[i])
            {
                for (int j = 2; i * j < maxNumber; j++)
                {
                    numbers[i*j] = 0;
                }
            }
        }

        // print the prime numbers
        for (int i = 2; i < maxNumber; i++)
        {
            if (numbers[i])
            {
                std::cout << i << std::endl;
            }
        }

        delete[] numbers;
    }
}

#if 1
int main()
{
    Alg::Eratosthenes(100);
}
#endif
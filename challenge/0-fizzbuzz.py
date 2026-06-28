#!/usr/bin/env python3
"""
FizzBuzz implementation
"""
import sys


def fizzbuzz(n):
    """
    FizzBuzz function prints numbers from 1 to n separated by a space.
    """
    if n < 1:
        return

    l_output = []
    for i in range(1, n + 1):
        if i % 3 == 0 and i % 5 == 0:
            l_output.append("FizzBuzz")
        elif i % 3 == 0:
            l_output.append("Fizz")
        elif i % 5 == 0:
            l_output.append("Buzz")
        else:
            l_output.append(str(i))
    print(" ".join(l_output))

if __name__ == '__main__':
    if len(sys.argv) <= 1:
        print("Missing argument")
        sys.exit(1)

    try:
        number = int(sys.argv[1])
        fizzbuzz(number)
    except ValueError:
        print("Argument must be an integer")
        sys.exit(1)

#!/usr/bin/env python3
# This is a pi calculation script
import time
import argparse

def calculate(iterations, p1, p2):
  result = 1.0
  for i in range(1, iterations + 1):
    j = i *  p1 - p2
    result -= (1/j)
    j = i * p1 + p2
    result += (1/j)
  return result

def main():
  parser = argparse.ArgumentParser(description="Calculate a mathematical series.")
  parser.add_argument('--iterations', type=int, default=100000000, help='Number of iterations to perform')
  args = parser.parse_args()

  # Use the provided iterations value
  iterations = args.iterations
  start_time = time.time()
  result = calculate(iterations, 4, 1) * 4
  end_time = time.time()
  print(f"Result: {result:.12f}")
  print(f"Execution time: {end_time - start_time:.6f} seconds")

if __name__ == "__main__":
  main()

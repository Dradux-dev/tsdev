/*
 * This example demonstrates the usage of the CHECK macro.
 *
 * Whenever the CHECK macro is expanded, it checks a the
 * conditional parameter. If this parameter is false, it
 * will trigger a breakpoint. Otherwise it won't do anything.
 * In a non DEBUG version, the macro is expanded to an empty
 * line.
 *
 * Steps:
 *   1. Define DEBUG, if not already defined
 *   2. Include "check.h"
 *   3. Use CHECK macro, wherever needed
 *
 * Author: Tarek Schwarzinger <tarek.schwarzinger@googlemail.com>
 */




#include <iostream>
#include <cmath>

/*
 * Define DEBUG, so that the CHECK macro will work
 */
#ifndef DEBUG
# define DEBUG 1
#endif


/*
 * Include the needed header file
 */
#include <tsdev/check.h>

/**
 * @brief 3-dimensional Vector
 *
 * Simple 3-dimensional vector, that can
 * store it's components.
 */
struct FVector
{
    float X;
    float Y;
    float Z;
};

/**
 * @brief Vector normalization
 *
 * Normalizes the vector parameter, if it's
 * actual length exceeds the Delta parameter.
 * Performs a CHECK, to see if the Vector
 * parameter is a valid one.
 *
 * @param Vector Pointer to the vector.
 * @param Delta Minimum length, that the vector has to have to be normalized.
 */
void NormalizeVector(FVector* Vector, float Delta = 0.000001f)
{
  /*
   * Performs the check and triggers a breakpoint, if it fails. In
   * a non DEBUG version, the CHECK macro won't be in the final
   * executable, thanks to compiler optimization.
   */
  CHECK(Vector);

  float Length = std::sqrt(Vector->X * Vector->X + Vector->Y + Vector->Y + Vector->Z + Vector->Z);
  if (Length >= Delta)
  {
    Vector->X /= Length;
    Vector->Y /= Length;
    Vector->Z /= Length;
  }
}

/**
 * @brief Vector output operator
 *
 * Streams the vector to the output stream.
 *
 * @param os The output stream.
 * @param Vector The vector, that shall be streamed.
 *
 * @return Returns the modified output stream.
 */
std::ostream& operator << (std::ostream& os, const FVector& Vector)
{
  return os << "{" << Vector.X << ", " << Vector.Y << ", " << Vector.Z << "}";
}

int main(int, char**)
{
  std::cout << "Check demo for TsDev library" << std::endl;

  FVector A = {7, 12, 84};
  std::cout << "A=" << A << std::endl;

  NormalizeVector(&A);
  std::cout << "A_norm=" << A << std::endl;

  FVector B = {3, 5, 7};
  std::cout << "B=" << B << std::endl;

  NormalizeVector(nullptr);
  std::cout << "B_norm=" << B << std::endl;

  return 0;
}

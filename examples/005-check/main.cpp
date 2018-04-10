#include <iostream>
#include <cmath>

#ifndef DEBUG
# define DEBUG 1
#endif

#include <tsdev/check.h>

struct FVector
{
    float X;
    float Y;
    float Z;
};

void NormalizeVector(FVector* Vector, float Delta = 0.000001f)
{
  CHECK(Vector);

  float Length = std::sqrt(Vector->X * Vector->X + Vector->Y + Vector->Y + Vector->Z + Vector->Z);
  if (Length > Delta)
  {
    Vector->X /= Length;
    Vector->Y /= Length;
    Vector->Z /= Length;
  }
}

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

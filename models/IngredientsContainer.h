#include <bits/stdc++.h>
using namespace std;

class IngredientContainer
{
  int maxLimit;
  int current;

public:
  IngredientContainer()
  {
    maxLimit = 10;
    current = 10;
  }
  IngredientContainer(int limit, int curr)
  {
    maxLimit = limit;
    current = curr;
  }
  int getCurrentAmount()
  {
    return current;
  }

  bool hasAmount(int amount)
  {
    if (amount <= current)
      return true;
    return false;
  }

  bool fill(int amount)
  {
    if (amount + current > maxLimit)
    {
      cout << "Max limit is " << maxLimit;
      return false;
    }
    current += amount;
    return true;
  }

  bool use(int amount)
  {
    if (!hasAmount(amount))
      return false;
    current -= amount;
    return true;
  }
};

class WaterContainer : public IngredientContainer
{
};
class MilkContainer : public IngredientContainer
{
};
class CoffeeBeansContainer : public IngredientContainer
{
};

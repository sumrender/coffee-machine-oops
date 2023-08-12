#include "./IngredientsContainer.h"

class CoffeeMachine
{
  WaterContainer water;
  MilkContainer milk;
  CoffeeBeansContainer coffeeBeans;
  vector<string> options = {
      "Serve Cappucino",
      "Serve Latte",
      "Serve Espresso",
      "Serve Milk",
      "Serve Water",
      "Fill Coffee beans",
      "Fill Milk",
      "Fill Water",
      "Display current ingredient quantity",
      "Turn off"};

  bool canMake(int waterAmount, int coffeeBeansAmount, int milkAmount)
  {
    if (!water.hasAmount(waterAmount))
    {
      cout << "Lack of Water";
      return false;
    }
    if (!coffeeBeans.hasAmount(coffeeBeansAmount))
    {
      cout << "Lack of CoffeeBeans";
      return false;
    }
    if (!milk.hasAmount(milkAmount))
    {
      cout << "Lack of Milk";
      return false;
    }
    return true;
  }
  void makeCoffee(int waterAmount, int coffeeBeansAmount, int milkAmount)
  {
    water.use(waterAmount);
    coffeeBeans.use(coffeeBeansAmount);
    milk.use(milkAmount);
  }
  bool getCappucino()
  {
    if (!canMake(1, 2, 2))
      return false;
    makeCoffee(1, 2, 2);
    cout << "Here is your Cappucino" << endl;
    return true;
  }
  bool getLatte()
  {
    if (!canMake(1, 2, 3))
    {
      return false;
    }
    makeCoffee(1, 2, 3);
    cout << "Here is your Latte" << endl;
    return true;
  }
  bool getEspresso()
  {
    if (!canMake(1, 3, 0))
    {
      return false;
    }
    makeCoffee(1, 3, 0);
    cout << "Here is your Espresso" << endl;
    return true;
  }
  bool getMilk()
  {
    if (!milk.hasAmount(3))
    {
      cout << "Lack of milk" << endl;
      return false;
    }
    milk.use(3);
    cout << "Here is your milk" << endl;
    return true;
  }
  bool getWater()
  {
    if (!water.hasAmount(3))
    {
      cout << "Lack of water" << endl;
      return false;
    }
    water.use(3);
    cout << "Here is your water" << endl;
    return true;
  }
  void fillWater()
  {
    int amount = getAmount();
    water.fill(amount);
  }
  void fillCoffeeBeans()
  {
    int amount = getAmount();
    coffeeBeans.fill(amount);
  }
  void fillMilk()
  {
    int amount = getAmount();
    milk.fill(amount);
  }
  void displayCurrentIngredients()
  {
    cout << "The current quantity is" << endl;
    cout << "Milk: " << milk.getCurrentAmount() << endl;
    cout << "Water: " << water.getCurrentAmount() << endl;
    cout << "CoffeeBeans: " << coffeeBeans.getCurrentAmount() << endl;
  }

  int getAmount()
  {
    cout << "Enter the quantity" << endl;
    int amount;
    cin >> amount;
    return amount;
  }
  void shutDown()
  {
    cout << "Shutting down..." << endl;
    exit(EXIT_SUCCESS);
  }
  void doTask(int choice)
  {
    switch (choice)
    {
    case 1:
      getCappucino();
      break;
    case 2:
      getLatte();
      break;
    case 3:
      getEspresso();
      break;
    case 4:
      getMilk();
      break;
    case 5:
      getWater();
      break;
    case 6:
      fillCoffeeBeans();
      break;
    case 7:
      fillMilk();
      break;
    case 8:
      fillWater();
      break;
    case 9:
      displayCurrentIngredients();
      break;
    case 10:
      shutDown();
      break;
    }
  }

public:
  CoffeeMachine()
  {
    cout << "Initialising Coffee Machine..." << endl;
    cout << "Fetching water: " << water.getCurrentAmount() << endl;
    cout << "Fetching milk: " << milk.getCurrentAmount() << endl;
    cout << "Fetching coffeeBeans: " << coffeeBeans.getCurrentAmount() << endl;
  }
  void start()
  {
    while (true)
    {
      cout << endl
           << endl
           << endl
           << "===========================================" << endl;
      cout << "Please select a choice from the following operations:" << endl;
      for (int i = 0; i < options.size(); i++)
      {
        cout << i + 1 << ". " << options[i] << endl;
      }
      cout << "===========================================" << endl
           << endl
           << endl;
      int choice;
      cin >> choice;
      doTask(choice);
    }
  }
};

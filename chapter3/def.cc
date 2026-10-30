#include <cmath>
#include <iostream>
#include <string>

namespace zad1 {
double HowManyFeet(double centimeters) {
  const float FEET_TO_CM = 30.48;
  double feet = centimeters / FEET_TO_CM;
  return feet;
}
}  // namespace zad1

namespace zad2 {
float BMICalculator() {
  const int cale_w_stopie = 12;
  const float mnoznik_cale_na_metry = 0.0254;
  const float dzielenie_funty_na_kg = 2.2;

  float height;
  float weight;
  std::cout << "put in your height in ft" << std::endl;
  std::cin >> height;
  std::cout << "put in your weight in lbs" << std::endl;
  std::cin >> weight;

  height = (height * cale_w_stopie) * mnoznik_cale_na_metry;
  weight = weight / dzielenie_funty_na_kg;

  double BMI = weight / (height * height);

  return BMI;
}
}  // namespace zad2

namespace zad3 {
float geography() {
  int stopnie;
  int minuty;
  int sekundy;
  const float minuty_w_stopien = 60.0;
  const float sekundy_w_minuta = 60.0;

  std::cout << "Najpierw podaj stopnie:" << std::endl;
  std::cin >> stopnie;
  std::cout << "Następnie podaj minuty stopnia łuku:" << std::endl;
  std::cin >> minuty;
  std::cout << "Na koniec podaj sekundy łuku:" << std::endl;
  std::cin >> sekundy;

  float stopnie_dziesietnie = stopnie + (minuty / minuty_w_stopien) +
                              (sekundy / (minuty_w_stopien * sekundy_w_minuta));
  return stopnie_dziesietnie;
}
}  // namespace zad3

namespace zad4 {
void seconds() {
  std::cout << "insert the amount of seconds: " << std::endl;
  long long seconds_input;
  std::cin >> seconds_input;
  const int hours_in_a_day = 24;
  const int minutes_in_an_hour = 60;
  const int seconds_in_a_minute = 60;

  const int seconds_in_an_hour = minutes_in_an_hour * seconds_in_a_minute;

  const int seconds_in_a_day = seconds_in_an_hour * hours_in_a_day;

  int days = seconds_input / seconds_in_a_day;
  int hours = (seconds_input % seconds_in_a_day) / seconds_in_an_hour;
  int minutes = (seconds_input % seconds_in_an_hour) / seconds_in_a_minute;
  int seconds = seconds_input % seconds_in_a_minute;

  std::cout << seconds_input << " seconds = " << days << " days " << hours
            << "hours " << minutes << " minutes " << seconds << "seconds "
            << std::endl;
}
}  // namespace zad4
   // namespace zad4
namespace zad4_1 {
void modul() {
  long long price;

  std::cout << "insert the full price here: " << std ::endl;
  std::cin >> price;

  long long remainer = price;

  int hundreds = price / 100;
  remainer = remainer % 100;

  int fifties = remainer / 50;
  remainer %= 50;

  int twenties = remainer / 20;
  remainer %= 20;

  int tens = remainer / 10;

  remainer %= 10;
  int ones = remainer;

  std::cout << price << "price in billons equals: " << hundreds << " 100zl "
            << fifties << " 50zl " << twenties << " 20zl " << tens << " 10zl "
            << ones << " 1zl " << std ::endl;
}
}  // namespace zad4_1

namespace zad4_2 {
void modulo2() {
  int day_of_week;
  int days_elapsed;
  const int days_in_a_week = 7;
  std::cout << "what day of the week you're choosing? (monday - 0, tuesday - "
               "1, ... , "
               "sunday - 6)"
            << std::endl;

  std::cin >> day_of_week;

  std::cout << "inser the amount of days elapsed " << std::endl;
  std::cin >> days_elapsed;

  const std::string daysOfWeek[days_in_a_week] = {
      "Monday", "tuesday",  "Wednesday", "Thursday",
      "Friday", "Saturday", "Sunday"};

  int future_day = (day_of_week + days_elapsed) % days_in_a_week;
  std::cout << "The day " << days_elapsed << " days away from "
            << daysOfWeek[day_of_week] << " is " << daysOfWeek[future_day]
            << std::endl;
}
}  // namespace zad4_2

namespace zad4_3 {
void modulo3() {
  const int gross = 144;
  const int mugs = 12;
  const int boxes_in_a_palette = gross / mugs;
  int amount;

  std::cout << "how many mugs are being shipped?" << std::endl;
  std::cin >> amount;

  int palletes = amount / gross;
  int boxes = (amount % gross) / mugs;
  int loose = amount % mugs;

  std::cout << "shipping out: " << palletes << " palletes " << boxes
            << " boxes " << loose << " loose mugs." << std::endl;
}
}  // namespace zad4_3

namespace zad4_4 {
void modulo4() {
  int number;
  std::cout << "Insert a 3 digit number: " << std::endl;
  std::cin >> number;

  int hundreds = number / 100;
  int remainer = number % 100;

  int tens = remainer / 10;
  remainer %= 10;

  int units = remainer;

  int sum = hundreds + tens + units;

  std::cout << "The sum of digits equals = " << sum << std::endl;
}
}  // namespace zad4_4

namespace zad5 {
void population() {
  long long world_population;
  long long polish_population;
  std::cout << "Insert the number of world's population: " << std::endl;
  std::cin >> world_population;
  std::cout << "Insert the number of Poland's population: " << std::endl;
  std::cin >> polish_population;
  double procentage = (polish_population * 100.0) / world_population;
  std::cout << "Polish population accounts for " << procentage
            << "% of world's population" << std::endl;
}
}  // namespace zad5

namespace zad6 {
void gas_left() {
  double how_many_km;
  double gas_used;
  std::cout << "How many km have you driven already? " << std::endl;
  std::cin >> how_many_km;
  std::cout << "How much gas have you used up? " << std::endl;
  std::cin >> gas_used;
  if (how_many_km > 0.0) {
    double usage = (gas_used / how_many_km) * 100.0;
    std::cout << "gas usage is " << usage << " l/km " << std::endl;
  } else {
    std::cout << "the distance input must be more than 0.0" << std::endl;
  }
}
}  // namespace zad6

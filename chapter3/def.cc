#include <cmath>
#include <iostream>

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
void seconds_to_days() {
  long long seconds_input;
  const int seconds_in_minute = 60;
  const int minutes_in_hour = 60;
  const int hours_in_day = 24;

  std::cout << "Najpierw podaj sekundy: ";
  std::cin >> seconds_input;

  const int seconds_in_hour = seconds_in_minute * minutes_in_hour;
  const int seconds_in_day = seconds_in_hour * hours_in_day;

  int days = seconds_input / seconds_in_day;
  int hours = (seconds_input % seconds_in_day) / seconds_in_hour;
  int minutes = (seconds_input % seconds_in_hour) / seconds_in_minute;
  int seconds = seconds_input % seconds_in_minute;

  std::cout << seconds_input << " sekund = " << days << " dni " << hours
            << " godzin " << minutes << " minut " << seconds << " sekund"
            << std::endl;
}
}  // namespace zad4

/*

}*/

namespace zad4_1 {
void modul() {
  const int nom_100 = 100;
  const int nom_50 = 50;
  const int nom_20 = 20;
  const int nom_19 = 10;
  const int nom_1 = 1;
  int kwota;
  std::cout << "podaj kwote do wydania nominalow:" << std::endl;
  std::cin >> kwota;

  int hundred = kwota / nom_100;
}
}  // namespace zad4_1

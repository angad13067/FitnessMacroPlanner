#include <iostream>
#include <chrono>
#include <thread>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int displayMenu()
{
    int menuChoice;
    cout << "[Menu Options]" << endl;
    cout << endl;
    cout << "[1] Calculate BMR and Maintenance calories" << endl;
    cout << "[2] Calculate Pre/Post-workout meal macros" << endl;
    cout << "[3] Help" << endl;
    cout << endl;

    cout << "Enter your choice(Number): " << endl;
    cin >> menuChoice;
    cout << endl;

    return menuChoice;
}

void help()
{
    cout << "This is a simple program to calculate your Basal metabolic rate (BMR) and your maintenance calories.\n";
    cout << "This is useful information when setting fitness and weight gain/loss goals.\n";
    cout << "Additionally, based on your bodyweight, this program calculates the ideal macronutrient targets for your pre and post-workout meals.\n";
    cout << "These guidelines allow you to optimize the two most important meals from a training standpoint\n";
}

double calculateBmr(double weight, double height, double age)
{
    double convertedWeight = weight / 2.205; //converting lbs to kg for calculation.
    return (10 * convertedWeight) + (6.25 * height) - (5 * age) + 5;
}

double calculateMaintenanceCalories(double bmr, double activityMultiplier)
{
    return bmr * activityMultiplier;
}

double calculateProtein(double weight)
{
    double convertedWeight = weight / 2.205;
    return 0.5 * convertedWeight;
}
double calculateCarbsLow(double weight)
{
    return weight;
}
double calculateCarbsHigh(double weight)
{
    return 1.5 * weight;
}

const void printPreworkoutMeal(double protein, double carbsLow)
{
    cout << endl;
    cout << "------------------------------------------------\n";
    cout << "Your Pre-Workout Meal Target Macros Are: " << endl;
    cout << endl;
    cout << "-Protein: " << protein << " grams" << endl;
    cout << "-Carbohydrates: " << carbsLow << " grams" << endl;
    cout << "-Fats: " << "1-20g depending on caloric intake " << endl;
}
const void printPostWorkoutMeal(double protein, double carbsLow, double carbsHigh)
{
    cout << endl;
    cout << "Your Post-Workout Meal Target Macros Are: " << endl;
    cout << endl;
    cout << "-Protein: " << protein << " grams" << endl;
    cout << "-Carbohydrates Range: " << carbsLow << " to " << carbsHigh << " grams" << endl;
    cout << "-Fats: " << "1-20g depending on caloric intake " << endl;
    cout << "------------------------------------------------\n";
}

void drawTable()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "To calculate your Maintenance Calories, you must first choose an activity level." << endl;
    cout << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "Use the table below to estimate your activity level based on your situation." << endl;
    cout << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "--------------------------------------------------------------------------------\n";
    cout << "|LIFESTYLE AND TRAINING FREQUENCY|     |EXAMPLE|     |ACTIVITY MULTIPLIER RANGE|" << endl;
    cout << "--------------------------------------------------------------------------------\n";
    cout << endl;
    cout << "SEDENTARY + TRAINING 3-6x/wk: Works a desk job, very little activity outside of lifting -> [1.2 - 1.5]" << endl;
    cout << endl;
    cout << "--------------------------------------------------------------------------------\n";
    cout << endl;
    cout << "LIGHTLY ACTIVE + TRAINING 3-6x/wk: Works a desk job, takes pet for a walk most days in addition to lifting -> [1.5 - 1.8]" << endl;
    cout << endl;
    cout << "--------------------------------------------------------------------------------\n";
    cout << endl;
    cout << "MODERATELY ACTIVE + TRAINING 3-6x/wk: Works as a full-time waiter, occasionally plays tennis in addition to lifting -> [1.8 - 2.0]" << endl;
    cout << endl;
    cout << "--------------------------------------------------------------------------------\n";
    cout << endl;
    cout << "HIGHLY ACTIVE + TRAINING 3-6x/wk: Works as a construction worker, regular hiking in addition to lifting -> [1.2 - 1.5]" << endl;
    cout << endl;
    cout << "--------------------------------------------------------------------------------\n";
    cout << endl;
}

int main()
{
    double weight, height, bmr, activityMultiplier, maintenanceCalories, protein, carbsLow, carbsHigh, weightInput;
    int age;


    cout << "Enter your weight(lbs):" << endl;
    cin >> weight;
    cout << endl;
    cout << "Enter your height(cm):" << endl;
    cin >> height;
    cout << endl;
    cout << "Enter your age:" << endl;
    cin >> age;
    cout << endl;

    int menuChoice = displayMenu();

    switch (menuChoice)
    {
    case 1: bmr = calculateBmr(weight, height, age);
        cout << "Your BMR is: " << bmr << " Calories" << endl;
        cout << endl;
        drawTable();
        cout << "Enter your activity multiplier:" << endl;
        cin >> activityMultiplier;
        cout << endl;
        maintenanceCalories = calculateMaintenanceCalories(bmr, activityMultiplier);
        cout << "Your daily maintenance caloric intake is: " << maintenanceCalories << " Calories" << endl;
        cout << endl;
        break;

    case 2:
        //cout << "Enter your weight (lbs): " << endl;
        //cin >> weightInput;
        protein = calculateProtein(weight);
        carbsLow = calculateCarbsLow(weight);
        carbsHigh = calculateCarbsHigh(weight);
        printPreworkoutMeal(protein, carbsLow);
        printPostWorkoutMeal(protein, carbsLow, carbsHigh);
        break;
    case 3:
        help();
        break;
    }
}


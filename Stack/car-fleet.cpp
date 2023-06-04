#include <bits/stdc++.h>
using namespace std;

// Define a struct to represent a car with position and speed
struct Car
{
    int pos;
    int speed;
};

// Function to calculate the number of car fleets
int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    vector<Car> cars;        // Create a vector to store the cars
    int N = position.size(); // Get the number of cars

    // Iterate through each car position and speed
    for (int i = 0; i < N; i++)
    {
        cars.push_back({position[i], speed[i]}); // Add the car to the vector
    }

    // Sort the cars based on their positions using a lambda function
    sort(cars.begin(), cars.end(), [](const Car &a, const Car &b)
         { return a.pos < b.pos; });

    stack<float> mono; // Create a stack to store the arrival times of the cars

    // Iterate through each car
    for (int i = 0; i < N; i++)
    {
        // Calculate the time it takes for the car to reach the target
        float time = (target - cars[i].pos) / static_cast<float>(cars[i].speed);

        // Remove the cars that can be caught by the previous car fleet
        while (!mono.empty() && time >= mono.top())
        {
            mono.pop();
        }

        mono.push(time); // Add the current car's arrival time to the stack
    }

    return mono.size(); // Return the number of car fleets
}

int main()
{
    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};

    int result = carFleet(target, position, speed);
    std::cout << result;
    return 0;
}

/* Ex:
Target: 12
Pos:  [0, 3, 5, 8,10]
Speed:[1, 3, 1, 4, 2]
Time: [12,3, 7, 1, 1] */

// TC - O(NlogN +N)
// SC - O(n)
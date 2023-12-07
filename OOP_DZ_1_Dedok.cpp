#include <iostream>
using namespace std;
//класс 1
class DigitalCounter {
private:
    int minValue;
    int maxValue;
    int value;
public:
    DigitalCounter(int minVal, int maxVal) {
        minValue = minVal;
        maxValue = maxVal;
        value = minValue;
    }
    void setMinValue(int minVal) {
        minValue = minVal;
    }
    void setMaxValue(int maxVal) {
        maxValue = maxVal;
    }
    int getValue() {
        return value;
    }
    void Run(int iterations) {
        for (int i = 0; i < iterations; i++) {
            if (value < maxValue) {
                value++;
            }
            else {
                value = minValue;
            }

            cout << "Iteration " << i + 1 << ": Current Value = " << getValue() << "\n";
        }
    }
};
//класс 2
class Elevator {
private:
    int currentFloor;
    int totalFloors;
public:
    void setTotalFloors(int floors) {
        totalFloors = floors;
    }
    void moveToFloor(int destinationFloor) {
        if (destinationFloor < 1 || destinationFloor > totalFloors) {
            cout << "Invalid floor. Please select a valid floor." << "\n";
            return;
        }
        cout << "Moving from floor " << currentFloor << " to floor " << destinationFloor << "..." << "\n";
        wait(2);
        currentFloor = destinationFloor;
        cout << "Arrived at floor " << currentFloor << "\n";
    }
    void displayCurrentFloor() {
        cout << "Current floor: " << currentFloor << "\n";
    }
    void wait(int seconds) {
        time_t startTime = time(nullptr);
        while (time(nullptr) - startTime < seconds) {}
    }
    void displayMenu() {
        int destinationFloor;
        while (true) {
            cout << "Enter the destination floor (1-" << totalFloors << ", 0 to exit): ";
            cin >> destinationFloor;

            if (destinationFloor == 0) {
                break;
            }
            moveToFloor(destinationFloor);
            displayCurrentFloor();
        }
    }
};
int main()
{
    //Task_1
    DigitalCounter counter(10, 50);
    counter.Run(20);
    //Task_2
    Elevator elevator;
    elevator.setTotalFloors(10);
    elevator.displayMenu();
}

#include <cassert>
#include "PIController.h"
#include <iostream>

void testPIController() {
    double kp = 1.0;
    double ki = 0.1;
    double setPoint = 30.0;
    PIController piController(kp, ki, setPoint);

    double currentTemperature = 25.0;
    double output = piController.compute(currentTemperature);

    // Add assertions or checks as needed
    assert(output > 0.0);
    assert(output < (setPoint - currentTemperature) * kp + 1); // Example assertion
}

int main() {
    testPIController();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}

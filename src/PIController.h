#ifndef PI_CONTROLLER_H
#define PI_CONTROLLER_H

#include <chrono>

class PIController {
public:
    PIController(double kp, double ki, double setPoint);
    double compute(double currentTemperature);

private:
    double kp_;
    double ki_;
    double setPoint_;
    double integral_;
    std::chrono::steady_clock::time_point prevTime_;
};

#endif // PI_CONTROLLER_H

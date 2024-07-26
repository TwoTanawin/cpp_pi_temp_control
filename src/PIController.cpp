#include "PIController.h"

PIController::PIController(double kp, double ki, double setPoint)
    : kp_(kp), ki_(ki), setPoint_(setPoint), integral_(0.0), prevTime_(std::chrono::steady_clock::now()) {}

double PIController::compute(double currentTemperature) {
    auto currentTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedTime = currentTime - prevTime_;

    double error = setPoint_ - currentTemperature;
    integral_ += error * elapsedTime.count();

    double output = kp_ * error + ki_ * integral_;

    prevTime_ = currentTime;
    return output;
}

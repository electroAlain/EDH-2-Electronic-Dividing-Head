#include <iostream>
#include <string>

class UserInterface {
public:
    enum class Mode { Idle, Configuring, Running };

private:
    Mode currentMode;
    int displayValue;

public:
    UserInterface() : currentMode(Mode::Idle), displayValue(0) {}

    void transitionTo(Mode newMode) {
        currentMode = newMode;
        handleModeTransition();
    }

    void onButtonPress(const std::string& button) {
        if (button == "start") {
            if (currentMode == Mode::Idle) {
                transitionTo(Mode::Running);
            }
        } else if (button == "configure") {
            if (currentMode == Mode::Idle) {
                transitionTo(Mode::Configuring);
            }
        } else if (button == "stop") {
            if (currentMode == Mode::Running) {
                transitionTo(Mode::Idle);
            }
        }
    }

    void updateDisplay() {
        switch (currentMode) {
            case Mode::Idle:
                std::cout << "System is Idle. Ready to start.\n";
                break;
            case Mode::Configuring:
                std::cout << "Configuring... Enter configuration settings.\n";
                break;
            case Mode::Running:
                std::cout << "Running... Current Value: " << displayValue << "\n";
                break;
        }
    }

private:
    void handleModeTransition() {
        updateDisplay();
        // Add more transition behaviors here if needed
    }
};

int main() {
    UserInterface ui;
    ui.updateDisplay();

    ui.onButtonPress("configure");
    ui.onButtonPress("start");
    ui.updateDisplay();

    ui.onButtonPress("stop");
    ui.updateDisplay();

    return 0;
}
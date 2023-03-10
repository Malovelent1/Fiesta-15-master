#include "ControllerPrinter.hpp"
#include "EZ-Template/util.hpp"
#include "Flywheel.hpp"
#include "api.h"
#include "main.h"
#include "pros/misc.h"

char* SpeedLine()
{
    char* toReturn = new char[13];

    int currentVelocity = ez::util::clip_num(getFlywheelVelocity(), 102, 89);

    int i = 0;

    for (; i < (currentVelocity-89); i++)
    {
        toReturn[i] = '#';
    }

    for (; i < (110 - 89); i++) {
        toReturn[i] = ' ';
    }

    return toReturn;
}

void PrintInfo(void *)
{
  while (true)
  {
    master.print(0, 0, "RPM: %d / %d  ", ((int)getFlywheelVelocity()), ((int)getFlywheelTarget()));
    pros::delay(50);
    master.print(1, 0, "TMP: %d  ", getTemperature());

    pros::delay(250);
  }
}
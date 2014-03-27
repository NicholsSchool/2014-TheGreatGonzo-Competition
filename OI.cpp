// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "OI.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousSequence.h"
#include "Commands/CycleThrowerMotors.h"
#include "Commands/IntakeArmController.h"
#include "Commands/RollerIn.h"
#include "Commands/RollerOut.h"
#include "Commands/TeleOpTankDrive.h"
#include "Commands/ThrowBall.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
OI::OI() {
	// Process operator interface input here.
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	armControllerJoystick = new Joystick(3);
	
	armControllerJoystickButton6 = new JoystickButton(armControllerJoystick, 6);
	armControllerJoystickButton6->WhileHeld(new CycleThrowerMotors());
	armControllerJoystickButton3 = new JoystickButton(armControllerJoystick, 3);
	armControllerJoystickButton3->WhileHeld(new RollerOut());
	armControllerJoystickButton2 = new JoystickButton(armControllerJoystick, 2);
	armControllerJoystickButton2->WhileHeld(new RollerIn());
	armControllerJoystickTrigger = new JoystickButton(armControllerJoystick, 1);
	armControllerJoystickTrigger->WhileHeld(new ThrowBall());
     
        // SmartDashboard Buttons
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// SmartDashboard Buttons
	SmartDashboard::PutString("Test", "v007");
}
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
Joystick* OI::getArmControllerJoystick() {
	return armControllerJoystick;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

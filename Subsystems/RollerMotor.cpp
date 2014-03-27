// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "RollerMotor.h"
#include "../Robotmap.h"
RollerMotor::RollerMotor() : Subsystem("RollerMotor") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	rollerMotor = RobotMap::rollerMotorRollerMotor;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void RollerMotor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
//
// Roller Motor In
// This method rotates the spinners on the intake arm to receive a ball.
// This method always assumes a positive value.
// @example Robot::rollerMotor->rollerMotorIn(1.0);
// @param rotateInSpeed double
void RollerMotor::rollerMotorIn(double rotateInSpeed) {
	rollerMotor->Set(rotateInSpeed);
}
//
// Roller Motor Out
// This method rotates the spinners on the intake arm to pass/low-shoot the ball.
// This method always assumes a positive value.
// @example Robot::rollerMotor->rollerMotorOut(1.0);
// @param rotateOutSpeed double
void RollerMotor::rollerMotorOut(double rotateOutSpeed) {
	rollerMotor->Set(-rotateOutSpeed);
}
//
// Stop Roller Motor
// This method stops the roller motor on the intake arm.
// @example Robot::rollerMotor->rollerMotorStop();
void RollerMotor::stopRollerMotor() {
	rollerMotor->Set(0.0);
}
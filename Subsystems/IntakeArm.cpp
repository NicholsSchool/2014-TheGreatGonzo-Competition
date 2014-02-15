// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "IntakeArm.h"
#include "../Robotmap.h"
#include "../Commands/IntakeArmController.h"
IntakeArm::IntakeArm() : Subsystem("IntakeArm") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	rollerMotor = RobotMap::intakeArmRollerMotor;
	intakeArmMotor = RobotMap::intakeArmIntakeArmMotor;
	intakeArmPotentiometer = RobotMap::intakeArmIntakeArmPotentiometer;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void IntakeArm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new IntakeArmController());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
//
// Power Winch Motor
// This method controls the direction and speed of the winch motor on the intake arm.
// A negative value retracts (-1.0). A positive value extends (1.0).
// @example Robot::intakeArm->powerWinchMotor(0.5);
// @param winchSpeed double
void IntakeArm::powerWinchMotor(double winchSpeed) {
	intakeArmMotor->Set(winchSpeed);
}
//
// Stop Winch Motor
// This method tells the winch motor to do a full stop.
// @example Robot::intakeArm->stopWinchMotor();
void IntakeArm::stopWinchMotor() {
	intakeArmMotor->Set(0.0);
}
//
// Roller Motor In
// This method rotates the spinners on the intake arm to receive a ball.
// This method always assumes a positive value.
// @example Robot::intakeArm->rollerMotorIn(1.0);
// @param rotateInSpeed double
void IntakeArm::rollerMotorIn(double rotateInSpeed) {
	rollerMotor->Set(rotateInSpeed);
}
//
// Roller Motor Out
// This method rotates the spinners on the intake arm to pass/low-shoot the ball.
// This method always assumes a positive value.
// @example Robot::intakeArm->rollerMotorOut(1.0);
// @param rotateOutSpeed double
void IntakeArm::rollerMotorOut(double rotateOutSpeed) {
	rollerMotor->Set(-rotateOutSpeed);
}
//
// Stop Roller Motor
// This method stops the roller motor on the intake arm.
// @example Robot::intakeArm->rollerMotorStop();
void IntakeArm::rollerMotorStop() {
	rollerMotor->Set(0.0);
}

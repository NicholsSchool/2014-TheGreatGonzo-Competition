// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "IntakeArmController.h"
IntakeArmController::IntakeArmController() {
	// Use requires() here to declare subsystem dependencies
	// eg. requirefs(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::intakeArm);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void IntakeArmController::Initialize() {
	
}
// Called repeatedly when this Command is scheduled to run
void IntakeArmController::Execute() {
	
	// instantiate and assign arm controller joystick value
	Joystick *arm_control_joystick = Robot::oi->getArmControllerJoystick();
	
	// add if/else conditions to the dashboard
	SmartDashboard::PutBoolean( "Intake Arm: SafeToShoot", Robot::intakeArm->isFullyExtendedForward() );
	SmartDashboard::PutBoolean( "Intake Arm: FullyRetracted", Robot::intakeArm->isFullyRetractedBack() );
	
	// If neither extreme is reached, simply power the winch motor.
	if(Robot::intakeArm->isFullyRetractedBack() == false && Robot::intakeArm->isFullyExtendedForward() == false){
		Robot::intakeArm->powerWinchMotor(arm_control_joystick->GetY());
	}
	
	// Once the intake arm is fully extended, stop both the winch motor and the roller motor.
	if(Robot::intakeArm->isFullyExtendedForward()){
		if(arm_control_joystick->GetY() > 0.05){
			Robot::intakeArm->powerWinchMotor(arm_control_joystick->GetY());
		} else {
			Robot::intakeArm->stopWinchMotor();
			Robot::intakeArm->rollerMotorStop();
		}
	}
	
	// If the intake arm is fully retracted, stop the winch motor. Start roller motor on forward motion.
	if(Robot::intakeArm->isFullyRetractedBack()){
		if(arm_control_joystick->GetY() < -0.05){
			Robot::intakeArm->rollerMotorIn(-arm_control_joystick->GetY());
			Robot::intakeArm->powerWinchMotor(arm_control_joystick->GetY());
		} else {
			Robot::intakeArm->stopWinchMotor();
		}
	}
	
}
// Make this return true when this Command no longer needs to run execute()
bool IntakeArmController::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void IntakeArmController::End() {
	// This may never fire. But good practice to stop motor here.
	Robot::intakeArm->stopWinchMotor();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeArmController::Interrupted() {
	// Stop the winch motor when this method is called.
	Robot::intakeArm->stopWinchMotor();
}

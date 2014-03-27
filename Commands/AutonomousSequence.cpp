// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "AutonomousSequence.h"
#include <time.h>
AutonomousSequence::AutonomousSequence() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::theDriveTrain);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::intakeArm);
	Requires(Robot::throwerArm);
}
// Called just before this Command runs the first time
void AutonomousSequence::Initialize() {
	Robot::theDriveTrain->setSafetyBoolean(false);
}
// Called repeatedly when this Command is scheduled to run
void AutonomousSequence::Execute() {
	
	// drive forward at sixty percent
	Robot::theDriveTrain->runTankDrive(0.75, 0.75);
	Wait(3.75);
	Robot::theDriveTrain->stopTankDrive();
	
	// roller intake motor out for two seconds
//	Robot::intakeArm->rollerMotorOut(1.0);
//	Wait(2.0);
//	Robot::intakeArm->rollerMotorStop();
	
	// move the thrower arm forward until full extended
	while(Robot::intakeArm->isFullyExtendedForward() == false){
		Robot::intakeArm->powerWinchMotor(-0.85);
	}
	
	// thrower arm throw ball for point eight seconds
	if(Robot::intakeArm->isFullyExtendedForward()){
		Robot::throwerArm->moveMotorsForward(0.695);
		Wait(0.55);
		Robot::throwerArm->stopThrowerMotors();
	}
	
}
// Make this return true when this Command no longer needs to run execute()
bool AutonomousSequence::IsFinished() {
	return true;
}
// Called once after isFinished returns true
void AutonomousSequence::End() {
	Robot::theDriveTrain->stopTankDrive();
	Robot::rollerMotor->stopRollerMotor();
	Robot::throwerArm->stopThrowerMotors();
	Robot::theDriveTrain->setSafetyBoolean(true);
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousSequence::Interrupted() {
	Robot::theDriveTrain->stopTankDrive();
	Robot::rollerMotor->stopRollerMotor();
	Robot::throwerArm->stopThrowerMotors();
	Robot::theDriveTrain->setSafetyBoolean(true);
}

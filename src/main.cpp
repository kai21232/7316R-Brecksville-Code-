#include "main.h"
#include "globals.hpp"

//Boolean flags for use in driver control
bool fwToggle = false;
int intakeState = false;
bool adjusterState = false;
bool hasExpanded = false;
bool ringdetected = false;
//Holds the current target velocities for the flywheel
std::pair<int, float> flywheelVel {2600, 0.866};
std::pair<int, float> angledFlywheelVel = {2700,0.9};
std::pair<int, float> maxFlywheelVel {3600, 1.0};
std::pair<int, float> flywheelVelocitiesL1[2] {flywheelVel, angledFlywheelVel};


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void initialize() {
		Tintake.lock();
		//lift.hold();
		//pros::lcd::initialize();
}
/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {	
	//Run the auton the user selected based on the output of the Selector class
	selector.runSelection();
/*
	chassis->startOdom({55.28, -31.46}, 90_deg);

	chassis->settings.reversed = true;
	chassis->settings.maxAcceleration = 200;
	chassis->followNewPath({{
			{55.28, -31.46},
			{42.8,-36},
			{22.11,-20.69}
			
	}});
	clamp.toggle();
	pros::delay(100);

	
	chassis->turnToAngle(222_deg, 500_ms);
	Tintake.setNormalizedVelocity(-12000);
	Bintake.setNormalizedVelocity(12000);
	//pros::delay(200);

	
	chassis->settings.reversed = false;
	//chassis->settings.maxAcceleration = 200;
	chassis->followNewPath({{
			//{22.11, -20.69},
		{22.11, -20.69},
        {10.93, -28.35},
        {14.61, -54.43}
	}});
	pros::delay(200);

	chassis->settings.reversed = true;
	chassis->followNewPath({{
			{14.,-54.43},
			{8.79,-41.67},
			{30.36,-31.18}	
	}});
	pros::delay(100);


	chassis->turnToAngle(180_deg, 500_ms);
	//pros::delay(100);

	(chassis->getModel())->arcade(1, 0);
	pros::delay(340);

	chassis->turnToAngle(70_deg, 500_ms);
	pros::delay(100);

	
	chassis->settings.reversed = false;
	chassis->followNewPath({{
			//{30.36,-31.18},
		{22.11, -52.44},
        {50.46, -35.72},
        {54.14,   -13.89}

		}});
		pros::delay(100);

	Pintake.toggle();
	deflecter.toggle();
	pros::delay(100);
	chassis->settings.maxVelocity = 50;
	chassis->followNewPath({{
			//{30.36,-31.18},
			{52.31,-13.89},
			{52.31,3}	
	}});	
	pros::delay(100);	

	Pintake.toggle();
	Parm.toggle();
	babyflap.toggle();
	pros::delay(100);
	
	chassis->turnToAngle(90_deg, 800_ms);
	pros::delay(1000);
	babyflap.toggle();
	
	Bintake.setNormalizedVelocity(-12000);
	lift.setNormalizedVelocity(12000);
	Tintake.setNormalizedVelocity(12000);
	pros::delay(500);

	chassis->settings.maxVelocity = 480;
	chassis->followNewPath({{
			{52.31,3},
			{66,3}
	}});
	pros::delay(100);

	lift.setNormalizedVelocity(-12000);
	Tintake.setNormalizedVelocity(-12000);
	pros::delay(500);

	Tintake.setNormalizedVelocity(0);		
	Bintake.setNormalizedVelocity(0);
	chassis->settings.reversed = true;
	//chassis->settings.maxAcceleration = 200;
	chassis->followNewPath({{
		{66, 3},
        {53.45, 0.28},
        {43.81, 8.79}
	}});
	pros::delay(!00);

	Tintake.setNormalizedVelocity(0);		
	Bintake.setNormalizedVelocity(0);

	(chassis->getModel())->stop();
    chassis->stopOdom();*/

}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	Tintake.stop();
	Bintake.stop();
	lift.stop();
	
	

	while(true) {


		
		
		if(master[ControllerDigital::R1].isPressed())
		{
			Tintake.setNormalizedVelocity(-12000);
			Bintake.setNormalizedVelocity(12000);
		}
		else if(master[ControllerDigital::R2].isPressed()) 
		{
			Bintake.setNormalizedVelocity(-12000);
		}
		else if(master[ControllerDigital::L1].isPressed())
		{
			lift.setNormalizedVelocity(12000);
			Tintake.setNormalizedVelocity(12000);
		}
		else if(master[ControllerDigital::L2].isPressed())
		{
			lift.setNormalizedVelocity(-1);
			Tintake.setNormalizedVelocity(-1);
		}	
		else if(master[ControllerDigital::up].isPressed())
		{
			Bintake.setNormalizedVelocity(12000);
		}
		else if(master[ControllerDigital::up].changedToPressed())
		{
			Bintake.setNormalizedVelocity(-12000);
		}
		else
		{
			lift.stop();
			Tintake.stop();
			Tintake.stop();
			Bintake.stop();
		}
			
		if(master[ControllerDigital::A].changedToPressed())
		{
			clamp.toggle();
		}
		if(master[ControllerDigital::B].changedToPressed())
		{
			
			deflecter.toggle();
		}
		if(master[ControllerDigital::Y].changedToPressed())
		{
			Parm.toggle();

		}
		if(master[ControllerDigital::X].changedToPressed())
		{
			
			Pintake.toggle();
		}
		if(master[ControllerDigital::left].changedToPressed())
		{
			
			flap.toggle();
		}
		
		



		/*if(master[ControllerDigital::L1].changedToPressed() && !fwToggle) {
			fw.moveVelocity(flywheelVelocitiesL1[adjusterState]);
		}
		else if(master[ControllerDigital::L1].isPressed() && fwToggle) {
			primary.setNormalizedVelocity(-1.0);
		}
		
		if(master[ControllerDigital::L1].changedToReleased()) {
			fwToggle = true;
			primary.setNormalizedVelocity(intakeState);
		}

		if(master[ControllerDigital::L2].changedToPressed()) {
			fwToggle = false;
			fw.moveVelocity(0);
		}

		if(master[ControllerDigital::R1].changedToPressed()) {
			intakeState = !intakeState;
			primary.setNormalizedVelocity(intakeState);
		}

		if(master[ControllerDigital::R2].changedToPressed()) {
			primary.setNormalizedVelocity(-1.0);
		}
		else if(master[ControllerDigital::R2].changedToReleased()) {
			intakeState = false;
			primary.stop();
		}

		if(master[ControllerDigital::A].changedToPressed()) {
			primary.setNormalizedVelocity(intakeState *= -1);
		}

		if(master[ControllerDigital::up].changedToPressed()) {
			adjusterState = !adjusterState;
			angleAdjuster.toggle();
			fw.moveVelocity(flywheelVelocitiesL1[adjusterState]);
		}

		if(master[ControllerDigital::X].changedToPressed()) {
			fw.moveVelocity(maxFlywheelVel);
			fwToggle = true;
		}

		if(master[ControllerDigital::L1].isPressed() &&
		   master[ControllerDigital::L2].isPressed() &&
		   master[ControllerDigital::R1].isPressed() &&
		   master[ControllerDigital::R2].isPressed() &&
		   !hasExpanded) {
			hasExpanded = true;
			primary.setNormalizedVelocity(intakeState = false);
			fw.moveVelocity(fwToggle = false);
			lowExpansion1.toggle();
			lowExpansion2.toggle();
			highExpansion.toggle();
		}

		if(master[ControllerDigital::down].changedToPressed() && !hasExpanded) {
			lowExpansion1.toggle();
			lowExpansion2.toggle();
		}*/


		chassis->getModel()->tank (
			master.getAnalog(ControllerAnalog::leftY),
			master.getAnalog(ControllerAnalog::rightY)
		);

		pros::delay(20);
	}
}




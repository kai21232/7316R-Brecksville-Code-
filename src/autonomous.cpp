#include "autonomous.hpp"
#include "globals.hpp"



//4.75 inches per milisecond
//6.2 Inches per milisecond
//3.1(s) x 4.75

void  blueright5Ring() {
  

chassis->startOdom({-55.28, -31.46}, -90_deg);

	chassis->settings.reversed = true;
	chassis->settings.maxAcceleration = 200;
	chassis->followNewPath({{
			{-55.28, -31.46},
			{-42.8,-36},
			{-22.11,-20.69}
			
	}});
	clamp.toggle();
	pros::delay(100);

	
	chassis->turnToAngle(-215_deg, 500_ms);
	Tintake.setNormalizedVelocity(-12000);
	Bintake.setNormalizedVelocity(12000);
	//pros::delay(200);

	
	chassis->settings.reversed = false;
	//chassis->settings.maxAcceleration = 200;
	chassis->followNewPath({{
			//{22.11, -20.69},
		{-22.11, -20.69},
        {-13.27, -28.35},
        {-13.27, -54.43}
	}});
	pros::delay(200);

	chassis->settings.reversed = true;
	chassis->followNewPath({{
			{-13.27,-54.43},
			{-8.79,-41.67},
			{-30.36,-31.18}	
	}});
	pros::delay(100);


	chassis->turnToAngle(-180_deg, 500_ms);
	//pros::delay(100);

	(chassis->getModel())->arcade(1, 0);
	pros::delay(340);

	chassis->turnToAngle(-70_deg, 500_ms);
	pros::delay(100);

	
	chassis->settings.reversed = false;
	chassis->followNewPath({{
			//{30.36,-31.18},
		{-22.11, -52.44},
        {-50.46, -35.72},
        {-54.14,   -13.89}

		}});
		pros::delay(100);

	Pintake.toggle();
	deflecter.toggle();
	pros::delay(100);
	chassis->settings.maxVelocity = 50;
	chassis->followNewPath({{
			//{30.36,-31.18},
			{-52.31,-13.89},
			{-52.31,4}	
	}});	
	pros::delay(100);	

	//Pintake.toggle();
	Parm.toggle();
	flap.toggle();
	pros::delay(100);
	
	chassis->turnToAngle(-90_deg, 800_ms);
	pros::delay(1000);
	flap.toggle();
	
	Bintake.setNormalizedVelocity(12000);
	lift.setNormalizedVelocity(12000);
	Tintake.setNormalizedVelocity(12000);
	pros::delay(500);

	chassis->settings.maxVelocity = 480;
	chassis->followNewPath({{
			{-52.31,4},
			{-65,4}
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
		{-65, 4},
        {-53.45, 0.28},
        {-43.81, 8.79}
	}});
	pros::delay(!00);

	Tintake.setNormalizedVelocity(0);		
	Bintake.setNormalizedVelocity(0);

	(chassis->getModel())->stop();
    chassis->stopOdom();
	}


void redleft5Ring() {

	
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

	
	chassis->turnToAngle(215_deg, 500_ms);
	Tintake.setNormalizedVelocity(-12000);
	Bintake.setNormalizedVelocity(12000);
	//pros::delay(200);

	
	chassis->settings.reversed = false;
	//chassis->settings.maxAcceleration = 200;
	chassis->followNewPath({{
			//{22.11, -20.69},
		{22.11, -20.69},
        {13.27, -27.78},
        {13.27, -54.43}
	}});
	pros::delay(200);

	chassis->settings.reversed = true;
	chassis->followNewPath({{
			{13.27,-54.43},
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
			{52.31,4}	
	}});	
	pros::delay(100);	

	//Pintake.toggle();
	Parm.toggle();
	babyflap.toggle();
	pros::delay(100);
	
	chassis->turnToAngle(90_deg, 800_ms);
	pros::delay(1000);
	babyflap.toggle();
	
	Bintake.setNormalizedVelocity(12000);
	lift.setNormalizedVelocity(12000);
	Tintake.setNormalizedVelocity(12000);
	pros::delay(500);

	chassis->settings.maxVelocity = 480;
	chassis->followNewPath({{
			{52.31,4},
			{66,4}
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
		{65, 4},
        {53.45, 0.28},
        {43.81, 8.79}
	}});
	pros::delay(!00);

	Tintake.setNormalizedVelocity(0);		
	Bintake.setNormalizedVelocity(0);

	(chassis->getModel())->stop();
    chassis->stopOdom();

	}
    	



void blueleft3Ring() {

	 
	chassis->startOdom({ -55.28, 31.48}, -90_deg);

	chassis->settings.reversed = true;
	//chassis->settings.maxVelocity = 200;
	chassis->followNewPath({{
			{-55.28, 31.48},
			{-42.8,36},
			{ -24.09,23.81}
			
	}});
	pros::delay(100);
	
	clamp.toggle();
	pros::delay(100);	

	Tintake.setNormalizedVelocity(-3000);
	Bintake.setNormalizedVelocity(3000);
	pros::delay(500);

	clamp.toggle();

	chassis->turnToAngle(0_deg, 1.0_s);
	pros::delay(100);

	chassis->settings.reversed = false;
	//chassis->settings.maxVelocity = 480;
	chassis->followNewPath({{
			 {-24.09,23.81},
			{ -24.09,45.91}
	}});
	pros::delay(100);
	Tintake.setNormalizedVelocity(0);
	Bintake.setNormalizedVelocity(0);
	pros::delay(100);

	

	chassis->settings.reversed = true;
	
	chassis->followNewPath({{
		{-24.09, 45.91},
        {-42.25, 29.48},
        {-7.37,47.34}

	}});
	pros::delay(100);

	clamp.toggle();

	Tintake.setNormalizedVelocity(-12000);
	Bintake.setNormalizedVelocity(12000);
	Pintake.toggle();
	pros::delay(100);

	chassis->settings.reversed = false;
	chassis->followNewPath({{
		{-7.37, 47.34},
        {-48.19, 0.28}
	}});
	pros::delay(100);
	Pintake.toggle();
	pros::delay(100);

	chassis->settings.reversed = true;

	chassis->followNewPath({{
			{-48.19, 0.28},
			{-48.19,10.2} 
	}});	
	pros::delay(100);

	chassis->turnToAngle(-120_deg, 1.0_s);
	pros::delay(100);


/*		
	chassis->settings.reversed = false;
	chassis->followNewPath({{
	{-48.19,10.2},
	{-40.25,-1.7},
	{-28.06,3.97}
	}});
	pros::delay(100);*/

	(chassis->getModel())->stop();
    chassis->stopOdom();

/*
	(chassis->getModel())->arcade(-.50, 0);
	pros::delay(1100);
	(chassis->getModel())->arcade(0, 0);
	pros::delay(1000);
	clamp.toggle();
	pros::delay(500);
	Tintake.setNormalizedVelocity(-12000);
	Bintake.setNormalizedVelocity(12000);
	pros::delay(2000);
	clamp.toggle();
	(chassis->getModel())->arcade(1, 0);
	pros::delay(100);
	
	chassis->turnToAngle(66_deg, 1.0_s);
	pros::delay(1000);
	

	(chassis->getModel())->arcade(1, 0);
	pros::delay(440);
	(chassis->getModel())->arcade(0, 0);
	pros::delay(300);
	Tintake.setNormalizedVelocity(0);
	Bintake.setNormalizedVelocity(0);
	(chassis->getModel())->arcade(0, 0);
	pros::delay(1000);
	//pros::delay(1000);
	
	(chassis->getModel())->arcade(-1, 0);
	pros::delay(560);
	chassis->turnToAngle(300_deg, 1.0_s);
	pros::delay(1000);	

	(chassis->getModel())->arcade(-.50, 0);
	pros::delay(720);
	
	(chassis->getModel())->arcade(0, 0);
	pros::delay(1000);
	clamp.toggle();
	pros::delay(500);
	Tintake.setNormalizedVelocity(-12000);
	Bintake.setNormalizedVelocity(12000);
	chassis->turnToAngle(330_deg, 1.0_s);
	pros::delay(2000);
/
	(chassis->getModel())->arcade(1, 0);
	pros::delay(260);

	chassis->turnToAngle(285_deg, 1.0_s);
	pros::delay(1000);
	Pintake.toggle();
	
	(chassis->getModel())->arcade(.5, 0);
	pros::delay(1900);

	
	(chassis->getModel())->arcade(-1, 0);
	pros::delay(250);


	
	Pintake.toggle();
	(chassis->getModel())->arcade(0, 0);
	pros::delay(1000);

	
	chassis->turnToAngle(156_deg, 1.0_s);
	pros::delay(1000);
	(chassis->getModel())->arcade(1, 0);
	pros::delay(200);
	Tintake.setNormalizedVelocity(0);
	Bintake.setNormalizedVelocity(0);
	
	(chassis->getModel())->stop();
    chassis->stopOdom();*/
}

   


void redright3Ring() {
		
	chassis->startOdom({ 	55.28, 31.48}, 90_deg);

		
	chassis->settings.reversed = true;
	//chassis->settings.maxVelocity = 200;
	chassis->followNewPath({{
			{55.28, 31.48},
			{42.8,36},
			{ 24.09,23.81}
			
	}});
	pros::delay(100);
	
	clamp.toggle();
	pros::delay(100);	

	Tintake.setNormalizedVelocity(-3000);
	Bintake.setNormalizedVelocity(3000);
	pros::delay(500);

	clamp.toggle();

	chassis->turnToAngle(0_deg, 1.0_s);
	pros::delay(100);

	chassis->settings.reversed = false;
	//chassis->settings.maxVelocity = 480;
	chassis->followNewPath({{
			 {24.09,23.81},
			{ 24.09,45.91}
	}});
	pros::delay(100);
	Tintake.setNormalizedVelocity(0);
	Bintake.setNormalizedVelocity(0);
	pros::delay(100);

	

	chassis->settings.reversed = true;
	chassis->followNewPath({{
		{24.09, 45.91},
        {42.25, 29.48},
        {7.37,47.34}

	}});
	pros::delay(100);

	clamp.toggle();

	Tintake.setNormalizedVelocity(-12000);
	Bintake.setNormalizedVelocity(12000);
	Pintake.toggle();
	pros::delay(100);

	chassis->settings.reversed = false;
	chassis->followNewPath({{
		{7.37, 47.34},
        {48.19, 0.28}
	}});
	pros::delay(100);
	Pintake.toggle();
	pros::delay(100);

	chassis->settings.reversed = true;
	chassis->followNewPath({{
			{48.19, 0.28},
			{48.19,10.2} 
	}});	
	pros::delay(100);

	chassis->turnToAngle(-120_deg, 1.0_s);
	pros::delay(100);


			
(chassis->getModel())->stop();
    chassis->stopOdom();
}



void blueright6Ring() {
    /*chassis->startOdom({55.9375, 6.25}, -90_deg);
	

    chassis->stopOdom();*/
}

void redleft6Ring(){

	 /*chassis->startOdom({-36.875, -58.375}, 0_deg);



	chassis->getModel()->stop();
	chassis->stopOdom();*/
}


void fullWP() {
 
}
#include "catapult.hpp"
#include "globals.hpp"


namespace xlib {}



namespace xlib {
      /**
     * @param vel Velocity on [-1, 1]
     */
 
void Catapult::setNormalizedVelocity(float vel) {
    moveVelocity(std::clamp(vel,-1.0f,1.0f) * 12000);
}
    /**
     * @return Velocity on [-1, 1]
     */
float Catapult::getNormalizedVelocity(){
return std::clamp(static_cast<float>(getActualVelocity()/ 200),-1.0f,1.0f);



}




void Catapult::stop() {
        setNormalizedVelocity(0.0);
    }



    void Catapult::catapultFlip() {
        okapi::Timer time;
        time.placeMark();
        tarePosition();
        setNormalizedVelocity(-200);
        while(getPosition() > -1150 && time.getDtFromMark() < 1000_ms) 
            pros::delay(25);
 
    }

    

    void Catapult::hold(){ 
        setBrakeMode(AbstractMotor::brakeMode::hold);
    }



Catapult::Catapult(const std::int8_t iport/*, const okapi::IterativePosPIDController::Gains& igains*/)
        : okapi::Motor{iport}{} //Calls the constructor for okapi::Motor 
       




}
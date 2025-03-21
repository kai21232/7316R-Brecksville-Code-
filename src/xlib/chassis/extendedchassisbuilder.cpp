#include "xlib/chassis/extendedchassisbuilder.hpp"

namespace xlib {

    /**
     * Sets the left and right drivetrain motors
     *
     * @param ileft The left motors
     * @param iright The right motors
     * @return An ongoing builder
     */
    ExtendedChassisBuilder& ExtendedChassisBuilder::withMotors(const MotorGroup& ileft, const MotorGroup& iright) {
        left = std::make_shared<MotorGroup>(ileft);
        right = std::make_shared<MotorGroup>(iright);

        return *this;
    }

    /**
     * Sets the chassis dimensions
     *
     * @param igearset Internal and external gearset in the drive motors
     * @param iscales Dimensions of the chassis
     * @param itrackwidth Distance between the drive wheels
     * @return An ongoing builder
     */
    ExtendedChassisBuilder& ExtendedChassisBuilder::withDimensions(const AbstractMotor::GearsetRatioPair& igearset, const ChassisScales& iscales, QLength itrackWidth) {
        gearset = igearset;
        scales = iscales;
        trackWidth = itrackWidth.convert(inch);

        return *this;
    }

    /**
     * Sets the maximum velocity the robot can follow a path with
     *
     * @param absolMaxVel The max velocity the chassis is capable of (rpm)
     * @return An ongion builder
     */
    ExtendedChassisBuilder& ExtendedChassisBuilder::withMaxVelocity(const float absolMaxVel) {
        absoluteMaxVelocity = absolMaxVel;

        return *this;
    }

     /**
      * Sets all sensors used in odometry and pure pursuit
      * 
      * @param itracking Tracking wheel (parallel) to measure arc length
      * @param irotation 
      * @param inertial Inertial sensor to measure robot's heading
      * @return ExtendedChassisBuilder& 
      */
    ExtendedChassisBuilder& ExtendedChassisBuilder::withSensors(const RotationSensor& irotation,
                                        const IMU& inertial) {
        rotationsensor = std::make_shared<RotationSensor>(irotation);
        imu = std::make_shared<IMU>(inertial);

        return *this;
    }

    /**
     * Sets PID controller and pure pursuit gains
     *
     * @param idistanceGains The distance controller's gains
     * @param iturnGains The turn controller's gain
     * @param iangleGains The heading correction controller's gains
     * @param ipurePursuitGains Pure pursuit controller's gains
     * @return An ongoing builder
     */
    ExtendedChassisBuilder& ExtendedChassisBuilder::withGains(const IterativePosPIDController::Gains& idistanceGains, const IterativePosPIDController::Gains& iturnGains, const IterativePosPIDController::Gains& iangleGains, const IterativePosPIDController::Gains& ipurePursuitGains) {
        distanceGains = idistanceGains;
        turnGains = iturnGains;
        angleGains = iangleGains;

        purePursuitGains.push_back(ipurePursuitGains.kP);
        purePursuitGains.push_back(ipurePursuitGains.kI);
        purePursuitGains.push_back(ipurePursuitGains.kD);

        return *this;
    }

    /**
     * Sets pure pursuit path generating and following velocity constraints
     *
     * @param maxVel Maximum velocity the path generator can request
     * @param maxAccel Maximum acceleration the path generator can request
     * @param curveConstant How much the robot slows down around curves
     * @param maxChange The maximum rate of change permitted by the rate limiter
     * @return An ongoing builder
     */
    ExtendedChassisBuilder& ExtendedChassisBuilder::withVelocityConstants(float maxVel, float maxAccel, float curveConstant, float maxChange) {
        maxVelocity = maxVel;
        maxAcceleration = maxAccel;
        k = curveConstant;
        maxRateChange = maxChange;

        return *this;
    }

    /**
     * Sets the lookahead distance for the pure pursuit controller
     *
     * @param ilookahead Radius of lookahead circle
     * @return An ongoing builder
     */
    ExtendedChassisBuilder& ExtendedChassisBuilder::withLookahead(QLength ilookahead) {
        lookahead = ilookahead.convert(inch);

        return *this;
    }

    /**
     * Builds the ExtendedChassis object. Initializes a new settings object with
     * pure pursuit tuning constants.
     *
     * @return A fully built ExtendedChassis
     */
    std::shared_ptr<ExtendedChassis> ExtendedChassisBuilder::build() {

        QPath::Settings settings {maxVelocity, absoluteMaxVelocity, maxAcceleration, k, 
            lookahead, maxRateChange, trackWidth, purePursuitGains};

        return std::make_shared<ExtendedChassis>(*left, *right,
            gearset, scales,
            *rotationsensor, *imu,
            distanceGains, turnGains, angleGains, settings
        );
    }

}
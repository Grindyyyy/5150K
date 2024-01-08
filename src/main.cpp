
// THIS CODE WILL NEED TO BE ADJUSTED FOR REVERSE MOTORS.
#include "main.h"
// Make sure to change the ports as needed!
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor leftFront(13,pros::E_MOTOR_GEARSET_06, false);
pros::Motor rightFront(19,pros::E_MOTOR_GEARSET_06, true);
pros::Motor leftBack(11,pros::E_MOTOR_GEARSET_06, false);
pros::Motor rightBack(20,pros::E_MOTOR_GEARSET_06, true);
pros::Motor leftMiddle(1,pros::E_MOTOR_GEARSET_06, true);
pros::Motor rightMiddle(10,pros::E_MOTOR_GEARSET_06, false);
pros::Motor cataMotor(8,pros::E_MOTOR_GEARSET_36,true);
pros::Motor intakeMotor(2,pros::E_MOTOR_GEARSET_06,false);
pros::Motor_Group leftDB({leftFront, leftMiddle, leftBack});
pros::Motor_Group rightDB({rightFront, rightMiddle, rightBack});
void on_center_button(){}



void initialize(){}



void disabled(){}



void competition_initialize(){}



void autonomous(){
// FAR SIDE ALLIANCE AWP
leftDB.move(-127);
rightDB.move(-127);
pros::delay(1500);
leftDB.move(127);
rightDB.move(127);
pros::delay(300);
leftDB.move(-127);
rightDB.move(-127);
pros::delay(500);
leftDB.move(127);
rightDB.move(127);
pros::delay(500);
leftDB.move(0);
rightDB.move(0);
}



void opcontrol(){
while(1){
double power = master.get_analog(ANALOG_LEFT_Y);
double turn = master.get_analog(ANALOG_RIGHT_X);
leftDB.move(power - turn);
rightDB.move(power + turn);
if(master.get_digital(DIGITAL_R2)){
    cataMotor.move(100);
}
else{
    cataMotor.move(0);
}

        // Intake Code
        // If R2 is held down, motor = max speed
        if(master.get_digital(DIGITAL_L2)){
            intakeMotor.move(127);
        }
        
        // Intake Code
        // If L2 is held down, motor = max reverse speed
        else if(master.get_digital(DIGITAL_L1)){
            intakeMotor.move(-127);
        }

        // Intake Code
        // Otherwise, dont move at all
        else{
            intakeMotor.move(0);
        }
}
}

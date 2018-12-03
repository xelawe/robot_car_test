#include <AutoPID.h>

//pid settings and gains
#define OUTPUT_MIN 0
#define OUTPUT_MAX 32
//#define KP .12
#define KP .3
//#define KI .0003
#define KI .2
#define KD 0.1

double gv_pid_speed_r, gv_pid_speed_set_r, gv_pid_speed_out_r;
double gv_pid_speed_l, gv_pid_speed_set_l, gv_pid_speed_out_l;

//input/output variables passed by reference, so they are updated automatically
AutoPID myPID_r(&gv_pid_speed_r, &gv_pid_speed_set_r, &gv_pid_speed_out_r, OUTPUT_MIN, OUTPUT_MAX, KP, KI, KD);
AutoPID myPID_l(&gv_pid_speed_l, &gv_pid_speed_set_l, &gv_pid_speed_out_l, OUTPUT_MIN, OUTPUT_MAX, KP, KI, KD);

void init_pid() {
  //if temperature is more than x ticks below or above setpoint, OUTPUT will be set to min or max respectively
  //myPID_r.setBangBang(10);
  //myPID_l.setBangBang(10);

  //set PID update interval to 4000ms
  myPID_r.setTimeStep(800);
  myPID_l.setTimeStep(800);
}

void check_pid() {
  myPID_r.run();
  myPID_l.run();
}


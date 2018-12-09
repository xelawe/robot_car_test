#include <PID_v1.h>

double gv_pid_speed_r, gv_pid_speed_set_r, gv_pid_speed_out_r;
double gv_pid_speed_l, gv_pid_speed_set_l, gv_pid_speed_out_l;

//Specify the links and initial tuning parameters
double Kp = 0.4;
double Ki = 0.2;
double Kd = 0;

PID myPID_r(&gv_pid_speed_r, &gv_pid_speed_out_r, &gv_pid_speed_set_r, Kp, Ki, Kd, DIRECT);
//PID myPID_l(&gv_pid_speed_l, &gv_pid_speed_out_l, &gv_pid_speed_set_l, Kp, Ki, Kd, DIRECT);


void init_pid() {
  //turn the PID on
  myPID_r.SetOutputLimits(0, 30);
  myPID_r.SetSampleTime(1000);

  myPID_r.SetMode(AUTOMATIC);
  // myPID_l.SetMode(AUTOMATIC);
}


void check_pid() {
  myPID_r.Compute();
  // myPID_l.Compute();
}


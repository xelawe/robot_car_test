#include <PID_v1.h>

double gv_pid_speed_r, gv_pid_speed_set_r, gv_pid_speed_out_r;
double gv_pid_speed_l, gv_pid_speed_set_l, gv_pid_speed_out_l;

//Specify the links and initial tuning parameters
double Kp = 2, Ki = 5, Kd = 1;

PID myPID_r(&gv_pid_speed_r, &gv_pid_speed_out_r, &gv_pid_speed_set_r, Kp, Ki, Kd, DIRECT);
PID myPID_l(&gv_pid_speed_l, &gv_pid_speed_out_l, &gv_pid_speed_set_l, Kp, Ki, Kd, DIRECT);


void init_pid() {
  //turn the PID on
  myPID_r.SetMode(AUTOMATIC);
  myPID_l.SetMode(AUTOMATIC);
}


void check_pid() {
  myPID_r.Compute();
  myPID_l.Compute();
}


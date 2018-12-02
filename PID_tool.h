#include <AutoPID.h>

//pid settings and gains
#define OUTPUT_MIN 0
#define OUTPUT_MAX 32
#define KP .12
#define KI .0003
#define KD 0

double gv_pid_speed_r, gv_pid_speed_set_r, gv_pid_speed_out_r;
double gv_pid_speed_l, gv_pid_speed_set_l, gv_pid_speed_out_l;

//input/output variables passed by reference, so they are updated automatically
AutoPID myPID_r(&gv_pid_speed_r, &gv_pid_speed_set_r, &gv_pid_speed_out_r, OUTPUT_MIN, OUTPUT_MAX, KP, KI, KD);
AutoPID myPID_l(&gv_pid_speed_l, &gv_pid_speed_set_l, &gv_pid_speed_out_l, OUTPUT_MIN, OUTPUT_MAX, KP, KI, KD);

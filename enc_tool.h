#include <Ticker.h>

#define ENC_R D5
#define ENC_L D6
// variables to store the number of encoder pulses
// for each motor
volatile unsigned long leftCount = 0;
volatile unsigned long rightCount = 0;
volatile unsigned long gv_leftCount = 0;
volatile unsigned long gv_rightCount = 0;
volatile boolean gv_do_chk_spd;




Ticker tick_spd_cnt;


void check_speed() {
  gv_pid_speed_r = rightCount;
  rightCount = 0;

  gv_pid_speed_l = leftCount;
  leftCount = 0;


  gv_do_chk_spd = true;

}


// encoder event for the interrupt call
void leftEncoderEvent() {
  leftCount++;
}

void rightEncoderEvent() {
  rightCount++;
}

void init_enc() {


  pinMode(ENC_R, INPUT);
  pinMode(ENC_L, INPUT);

  tick_spd_cnt.attach(1, check_speed);

  // initialize hardware interrupts
  attachInterrupt(ENC_R, rightEncoderEvent, FALLING);
  attachInterrupt(ENC_L, leftEncoderEvent, FALLING);
}


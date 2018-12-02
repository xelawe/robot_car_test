const short PWM_R = D1;
const short DIR_R = D3;

const short PWM_L = D2;
const short DIR_L = D4;

#define m_forward LOW
#define m_reverse HIGH


void init_motor() {

  // initialize pins
  pinMode(PWM_R, OUTPUT);
  pinMode(PWM_L, OUTPUT);
  pinMode(DIR_R, OUTPUT);
  pinMode(DIR_L, OUTPUT);


}

void set_speed( int iv_speed, short iv_dir, short iv_pwm_side, short iv_dir_side  ) {

  int lv_speed = map(iv_speed, 0, 32, 0, 1024);

  digitalWrite(iv_dir_side, iv_dir);
  analogWrite(iv_pwm_side, lv_speed);

}

void set_speed_l( int iv_speed, short iv_dir ) {
  set_speed( iv_speed, iv_dir, PWM_L, DIR_L);
}


void set_speed_r( int iv_speed, short iv_dir ) {
  set_speed( iv_speed, iv_dir, PWM_R, DIR_R);
}


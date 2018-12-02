/** simple test for motor board with node mcu v2
     fambach.net
*/
#include "PID_tool.h"
#include "motor_tool.h"
#include "enc_tool.h"

void setup() {


  Serial.begin(115200);
  delay(500);
  Serial.println("Serial init ok");

  init_motor();

  init_enc();

  init_pid();

  gv_pid_speed_set_r = 20;
  gv_pid_speed_set_l = 20;

}


void loop() {

  if ( gv_do_chk_spd == true) {

    myPID_r.run();
    int lv_speed = gv_pid_speed_out_r;
    set_speed_r( lv_speed, m_forward );
    Serial.print("Rechts :");
    Serial.print(gv_pid_speed_set_r);
    Serial.print("; ");
    Serial.print(gv_pid_speed_r);
    Serial.print("; ");
    Serial.print(gv_pid_speed_out_r);
    Serial.print("; ");
    Serial.print(lv_speed);
    Serial.println("");

    myPID_l.run();
    lv_speed = gv_pid_speed_out_l;
    set_speed_l( lv_speed, m_forward );
    Serial.print("Links :");
    Serial.print(gv_pid_speed_set_l);
    Serial.print("; ");
    Serial.print(gv_pid_speed_l);
    Serial.print("; ");
    Serial.print(gv_pid_speed_out_l);
    Serial.print("; ");
    Serial.print(lv_speed);
    Serial.println("");

    gv_do_chk_spd = false;
  }
  //  if (gv_do_chk_spd == true) {
  //    Serial.print("Rechts :");
  //    Serial.println(gv_rightCount);
  //
  //    Serial.print("Links :");
  //    Serial.println(gv_leftCount);
  //
  //    if (gv_rightCount > 30) {
  //      gv_spd_corr_r = gv_spd_corr_r + 10;
  //      Serial.print("speed corr R ");
  //      Serial.println (gv_spd_corr_r);
  //
  //      int lv_speed = speed - gv_spd_corr_r;
  //
  //      digitalWrite(DIR_R, m_forward);
  //      analogWrite(PWM_R, lv_speed);
  //    }
  //
  //    if (gv_leftCount > 30) {
  //      gv_spd_corr_l = gv_spd_corr_l + 10;
  //      Serial.print("speed corr L ");
  //      Serial.println (gv_spd_corr_l);
  //
  //      int lv_speed = speed - gv_spd_corr_l;
  //
  //      digitalWrite(DIR_L, m_forward);
  //      analogWrite(PWM_L, lv_speed);
  //    }
  //
  //
  //    Serial.println(" ");
  //
  //    gv_do_chk_spd = false;
  //
  //
  //
  //  }


  //  Serial.println("R forward");
  //  digitalWrite(DIR_R, m_forward);
  //  analogWrite(PWM_R, speed);
  //  digitalWrite(DIR_L, m_forward);
  //  analogWrite(PWM_L, speed);
  //  delay(5000);





  //  Serial.println("Both stop");
  //  analogWrite(PWM_R, 0);
  //  digitalWrite(DIR_R, m_reverse);
  //  analogWrite(PWM_L, 0);
  //  digitalWrite(DIR_L, m_reverse);
  //  delay(2000);
  //
  //  Serial.println("L forward");
  //  digitalWrite(DIR_R, m_reverse);
  //  analogWrite(PWM_R, 0);
  //  digitalWrite(DIR_L, m_forward);
  //  analogWrite(PWM_L, speed);
  //  delay(5000);
  //
  //
  //  Serial.println("Both stop");
  //  analogWrite(PWM_R, 0);
  //  digitalWrite(DIR_R, m_reverse);
  //  analogWrite(PWM_L, 0);
  //  digitalWrite(DIR_L, m_reverse);
  //  delay(2000);
  //
  //  Serial.println("Both forward");
  //  digitalWrite(DIR_R, m_forward);
  //  analogWrite(PWM_R, speed);
  //  digitalWrite(DIR_L, m_forward);
  //  analogWrite(PWM_L, speed);
  //  delay(5000);
  //
  //  Serial.println("Both stop");
  //  analogWrite(PWM_R, 0);
  //  digitalWrite(DIR_R, m_reverse);
  //  analogWrite(PWM_L, 0);
  //  digitalWrite(DIR_L, m_reverse);
  //  delay(2000);
  //
  //  Serial.println("Both backward");
  //  digitalWrite(DIR_R, m_reverse);
  //  analogWrite(PWM_R, speed);
  //  digitalWrite(DIR_L, m_reverse);
  //  analogWrite(PWM_L, speed);
  //  delay(5000);

  //  Serial.println("Both stop");
  //  analogWrite(PWM_R, 0);
  //  digitalWrite(DIR_R, m_reverse);
  //  analogWrite(PWM_L, 0);
  //  digitalWrite(DIR_L, m_reverse);
  //  delay(2000);

}





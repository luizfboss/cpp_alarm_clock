#include <iostream>

#include "alarm_clock.h" // Including header file

int main() {
  // This is test code for your AlarmClock class. Uncomment as you go to 
  // test your work. Note that just passing these tests does not necessarily
  // mean you have successfully met the assignment requirements.
  AlarmClock ac1 = AlarmClock();  
  ac1.DisplayTime();   // Expect 12:00  
  ac1.DisplayAmPm();   // Expect AM

  ac1.AlarmButton();
  ac1.DisplayTime();   // Expect 12:00
  ac1.DisplayAmPm();   // Expect AM
  ac1.DisplayAlarmSet();  // Expect Alarm is OFF 

  ac1.AlarmButton();
  ac1.DisplayTime();   // Expect 12:00
  ac1.DisplayAmPm();   // Expect AM

  ac1.TimeButton();    // Start changing the time
  ac1.HourButton();
  ac1.MinButton();
  
  ac1.DisplayTime();   // Expect 01:01
  ac1.DisplayAmPm();   // Expect AM
  
  for (int i=0; i<58; i++) {
    ac1.MinButton();
  }

  ac1.DisplayTime();   // Expect 01:59
  ac1.DisplayAmPm();   // Expect AM

  ac1.MinButton();
  ac1.DisplayTime();   // Expect 01:00
  ac1.DisplayAmPm();   // Expect AM

  for (int i=0; i<10; i++) {
    ac1.HourButton();
  }
  ac1.DisplayTime();   // Expect 11:00
  ac1.DisplayAmPm();   // Expect AM

  ac1.HourButton();
  ac1.DisplayTime();   // Expect 12:00
  ac1.DisplayAmPm();   // Expect PM

  ac1.HourButton();
  ac1.DisplayTime();   // Expect 1:00
  ac1.DisplayAmPm();   // Expect PM

  for (int i=0; i<10; i++) {
    ac1.HourButton();
  }
  ac1.DisplayTime();   // Expect 11:00
  ac1.DisplayAmPm();   // Expect PM

  ac1.HourButton();
  ac1.DisplayTime();   // Expect 12:00
  ac1.DisplayAmPm();   // Expect AM

  // Push to a weird time
  for (int i=0; i<7; i++) {
    ac1.HourButton();
    ac1.MinButton();
    ac1.MinButton();  
  }

  ac1.DisplayTime();   // Expect 7:14
  ac1.DisplayAmPm();   // Expect AM
  
  // Alarm time should be unchanged while we've been setting the clock time.
  ac1.AlarmButton();
  ac1.DisplayTime();   // Expect 12:00
  ac1.DisplayAmPm();   // Expect AM

  // Now repeat tests with the alarm instead of regular time
  for (int i=0; i<59; i++) {    
    ac1.MinButton();
  }
  ac1.DisplayTime();   // Expect 12:59
  ac1.DisplayAmPm();   // Expect AM

  
  ac1.MinButton();
  ac1.DisplayTime();   // Expect 12:00
  ac1.DisplayAmPm();   // Expect AM

  ac1.MinButton();
  ac1.DisplayTime();   // Expect 12:01
  ac1.DisplayAmPm();   // Expect AM

  for (int i=0; i<9; i++) {
    ac1.HourButton();
  }
  ac1.DisplayTime();   // Expect 9:01
  ac1.DisplayAmPm();   // Expect AM

  ac1.HourButton();
  ac1.DisplayTime();   // Expect 10:01
  ac1.DisplayAmPm();   // Expect AM

  ac1.HourButton();
  ac1.HourButton();
  ac1.DisplayTime();   // Expect 12:01
  ac1.DisplayAmPm();   // Expect PM

  ac1.HourButton();
  ac1.HourButton();
  ac1.DisplayTime();   // Expect 2:01
  ac1.DisplayAmPm();   // Expect PM
  
  for (int i=0; i<719; i++) {
    ac1.MinButton();
  }
  ac1.DisplayTime();   // Expect 2:00
  ac1.DisplayAmPm();   // Expect PM

  // Alarm time should be unchanged while we've been setting the clock time.
  ac1.AlarmButton();
  ac1.DisplayTime();   // Expect 7:14
  ac1.DisplayAmPm();   // Expect AM

  ac1.TimeButton();
  ac1.MinButton();
  ac1.DisplayTime();   // Expect 7:15
  // (WOULDN'T THE CODE ABOVE BE 7:15 BECAUSE ONE MINUTE IS BEING INCREMENTED??)
  
  ac1.DisplayAmPm();   // Expect AM

  std::cout << std::endl << "Alarm clock 2, using constructor 2" << std::endl;
  AlarmClock ac2 = AlarmClock(3, 33, true);
  ac2.DisplayTime();   // Expect 03:33
  ac2.DisplayAmPm();   // Expect PM

  ac2.AlarmButton();
  ac2.DisplayTime();   // Expect 12:00
  ac2.DisplayAmPm();   // Expect AM
  ac2.DisplayAlarmSet();  // Expect Alarm is OFF
  
  ac2.HourButton();
  ac2.MinButton();

  ac2.DisplayTime();   // Expect 01:01
  ac2.DisplayAmPm();   // Expect AM

  for (int i=0; i<60; i++) {
    ac2.MinButton();
  }
  ac2.DisplayTime();   // Expect 1:01
  ac2.DisplayAmPm();   // Expect AM
  
  // Regular clock time should be unchanged while we've been setting the alarm time.
  ac2.AlarmButton();
  ac2.DisplayTime();   // Expect 03:33
  ac2.DisplayAmPm();   // Expect PM

  ac2.AlarmButton();
  for (int i=0; i<478; i++) {
    ac2.MinButton();
  }
  ac2.DisplayTime();   // Expect 1:59
  ac2.DisplayAmPm();   // Expect AM

  ac2.MinButton();
  ac2.DisplayTime();   // Expect 1:00
  ac2.DisplayAmPm();   // Expect AM

  ac2.MinButton();
  ac2.DisplayTime();   // Expect 1:01
  ac2.DisplayAmPm();   // Expect AM

  for (int i=0; i<118; i++) {
    ac2.MinButton();
  }
  ac2.DisplayTime();   // Expect 1:59
  ac2.DisplayAmPm();   // Expect AM 

  ac2.MinButton();
  ac2.DisplayTime();   // Expect 1:00
  ac2.DisplayAmPm();   // Expect AM

  for (int i=0; i<9; i++) {
    ac2.HourButton();
  }
  ac2.DisplayTime();   // Expect 10:00
  ac2.DisplayAmPm();   // Expect AM

  ac2.HourButton();
  ac2.DisplayTime();   // Expect 11:00
  ac2.DisplayAmPm();   // Expect AM

  ac2.HourButton();
  ac2.HourButton();
  ac2.DisplayTime();   // Expect 1:00
  ac2.DisplayAmPm();   // Expect PM

  ac2.HourButton();
  ac2.HourButton();
  ac2.DisplayTime();   // Expect 3:00
  ac2.DisplayAmPm();   // Expect PM

  for (int i=0; i<719; i++) {
    ac2.MinButton();
  }
  ac2.DisplayTime();   // Expect 3:59
  ac2.DisplayAmPm();   // Expect PM

  // Regular clock time should be unchanged while we've been setting the alarm time.
  ac2.AlarmButton();
  ac2.DisplayTime();   // Expect 03:33
  ac2.DisplayAmPm();   // Expect PM

  ac2.AlarmButton();
  ac2.MinButton();
  ac2.DisplayTime();   // Expect 3:00
  ac2.DisplayAmPm();   // Expect PM

  std::cout << std::endl << "Testing out a clock with the 3rd constructor." << std::endl;
  AlarmClock ac3 = AlarmClock(10, 59, true, 11, 59, true);
  ac3.DisplayTime();   // Expect 10:59
  ac3.DisplayAmPm();   // Expect PM
  

  ac3.AlarmButton();
  ac3.DisplayTime();   // Expect 11:59
  ac3.DisplayAmPm();   // Expect PM 
  
  std::cout << std::endl << "Testing out alarm features." << std::endl;
  ac3.AlarmSwitch();   // Alarm should be set on now.
  ac3.DisplayAlarmSet();  // Expect Alarm is ON

  ac3.AdvanceMinute();
  ac3.DisplayTime();   // Expect 11:59
  ac3.DisplayAmPm();   // Expect PM

  ac3.AlarmButton();
  ac3.DisplayTime();   // Expect 11:00
  ac3.DisplayAmPm();   // Expect PM
  
  for (int i=0; i<58; i++) {
    ac3.AdvanceMinute();
  }

  ac3.DisplayTime();   // Expect 11:58
  ac3.DisplayAmPm();   // Expect PM

  ac3.AdvanceMinute();
  ac3.DisplayTime();   // Expect 11:59 BEEP BEEP BEEP
  ac3.DisplayAmPm();   // Expect PM BEEP BEEP BEEP
  
  ac3.AdvanceMinute();
  ac3.DisplayTime();   // Expect 12:00 BEEP BEEP BEEP
  ac3.DisplayAmPm();   // Expect AM BEEP BEEP BEEP

  ac3.AdvanceMinute();
  ac3.DisplayTime();   // Expect 12:01 BEEP BEEP BEEP
  ac3.DisplayAmPm();   // Expect AM BEEP BEEP BEEP

  for (int i=0; i<23; i++) {
    for (int j=0; j<60; j++) {
      ac3.AdvanceMinute();
    }
    ac3.DisplayTime();   // Clock should loop around every hour back to 11:01 PM
    ac3.DisplayAmPm();   // BEEP BEEP BEEPing every time.
  }
  
  for (int i=0; i<60; i++) {
    ac3.AdvanceMinute();
  }
  ac3.DisplayTime();   // Expect 12:01 BEEP BEEP BEEP
  ac3.DisplayAmPm();   // Expect AM BEEP BEEP BEEP
  
  // (FUTURE INFORMATION) If isAlarmGoingOff is true, set a new temporary timer that adds 5 mintues to the temporary timer, and create an if statement that can change the isAlarmGoingOff to false.

  // Alarm time should sitll be set to 11:59 PM, as that was when the alarm went off initially
  ac3.AlarmButton();   
  ac3.DisplayTime();   // Expect 11:59 BEEP BEEP BEEP
  ac3.DisplayAmPm();   // Expect PM BEEP BEEP BEEP

  std::cout << std::endl << "Testing the snooze button." << std::endl;

  ac3.SnoozeButton();
  ac3.AlarmButton();
  ac3.DisplayTime();   // Expect 12:01
  ac3.DisplayAmPm();   // Expect AM
  ac3.DisplayAlarmSet();  // Expect Alarm is ON

  for (int i=0; i<4; i++) {
    ac3.AdvanceMinute();
    ac3.DisplayTime();   // Alarm should not sound for 4 minutes
    ac3.DisplayAmPm();
  }
  
  ac3.AdvanceMinute();
  ac3.DisplayTime();   // Expect 12:06 BEEP BEEP BEEP
  ac3.DisplayAmPm();   // Expect AM BEEP BEEP BEEP
  ac3.DisplayAlarmSet();  // Expect Alarm is ON BEEP BEEP BEEP

  ac3.AdvanceMinute();
  ac3.DisplayTime();   // Expect 12:07 BEEP BEEP BEEP
  ac3.DisplayAmPm();   // Expect AM BEEP BEEP BEEP
  ac3.DisplayAlarmSet();  // Expect Alarm is ON BEEP BEEP BEEP

  ac3.SnoozeButton();
  ac3.DisplayTime();   // Expect 12:07
  ac3.DisplayAmPm();   // Expect AM
  ac3.DisplayAlarmSet();  // Expect Alarm is ON

  for (int i=0; i<4; i++) {
    ac3.AdvanceMinute();  // Re-snoozing a snoozed alarm should not change the snooze timer.
    ac3.DisplayTime();   
    ac3.DisplayAmPm();
    ac3.DisplayAlarmSet();  // Expect Alarm is ON
    ac3.SnoozeButton();
  }

  ac3.AdvanceMinute();
  ac3.DisplayTime();   // Expect 12:12 BEEP BEEP BEEP
  ac3.DisplayAmPm();   // Expect AM BEEP BEEP BEEP
  ac3.DisplayAlarmSet();  // Expect Alarm is ON BEEP BEEP BEEP
  
  ac3.SnoozeButton();  // Snoozing again, to check that it won't sound again even if alarm is turned off.
  ac3.DisplayTime();   // Expect 12:12
  ac3.DisplayAmPm();   // Expect AM
  ac3.DisplayAlarmSet();  // Expect Alarm is ON

  ac3.AlarmSwitch();
  ac3.DisplayAlarmSet();  // Expect Alarm is OFF

   for (int i=0; i<10; i++) {
    ac3.AdvanceMinute();
    ac3.DisplayTime();   // Alarm should not sound again
    ac3.DisplayAmPm();
  }

  ac3.AlarmButton();   // Alarm should still be set for 11:59 PM tomorrow.
  ac3.DisplayTime();   // Expect 11:59
  ac3.DisplayAmPm();   // Expect PM
  ac3.DisplayAlarmSet();  // Expect Alarm is OFF

  ac3.AlarmSwitch();
  ac3.DisplayTime();   // Expect 11:59
  ac3.DisplayAmPm();   // Expect PM
  ac3.DisplayAlarmSet();  // Expect Alarm is ON

  ac3.AlarmButton();
  ac3.DisplayTime();   // Expect 12:22
  ac3.DisplayAmPm();   // Expect AM

  ac3.AdvanceMinute();
  ac3.DisplayTime();   // Expect 12:23
  ac3.DisplayAmPm();   // Expect AM
  
  for (int i=0; i<1415; i++) {
    ac3.AdvanceMinute();
  }

  ac3.DisplayTime();   // Expect 11:58
  ac3.DisplayAmPm();   // Expect PM

  ac3.AdvanceMinute();
  ac3.DisplayTime();   // Expect 11:59 BEEP BEEP BEEP
  ac3.DisplayAmPm();   // Expect PM BEEP BEEP BEEP
}
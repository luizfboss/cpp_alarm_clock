#include <iostream>

#include <iomanip> // This will help the time formatting to work properly
 
#include "alarm_clock.h"

// Default Constructor - it sets the current hours and minutes to midnight as default.
AlarmClock::AlarmClock(){
  AlarmClock::curr_hours_ = 12;
  AlarmClock::curr_minutes_ = 0;
  AlarmClock::curr_isPM_ = false;

  // The other attributes are set to a "default setting", so they can be used in the future.
  AlarmClock::alarm_hours_ = 12;
  AlarmClock::alarm_minutes_ = 0;
  AlarmClock::isAlarmSettingOn_ = false;
  AlarmClock::isAlarmOn_ = false;
  AlarmClock::alarm_isPM_ = false;
}

// Constructor that takes three parameters:
// parameter 1 - hour for current time
// parameter 2 - minutes for current time
// parameter 3 - a boolean value that indicates whether the current time is AM/PM
AlarmClock::AlarmClock(int hour, int minute, bool curr_isPM){
  AlarmClock::curr_hours_ = hour;
  AlarmClock::curr_minutes_ = minute;
  AlarmClock::curr_isPM_ = curr_isPM;

  // The other attributes are set to a "default setting", so they can be used in the future.
  AlarmClock::alarm_hours_ = 12;
  AlarmClock::alarm_minutes_ = 0;
  AlarmClock::isAlarmSettingOn_ = false;
  AlarmClock::isAlarmOn_ = false;
  AlarmClock::alarm_isPM_ = false;
}

// Constructor that takes six parameters:
// parameter 1 - hour for current time
// parameter 2 - minutes for current time
// parameter 3 - a boolean value that indicates whether the current time is AM/PM
// parameter 4 - hour for alarm time
// parameter 5 - minutes for alarm time
// parameter 6 - a boolean value that indicates whether the alarm time is AM/PM
AlarmClock::AlarmClock(int hour, int minute, bool curr_isPM, int alarm_hour, int alarm_minute, bool alarm_isPM){
  // Setting clock's properties
  AlarmClock::curr_hours_ = hour;
  AlarmClock::curr_minutes_ = minute;
  AlarmClock::curr_isPM_ = curr_isPM;

  // Setting alarm properties
  AlarmClock::alarm_hours_ = alarm_hour;
  AlarmClock::alarm_minutes_ = alarm_minute;
  AlarmClock::alarm_isPM_ = alarm_isPM;
  AlarmClock::isAlarmOn_ = false;
}

// Destructor for the constructors
AlarmClock::~AlarmClock(){
  
}

// This helper method checks whether the alarm has been triggered or not. This will help the Snooze function to work better.
void AlarmClock::AlarmGoingOff(){
  // if the alarm is not on, this function does nothing. 
  if(!isAlarmOn_){
    return;
  }

  // if the alarm and current hours match, and the alarm is on, and the alarm is going off, OR the current hours match with the temporary hours for the snooze button, the alarm will be triggered.
  else if(((AlarmClock::curr_hours_ == AlarmClock::alarm_hours_) && (AlarmClock::curr_minutes_ == AlarmClock::alarm_minutes_) && AlarmClock::isAlarmOn_) || isAlarmGoingOff_ || ((AlarmClock::curr_hours_ == AlarmClock::temp_hours_) && (AlarmClock::curr_minutes_ == AlarmClock::temp_minutes_))){
    // Setting isAlarmGoingOff_ to true, if false;
    isAlarmGoingOff_ = true;
    isSnoozed_ = false;
    // "Triggering" the alarm
    std::cout << "BEEP BEEP BEEP" << std::endl;
  }

  // Setting the boolean value that controls the alarm to be triggered to true if the current time matches with the temporary time.
  if((AlarmClock::curr_hours_ == AlarmClock::temp_hours_) && (AlarmClock::curr_minutes_ == AlarmClock::temp_minutes_)){
    isAlarmGoingOff_ = true;
  }
}

// This method switches the alarm status. 
void AlarmClock::AlarmSwitch(){
  // Switching the Alarm Status.
  AlarmClock::isAlarmOn_ = !AlarmClock::isAlarmOn_;
  AlarmClock::isAlarmGoingOff_ = !AlarmClock::isAlarmGoingOff_;

  // Switching the Snooze Status, if active.
  if(AlarmClock::isSnoozed_){
    AlarmClock::isSnoozed_ = !AlarmClock::isSnoozed_;
  }
}

// A method that enables the user to change the current time
void AlarmClock::TimeButton(){
  // Setting the "Alarm Setting" to false, if it is on, so both settings are not active at the same time.
  if(AlarmClock::isAlarmSettingOn_){
    AlarmClock::isAlarmSettingOn_ = false;
  }
  
  // Changing the "time setting" status
  AlarmClock::isTimeSettingOn_ = !isTimeSettingOn_;
}

// A method that enables the user to change the alarm time
void AlarmClock::AlarmButton(){
  // Setting the "Time Setting" to false, if it is on, so both settings are not active at the same time.
  AlarmClock::isTimeSettingOn_ = false;
  
  // Changing the "alarm setting" status
  AlarmClock::isAlarmSettingOn_ = !isAlarmSettingOn_;
}

// Changing the current or alarm minute value, depending on which boolean value is true. 
void AlarmClock::MinButton(){
  // If the time setting mode is on, it will change the current time in the clock
  if(AlarmClock::isTimeSettingOn_){
    AlarmClock::curr_minutes_++;
    
    // If the minutes reach 60, it resets the value to 0.
    if(AlarmClock::curr_minutes_ == 60){
      AlarmClock::curr_minutes_ = 0;
    }
  }

  // If the alarm setting mode is on, it will change the alarm time
  if(AlarmClock::isAlarmSettingOn_){
    AlarmClock::alarm_minutes_++;
    
    // If the minutes reach 60, it resets the value to 0.
    if(AlarmClock::alarm_minutes_ == 60){
      AlarmClock::alarm_minutes_ = 0;
    }
  }
}

// Changing the current or alarm hour value, depending on which boolean value is true. 
void AlarmClock::HourButton(){
  // If the time setting mode is on, it will change the time in the clock
  if(AlarmClock::isTimeSettingOn_){
    AlarmClock::curr_hours_++;
    
    // Checking whether the AM/PM status should change
    if(AlarmClock::curr_hours_ == 12){
      AlarmClock::curr_isPM_ = !AlarmClock::curr_isPM_;
    }

    // If the number of hours goes over 12, it subtracts 12 
    // from the current value
    if(AlarmClock::curr_hours_ > 12){
      AlarmClock::curr_hours_ -= 12;
    }
  }

  // If the alarm setting mode is on, it will change the alarm time
  if(AlarmClock::isAlarmSettingOn_){
    AlarmClock::alarm_hours_++;

    // Checking whether the AM/PM status should change
    if(AlarmClock::alarm_hours_ == 12){
      AlarmClock::alarm_isPM_ = !AlarmClock::alarm_isPM_;
    }
    
    // If the number of hours goes over 12, it subtracts 12 
    // from the alarm value
    if(AlarmClock::alarm_hours_ > 12){
      AlarmClock::alarm_hours_ -= 12;
    }
  }
}

// The snooze method. This method helps the user to trigger the alarm 5 minutes after the method is called
void AlarmClock::SnoozeButton(){
  // This function will only work if the alarm is on.
  if(isAlarmOn_ == true){
    isSnoozed_ = true;
    isAlarmGoingOff_ = false;
    // Storing the current time in the temporary variables, so the 
    // snooze function can work properly, without changing the actual 
    // clock time 
    AlarmClock::temp_hours_ = AlarmClock::curr_hours_;
    AlarmClock::temp_minutes_ = AlarmClock::curr_minutes_;

    // Adding 5 minutes to the temprary time. This can be done because of an if 
    // statement located in AdvancedMinute().
    for(int i = 0; i < 5; i++){
      AdvanceMinute();
    }
    isSnoozed_ = false;
  }
}

// This method displays the time based on what setting is active. If the active setting is 
// "time setting", this function will display the current time. If the active setting is 
// "alarm setting", this will show the alarm time that was set by the user.
void AlarmClock::DisplayTime(){
  // Showing the alarm time if the time setting mode is on
  if(AlarmClock::isTimeSettingOn_ || !AlarmClock::isAlarmSettingOn_){
    // Showing the time with proper formatting, with the help of std::setfill and std::setw
    std::cout << std::setfill('0') << std::setw(2) << curr_hours_ << ":" << std::setfill('0') << std::setw(2) << curr_minutes_ << " " << std::endl;
  }

  // Showing the alarm time if the alarm setting mode is on
  else if(AlarmClock::isAlarmSettingOn_ || !AlarmClock::isTimeSettingOn_){
    // Showing the alarm time with proper formatting, with the help of std::setfill and std::setw
    std::cout << std::setfill('0') << std::setw(2) << AlarmClock::alarm_hours_ << ":" << std::setfill('0') << std::setw(2) << AlarmClock::alarm_minutes_ << " ";
    
    // Ending the line so the next action can be shown in the line below
    std::cout << std::endl;
  }
  // Calling AlarmGoingOff() so the Snooze method works properly
  AlarmGoingOff();
}

// A method that displays the AM/PM status, based on the boolean values related to 
// the current time and alarm time. 
void AlarmClock::DisplayAmPm(){
  // Displaying the alarm AM/PM status if the current "mode" is "time mode", or if the 
  // "alarm mode" is disabled.
  if(AlarmClock::isTimeSettingOn_ || !AlarmClock::isAlarmSettingOn_){
    if(AlarmClock::curr_isPM_){
      std::cout << "PM ";
    }
    else{
      std::cout << "AM ";
    }
  }

  // Displaying the alarm AM/PM status if the current "mode" is "alarm mode", or if the 
  // "time mode" is disabled.
  else if(AlarmClock::isAlarmSettingOn_ || !AlarmClock::isTimeSettingOn_){
    if(AlarmClock::alarm_isPM_){
      std::cout << "PM ";
    }
    else{
      std::cout << "AM ";
    }
  }

  // Ending the line for formatting purposes
  std::cout << std::endl;
  // Calling this function for the Snooze method to work
  AlarmGoingOff();
}

// A method that displays the alarm set, if it is on or off, based on the boolean attribute isAlarmOn_.
void AlarmClock::DisplayAlarmSet(){
  if(AlarmClock::isAlarmOn_){
    std::cout <<  "Alarm is ON " << std::endl;
  } else {
    std::cout <<  "Alarm is OFF " << std::endl;
  }

  // Calling this function for the Snooze method to work
  AlarmGoingOff();
}

// A method that advances the clock by one minute
void AlarmClock::AdvanceMinute(){
  // This makes the AdvanceMinute() call in the Snooze function to work (comment from line 187). 
  if(isSnoozed_){
    AlarmClock::temp_minutes_++;
  }
  else {
    AlarmClock::curr_minutes_++;
  }
  
  // Changing bool value of AM/PM, if current time == 11:59 AM, or 11:59 PM.
  // For example, if the current time is 11:59 AM, after calling 
  // this function, the current time will change to 12:00 PM, and vice-versa.
  if(AlarmClock::curr_hours_ == 11 && AlarmClock::curr_minutes_ == 60){
    AlarmClock::curr_isPM_ = !AlarmClock::curr_isPM_; 
  }
  // Adding 1 to the current hours variable if the minutes go over 60.
  if(AlarmClock::curr_minutes_ >= 60){
    curr_hours_++;
    curr_minutes_ %= 60;
  }

  // Changing bool value of AM/PM, if alarm time == 11:59 AM, or 11:59 PM.
  // For example, if the alarm time is 11:59 AM, after calling 
  // this function, the alarm time will change to 12:00 PM, and vice-versa.
  if(AlarmClock::alarm_hours_ == 11 && AlarmClock::alarm_minutes_ == 60){
    AlarmClock::alarm_isPM_ = !AlarmClock::alarm_isPM_; 
  }
  // Adding 1 to the alarm hours variable if the minutes go over 60.
  if(AlarmClock::alarm_minutes_ >= 60){
    alarm_hours_++;
    alarm_minutes_ %= 60;
  }

  // Subtracting 12from the hours variable if the hours go over 12.
  if(AlarmClock::alarm_hours_ > 12){
    AlarmClock::alarm_hours_ -= 12;
  }
  if(AlarmClock::curr_hours_ > 12){
    AlarmClock::curr_hours_ -= 12;
  }
}

#ifndef ALARM_CLOCK_H_
#define ALARM_CLOCK_H_

// Definition of the AlarmClock class
class AlarmClock {
  public:
    // Constructors and destructors
    AlarmClock();
    AlarmClock(int hour, int minute, bool isPM);
    AlarmClock(int hour, int minute, bool isPM, int alarm_hour, int alarm_minute, bool alarm_isPM);
    ~AlarmClock();

    // Methods
    void AlarmSwitch();
    void TimeButton();
    void AlarmButton();
    void MinButton();
    void HourButton();
    void SnoozeButton();
    void DisplayTime();
    void DisplayAmPm();
    void DisplayAlarmSet();
    void AdvanceMinute();

  private:
    // Attributes
    int curr_hours_;
    int curr_minutes_;
    bool curr_isPM_;

    int alarm_hours_;
    int alarm_minutes_;
    bool alarm_isPM_;

    bool isAlarmOn_;
    bool isAlarmGoingOff_;
    bool isSnoozed_;

    // Specific variables for snooze
    int temp_hours_;
    int temp_minutes_;

    // Modes
    bool isTimeSettingOn_ = true;
    bool isAlarmSettingOn_ = false;

    // Helper method
    void AlarmGoingOff();
};

#endif
/* SimpleTimer.h */
/* Aaron McNiven - 2019 */

#ifndef SimpleTimer_h
#define SimpleTimer_h

#include "Arduino.h"

class SimpleTimer {
  private:
    long m_duration;
    long m_value;
    bool m_expired;
    bool m_disabled;
    bool m_set;
    
  public:
    SimpleTimer();
    SimpleTimer(long duration);
    void setDuration(long duration);
    void update();
    void reset();
    void start();
    void stop();
    bool expired();
};

#endif

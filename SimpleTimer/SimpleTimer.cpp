/* SimpleTimer.cpp */
/* Aaron McNiven - 2019 */

#include "Arduino.h"
#include "SimpleTimer.h"

SimpleTimer::SimpleTimer() {
  m_expired = false;
  m_disabled = true;
  m_set = false;
}

SimpleTimer::SimpleTimer(long duration) {
  setDuration(duration);
}

void SimpleTimer::setDuration(long duration) {
  m_duration = duration;
  m_disabled = false;
  m_set = true;
  reset();
}

void SimpleTimer::update() {
  if(millis() > m_value) {
    m_expired = true;
  }
}

void SimpleTimer::reset() {
  m_expired = false;
  m_value = millis() + m_duration;
}

void SimpleTimer::start() {
  if(m_disabled) {
    m_disabled = false;
    reset();
  }
}

void SimpleTimer::stop() {
  m_disabled = true;
}

bool SimpleTimer::expired() {
  if(m_expired && !m_disabled && m_set) {
    reset();
    return true;
  }
  return false;
}


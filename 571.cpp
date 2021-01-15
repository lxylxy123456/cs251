Lock::acquire() { disableInterrupts(); }
Lock::release() { enableInterrupts(); }

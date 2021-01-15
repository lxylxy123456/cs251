Lock::acquire() {
	spinLock.acquire();
	if (value != FREE) {
		waiting.add(runningThread);
		spinLock.release();
		scheduler.suspend(&spinLock);
	} else {
		value = BUSY;
		spinLock.release();
	}
}
Lock::release() {
	TCB *next;
	spinLock.acquire();
	if (waiting.notEmpty()) {
		next = waiting.remove();
		scheduler.makeReady(next);
	} else {
		value = FREE;
	}
	spinLock.release();
}


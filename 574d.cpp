Scheduler::suspend(SpinLock *lock) {
	TCB *chosenTCB;
	disableInterrupts();
	schedulerSpinLock.acquire();
	// lock->release();
	runningThread->state = WAITING;
	chosenTCB = readyList.getNextThread();
	thread_switch(runningThread,
		          chosenTCB);
	runningThread->state = RUNNING;
	schedulerSpinLock.release();
	enableInterrupts();
}

Scheduler::makeReady(TCB *thread) {
	disableInterrupts();
	schedulerSpinLock.acquire();
	readyList.add(thread);
	thread->state = READY;
	schedulerSpinLock.release();
	enableInterrupts();
}


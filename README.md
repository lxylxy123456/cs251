# ECS 251 Presentation

## Slides
[pdf](Presentation.pdf) / [LaTeX source](Presentation.tex)

## Video
* on [AggieVideo (UC Davis)](https://video.ucdavis.edu/media/Implementing+Synchronization+Objects+-+Eric+Li+ECS+251+Presentation/1_x032w5ld)
* on [YouTube](http://www.youtube.com/watch?v=vFygLeyNd1o)

[![Youtube Presentation Video](http://img.youtube.com/vi/xtCWZYDGeAk/0.jpg)](http://www.youtube.com/watch?v=xtCWZYDGeAk)

## Quizzes

### Quiz question 1
What goes wrong in the following program, if implemented in a Real Time Operating System on uniprocessor system?
* A. Race condition
* B. Dead lock
* C. Starvation
* D. Nothing wrong

```
class Lock {
  private:
    int value = FREE;
    Queue waiting;
  public:
    void acquire();
    void release();
}

Lock::acquire() {
    TCB *chosenTCB;

    disableInterrupts();
    if (value == BUSY) {
        waiting.add(runningThread);
        runningThread->state = WAITING;
        chosenTCB = readyList.remove();
        thread_switch(runningThread,
                      chosenTCB);
        runningThread->state = RUNNING;
        value = BUSY;
    } else {
        value = BUSY;
    }
    enableInterrupts();
}

Lock::release() {
    TCB *next;

    disableInterrupts();
    if (waiting.notEmpty()) {
        next = waiting.remove();
        next->state = READY;
        readyList.add(next);
        value = FREE;
    } else {
        value = FREE;
    }
    enableInterrupts();
}
```

### Quiz question 2
Do uni- or multi-processor implementation of queuing locks discussed in this presentation ("Implementing Synchronization Objects" by Eric Li) use disabling interrupts / atomic instructions?
* uniprocessor _______ disabling interrupts
* uniprocessor _______ atomic instructions
* multiprocessor _______ disabling interrupts
* multiprocessor _______ atomic instructions

Choices for all blanks: "uses" / "does not use"

### Quiz answers
Enter the following into bash
```sh
echo Q29ycmVjdCBhbnN3ZXIgZm9yIHF1ZXN0aW9uIDE6IEMKQ29ycmVjdCBhbnN3ZXIgZm9yIHF1ZXN0aW9uIDI6IHVzZXM7IGRvZXMgbm90IHVzZTsgdXNlczsgdXNlcwo= | base64 -d
```

## Furthre reading
https://people.freebsd.org/~lstewart/articles/cpumemory.pdf

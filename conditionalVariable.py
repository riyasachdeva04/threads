from threading import *
import time

cond = Condition()
done = 1

def task(name):
    global done
    with cond:
        if done == 1:
            done = 2
            print("Waiting on conditional variable cond: ", name)
            cond.wait()
            for i in range(5):
                print(i, name)
                time.sleep(1)
            print("Condition met for", name)
        else:
            for i in range(5):
                print('.', name)
                time.sleep(1)
            print("Signalling cond by ", name)
            cond.notify_all()
            print("Notification sent by ", name)

if __name__ == '__main__':
    t1 = Thread(target=task, args=('t1',))
    t2 = Thread(target = task, args = ('t2',))

    t1.start()
    t2.start()

    t1.join()
    t2.join()
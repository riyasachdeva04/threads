from threading import *
import time

sem = Semaphore(3)

def task(name):
    sem.acquire()
    for i in range(5):
        print("{} working".format(name))
        time.sleep(1)
    sem.release()


if __name__ == '__main__':
    t1 = Thread(target=task, args=('Thread1', ))
    t2 = Thread(target=task, args=('Thread2', ))
    t3 = Thread(target=task, args=('Thread3', ))
    t4 = Thread(target=task, args=('Thread4', ))
    t5 = Thread(target=task, args=('Thread5', ))
    t6 = Thread(target=task, args=('Thread6', ))
           
    t1.start()
    t2.start()
    t3.start()
    t4.start()
    t5.start()
    t6.start()
    t1.join()
    t2.join()
    t3.join()
    t4.join()
    t5.join()
    t6.join()
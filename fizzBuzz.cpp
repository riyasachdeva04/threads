class FizzBuzz {
private:
    int n;
    int i;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {

        unique_lock<mutex> lock(m);
        while(i <= n)
        {
            while((i%3 != 0) || (i%5 == 0))
            {
                cv.wait(lock);
            }

            printFizz();
            i++;
            cv.notify_all();
        }
        
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {

        unique_lock<mutex> lock(m);

        while(i <= n)
        {
            while((i%3 == 0) || (i%5 != 0))
            {
                cv.wait(lock);
            }

            printBuzz();
            i++;
            cv.notify_all();
        }
        
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {

        unique_lock<mutex> lock(m);

        while(i <= n)
        {
            while((i%3 != 0) && (i%5 != 0))
            {
                cv.wait(lock);
            }

            printFizzBuzz();
            i++;
            cv.notify_all();
        }
        
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {

        unique_lock<mutex> lock(m);

        while(i <= n)
        {
            while((i%3 == 0) || (i%5 == 0))
            {
                cv.wait(lock);
            }
            printNumber(i);
            i++;
            cv.notify_all();
        }
        
    }
};
class Foo {
    std::mutex m;
    std::condition_variable cv;
    int flag;

public:
    Foo() {
        flag = 0;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        flag = 1;
        cv.notify_all();

    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        std::unique_lock<std::mutex> lock(m);
        while(flag != 1)
        {
            cv.wait(lock);
        }
        printSecond();
        flag = 2;
        cv.notify_all();

    }

    void third(function<void()> printThird) {

        std::unique_lock<std::mutex> lock(m);
        while(flag != 2)
        {
            cv.wait(lock);
        }
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
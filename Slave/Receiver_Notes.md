# Information for Reciever Code
--

## Multithreading
---
### Semaphore
---
Semaphore::aquire() - wait until a resource is released  
Semaphore::release() - release a Semaphore resource  

Official Documentation is [here](https://os.mbed.com/docs/mbed-os/v6.16/apis/semaphore.html)


### Thread
---
Thread::start(mbed::Callback <void()> task) - starts thread running void task function  
Thread::terminate() - terminates thread  
Thread::join() - wait for thread to terminate  
Official Documentation is [here](https://os.mbed.com/docs/mbed-os/v6.16/mbed-os-api-doxy/classrtos_1_1_thread.html#ad315c4f13f31fffde51040cbf00518cb)

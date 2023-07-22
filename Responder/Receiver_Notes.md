# Information for Reciever Code
--
## Fast Fourier Transforms
---
Here is a helpful link that explains how FFTs (Fast Fourier Transforms) work: [link](https://towardsdatascience.com/brief-introduction-of-hamming-and-hanning-function-as-the-preprocessing-of-discrete-fourier-8b87fe538bb7)

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

### When XIAO RP2040 No longer uploads or finds COMs port
---
 Do these Steps:
 1. Open in Bootmode (Hold Boot and Plug in, Hold Boot and press Reset)
 2. Select any COMs port and upload (will fail)
 3. The board should now be assigned a COMs port.
 4. Upload Normally

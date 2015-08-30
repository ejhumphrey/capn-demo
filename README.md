Demonstrate populating a Capn Proto in C++, and checking the data in Python.

In OS X (10.10.3), this code causes the following failure with `powof2 ≈ 12`:

```
Elibc++abi.dylib: terminating with uncaught exception of type kj::ExceptionImpl: src/kj/io.c++:259: failed: miniposix::read(fd, pos, max - pos): Bad file descriptor; fd = 3
stack: 0x10aa0e850 0x10aa12379 0x10aa14a0b 0x10aa140ea 0x10aa137cf 0x10aa135f5 0x10a95e5ea 0x10a95d105 0x10a95ecff 0x10a95efb7 0x10a95f03b 0x10a6a557a 0x10a6bfb7b 0x109d37489 0x109db6cbb 0x109db6ca2
```

# A Capn Proto Example -- C++ into Python
Demonstrate populating a Capn Proto in C++, and checking the data in Python.

In OS X (10.10.3), this simple program succeeds with `num_elements<=3376`, but otherwise fails with the following error:

```
user ~/src/capn-demo $ ./doall 3377
Compiling Capn Proto
Compiling Source
Generating Data
>> Number of elements (exp): 3377
>> Number of elements (act): 3377
Executing Python Test
Traceback (most recent call last):
  File "test_pycapnp.py", line 26, in <module>
    test_reading(args.num_elements)
  File "test_pycapnp.py", line 16, in test_reading
    np.asarray(x.values, dtype=DTYPE),
  File "capnp/lib/capnp.pyx", line 1022, in capnp.lib.capnp._DynamicStructReader.__getattr__ (capnp/lib/capnp.cpp:22190)
capnp.lib.capnp.KjException: src/kj/io.c++:259: failed: miniposix::read(fd, pos, max - pos): Bad file descriptor; fd = 3
stack: 0x1060d1850 0x1060d5379 0x1060d7a0b 0x1060d70ea 0x1060d67cf 0x1060d65f5 0x10602129c 0x1060d64b1 0x106020329 0x10600b751 0x1060133be 0x10603917a 0x10603f123 0x105d100b5 0x105d98f26 0x1059a37c4
libc++abi.dylib: terminating with uncaught exception of type kj::ExceptionImpl: src/kj/io.c++:259: failed: miniposix::read(fd, pos, max - pos): Bad file descriptor; fd = 3
stack: 0x1060d1850 0x1060d5379 0x1060d7a0b 0x1060d70ea 0x1060d67cf 0x1060d65f5 0x1060215ea 0x106020105 0x106021cff 0x106021fb7 0x10602203b 0x105d6857a 0x105d82b7b 0x105947489 0x1059c6cbb 0x1059c6ca2
./doall: line 39: 41586 Abort trap: 6           python test_pycapnp.py ${NUM_ELEMENTS}
```

# Dependencies
You'll need a C++11 capable compiler (this looks for g++), and the following libraries:

* [Capn Proto](https://capnproto.org): via `brew install capnp` on OS X
* [Pycapnp](http://jparyani.github.io/pycapnp/), via `pip install pycapnp`

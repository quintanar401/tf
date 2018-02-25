## C API

Definitions are taken from https://github.com/tensorflow/tensorflow/blob/r1.6/tensorflow/c/c_api.h

To generate Q bindings you need my q2c library. Tensorflow assumes it is in ../../q2c directory, modify the load path if necessary (at the start and at the end of the file). To generate:
```
q tensorflow.q
```
It will produce `tf.c` file.

To compile it run something like (following tensorflow installation instructions):
```
gcc -DKXVER=3 -fPIC -shared -O3 -L/usr/local/lib tf.c -ltensorflow -o tf.so
```

Load:
```
l:`:tf 2: (`tf__init;1); lib:l[];
```

## Operations

To generate operations you need https://github.com/tensorflow/tensorflow/blob/r1.6/tensorflow/core/ops/ops.pbtxt

```
q genops.q ops.pbtxt ops.q
```
It will produce ops.q file.

You actually don't have to use `ops.q`. You may as well save all tables in a binary format. Q file is generated for transparency.

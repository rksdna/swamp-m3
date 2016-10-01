#Swamp

Cooperative multitasking operating system for Cortex-M3 **STM32F1xx** controllers.
See *samples* directory to understand how to use the system.

Building samples:
```
make FILES="samples/source/kernel_sample.c" DIRS="kernel" all
```

Building your application:
```
make TARGET="app" DIRS="app kernel cdc" all
```

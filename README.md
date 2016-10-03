#Swamp

Cooperative multitasking operating system for Cortex-M3 **STM32F1xx** controllers.
See *samples* directory to understand how to use the system.

Building samples:
```
make MODULES="sample kernel" all
make MODULES="sample kernel cdc" all
make MODULES="sample kernel hid" all
```

Clean samples:
```
make MODULES="sample kernel cdc hid" clean
```

Building your application:
```
make MODULES="app kernel" all
```

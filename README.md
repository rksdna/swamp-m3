#Swamp

Cooperative multitasking operating system for Cortex-M3 **STM32F1xx** controllers.
See *sample.c* to understand how to use the system and its modules.

Building samples:
```
make MODULES="sample kernel" all
make MODULES="sample kernel cdc" all
make MODULES="sample kernel hid" all
make MODULES="sample kernel ip" all
```

Clean samples:
```
make MODULES="sample kernel cdc hid ip" clean
```

Building your application:
```
make MODULES="app kernel" all
```

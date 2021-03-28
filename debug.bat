cls
call compile.bat
start cmd /k C:\Users\vedro\Downloads\gdbgui-0.13.2.1\gdbgui-0.13.2.1\downloads\windows\gdbgui_0.13.1.1.exe --args -x gdb.run
qemu-system-i386 -s -S -serial file:serial.log -m 1G -kernel kernel.elf -L "D:\qemu" 
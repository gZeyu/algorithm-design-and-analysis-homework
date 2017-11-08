@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" x64 
set file=%1%    
set compilerflags=/Od /Zi /EHsc
set linkerflags=/OUT:a.exe
cl.exe %compilerflags% %file% /link %linkerflags%
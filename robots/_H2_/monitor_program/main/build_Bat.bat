:://::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:://	modified. 2008-9-26    by  MAZE Jeon you hoon (Edited by Hertz9th leejaeseong 11/04/16)
:://	;Remove all bad messages.
::// 	;Correct wrong code.
::// 	;If it have any error, delete "*.out"  automatically.
::// 	;Add FAIL message when she failed.
:://	;After a successful compile, hex file delete.
:://
:://	;File name : build_Bat.bat                ;tms320f28335
:://::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

:: [::] = //주석
:: [echo.] = //도스창에서 다음줄로 넘어감

@echo off

echo. 
set TARGET= a_varhae_monitor
set COMPILE_PATH= D:\work\_varhae_\monitor_base\cgtools\bin

::set c=
::set /p c=Build All or No All?? (Press a/A or Enter):
echo. 

echo TMS320F28335 Compile start!!
echo.

::clean
%COMPILE_PATH%\make clean
echo. 
echo.

::make
%COMPILE_PATH%\make all
echo. 
echo.

if not exist %TARGET%.out goto error

%COMPILE_PATH%\hex2000 %TARGET%.out -o %TARGET%.hex -map %TARGET%.map -i -datawidth 16 -memwidth 16 -romwidth 16

if exist %TARGET%.hex del %TARGET%.hex

@goto good


:error
@echo off
if exist %TARGET%.out del %TARGET%.out
echo !!!!!!!!FAIL!!!!!!!!
echo.
echo Compile after Debug...
goto nend

:good
@echo off
echo.
echo.

goto end

:end
echo.
echo Thanks to Jeon yu hoon

:nend

@echo on


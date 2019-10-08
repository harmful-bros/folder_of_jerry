:://::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:://  modified. 2008-9-26    by  MAZE Jeon you hoon (Edited by Hertz9th leejaeseong 10/02/12)
:://   ;Remove all bad messages.
:://   ;Correct wrong code.
:://   ;If it have any error, delete "*.hex"  automatically.
:://   ;Add FAIL message when she failed.
:://
:://  ;File name : build_Bat.bat                ;tms320f28335
:://::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

:: [::] = //주석
:: [echo.] = //도스창에서 다음줄로 넘어감

@echo off

echo. 
set TARGET= a_H2
set COMPILE_PATH= D:\work\_H2_\user\cgtools\bin

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

if exist %TARGET%.hex del %TARGET%.out	

if not exist %TARGET%.hex goto error

@goto good


:error
@echo off
if exist %TARGET%.hex del %TARGET%.hex
echo !!!!!!!!FAIL!!!!!!!!
echo.
echo Compile after Debug...
goto nend

:good
@echo off
echo.
echo.
echo !!!! 2012 micro mouse =H2= source compile complete !!!!
goto end

:end
echo.
echo Thanks to Jeon yu hoon

:nend

@echo on


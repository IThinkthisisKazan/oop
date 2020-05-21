@echo off

SET Program="%~1"
set SuccessfulTests=0

if %Program%=="" (
	echo Please specify path to program dec2bin.exe
	exit /B 1
)

echo Running Tests...

REM �������� ������� ���������
%Program% "" && goto err
echo Test 'without args' successful
set /A successful+=1

REM �������� ����
%Program% "0" || goto err
fc "tests\comparison\2.txt" "tests\example.txt" || goto err
echo Test 'without zero' successful
set /A successful+=1

REM �������� 213
%Program% "213" || goto err
fc "tests\comparison\1.txt" "tests\example.txt" || goto err
echo Test '213 test ' successful
rem echo. > "tests\example.txt"
set /A successful+=1

REM �������� 100
%Program% "100" || goto err
fc "tests\comparison\3.txt" "tests\example.txt" || goto err
echo Test '213 test ' successful
rem echo. > "tests\example.txt"
set /A successful+=1


REM Tests passed successfully
echo Tests passed: %successful%/4
echo All tests successful
exit /B 0

REM Test failed
:err
echo Test failed!
rem exit /B 1
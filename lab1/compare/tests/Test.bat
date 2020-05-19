echo hello world
@echo off

SET Program="%~1"
set SuccessfulTests=0

if %Program%=="" (
	echo Please specify path to program compare.exe
	exit /B 1
)

echo Running Tests...

rem check input1 
%Program% "" "tests\data2\input2.txt" "%TMP%\output.txt" > nul && goto err
echo Test 'input1 not provided' successful
set /A successful+=1

rem  check input2
%Program% "tests\data1\input1.txt" "" "%TMP%\output.txt" > nul && goto err
echo Test 'input2 not provided' successful
set /A successful+=1

rem  checking both files
%Program% "" "" "%TMP%\output.txt" > nul && goto err
echo Test 'both input file not provided' successful
set /A successful+=1

rem check without arguments
%Program% > nul && goto err
echo Test 'without arguments not work' successful
set /A successful+=1

rem equal
%Program% "tests\data1\input1.txt" "tests\data2\input1.txt" || goto err
rem fc "tests\data1\input2.txt" "tests\data2\input2.txt" || goto err
echo 1)Test 'equal file' successful
set /A successful+=1

rem not equal
%Program% "tests\data1\input2.txt" "tests\data2\input2.txt" || goto err
echo 2)Test 'not equal file' successful
set /A successful+=1

rem empty files
%Program% "tests\data1\input3.txt" "tests\data2\input3.txt" || goto err
echo 3)Test 'empty files' successful
set /A successful+=1

REM Tests passed successfully
echo Tests passed: %successful%/8
echo All tests successful
exit /B 0

REM Test failed
:err
echo Test failed!
exit /B 1
@echo OFF
setlocal EnableDelayedExpansion


rem -------------------------------------- Data and Constant ---------------------------------
echo %CD%
set temp_path=%CD%

set num=0
set num1=0
set num2=0

echo -------------------------------------------------------------------------------------------------------------
echo -------------------------------------- Container Generate file  ---------------------------------------------


rem ------------------------  - Choose Sandboxes Link ------------------------------------
set /p sandboxes1= Your sandboxes : 
rem get in the sandboxes
cd \
cd %sandboxes1%
rem ----------------------------------------------------------------------------------



rem --------------------------- Before Start ------------------------------------
echo Please delete all release .hex file - Dflash .hex file on previous CP
echo Example : 
echo           Delete "DF1205_C5_0010_BB101049_Cat5_dflash.hex"
echo           Delete "DF1205_C5_0010_BB101049_Cat5.hex"
pause
rem ----------------------------------------------------------------------------------




rem ---------------------------- Change Folder Name of Release Result -----------------------------
echo ...
echo ...

set /p option="Do you want to build the Software: [y]/[n]" 

for /d %%a in (*) do (
    rem If consist folder result_cat5 on previous CP
    if %%a==results_cat5 (
        set /a num= 1
    )
)

if !num!==1 (
    echo Delete "results_cat5"
    del results_cat5
    move results\* results_cat5
) else (
    echo Rename "results" to "results_cat5"
    rename results results_cat5
)
rem ------------------------------------------------------------------------------------------



rem ----------------------------Clear Result - Generated -----------------------------
del %sandboxes1%\generated
rem /f Clear read only file  --- /s Asking each file before clear
rem del /f %sandboxes1%\results
rem ----------------------------------------------------------------------------------



rem --------------------------------------- Build SW ---------------------------------
echo -------------------- Clean Results ------------------------------
echo -----------------------------------------------------------------
ab12 -t clean

echo -------------------- Build SW -----------------------------------
echo -----------------------------------------------------------------
ab12 -nm -j=8
rem ----------------------------------------------------------------------------------



rem -------------------------------------------- Report Generate ---------------------------------------
set /p select= Do you want to generate the report ? [y]/[n] 

if %select%==y (
    echo -------------------- Report Gen ------------------------------
    resources mem report
)
rem ----------------------------------------------------------------------------------


rem -------------------------------------------- Meger file creation ---------------------------------------
echo ---------------------- Merge file create ------------------------
echo -----------------------------------------------------------------

cd results
for /f %%a in ('dir /B /S *.hex') do (
    set /a num1=!num1! + 1
    @REM echo %%a
    if !num1!==3 (
        set path_dflash=!%%a!
    )
)

cd ..
for /f %%g in ('dir /B *.hex') do (
    echo %%g
    if %%g==sector_0.hex (
        echo ...............
    ) else (
        del %%g
    )   
)

cd results_cat5
for /f %%i in ('dir /B /S *.hex') do (
    set /a num2=!num2! + 1
    @REM echo %%i
    if !num2!==1 (
        set path_rom=!%%i!
    )
)

@REM echo %path_dflash%
@REM echo %path_rom%

cd ..
mergermx --input C:/%path_rom% --input C:/%path_dflash% --output merge.hex
rem ---------------------------------------------------------------------------------------------------------



rem -------------------------------------------- Folder creation ---------------------------------------
echo -------------------- Folder Container create --------------------
echo -----------------------------------------------------------------
cd \ 
cd %temp_path%
python Main.py %sandboxes1%
rem ---------------------------------------------------------------------------------------------------------




echo -------------------------------------- Created by OVT81HC - EPS23  ------------------------------------------
echo -------------------------------------------------------------------------------------------------------------

pause
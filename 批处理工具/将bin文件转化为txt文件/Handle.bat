for %%i in (*.bin) do (
echo "%%i"
CP02_Splitter.exe  %%i  %%~ni.txt
)

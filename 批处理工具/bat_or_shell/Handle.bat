for %%i in (*.bin) do (
echo "%%i"
CP02_Splitter.exe  %%i  %%~ni.txt
)
echo "用程序CP02_Splitter.exe对所有的 *.bin  文件做处理 ，生成同样文件名的*.txt文件"
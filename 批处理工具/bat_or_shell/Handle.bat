for %%i in (*.bin) do (
echo "%%i"
CP02_Splitter.exe  %%i  %%~ni.txt
)
echo "�ó���CP02_Splitter.exe�����е� *.bin  �ļ������� ������ͬ���ļ�����*.txt�ļ�"
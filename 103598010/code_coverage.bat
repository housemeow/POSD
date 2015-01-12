REM rmdir CppCoverageReport-ProductionCode /s /q
REM OpenCppCoverage.exe --source 103598010_MindMap --output CppCoverageReport-ProductionCode --excluded_sources 103598010_Test -- Debug\103598010_Test.exe 
REM start CppCoverageReport-ProductionCode/index.html


REM rmdir CppCoverageReport-TestCode /s /q
REM OpenCppCoverage.exe --source MindMapTest --output CppCoverageReport-TestCode -- Debug\MindMapTest.exe
REM start CppCoverageReport-TestCode/index.html


REM rmdir CppCoverageReport-ProductionCode /s /q
REM OpenCppCoverage.exe --source mindmap --output CppCoverageReport-ProductionCode --excluded_sources mindmaptest -- Debug\MindMapTest.exe 
REM start CppCoverageReport-ProductionCode/index.html






REM rmdir CppCoverageReport-TestCode /s /q
REM OpenCppCoverage.exe --source 103598010_Test --output CppCoverageReport-TestCode -- Debug\103598010_Test.exe
REM start CppCoverageReport-TestCode/index.html


rmdir CppCoverageReport-ProductionCode /s /q
OpenCppCoverage.exe --source 103598010_MindMap --output CppCoverageReport-ProductionCode --excluded_sources 103598010_Test -- Debug\103598010_Test.exe 
start CppCoverageReport-ProductionCode/index.html




rmdir CppCoverageReport-ProductionCode /s /q
OpenCppCoverage.exe --source 103598010_MindMap --output CppCoverageReport-ProductionCode --excluded_sources 103598010_Test -- Debug\103598010_Test.exe 
start CppCoverageReport-ProductionCode/index.html
cmake_minimum_required(VERSION 3.22)
project(CPlusPlus)

set(CMAKE_CXX_STANDARD 14)

#add_executable(CPlusPlus main.cpp  LinkList.cpp)

#遍历项目根目录下所有的 .cpp 文件
file (GLOB files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file} doubleLink.cpp)
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()
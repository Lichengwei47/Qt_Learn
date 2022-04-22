cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(coingame LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#根据GNU标准定义Binary和Library路径
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
	${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
	${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
	${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")#将字符串格式设置为utf-8,避免在VS中字符串存在换行
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
#打开全局moc,设置自动生成moc文件，一定要设置
set(CMAKE_AUTOMOC ON)
#打开全局uic，非必须
set(CMAKE_AUTOUIC ON)
#打开全局rcc，非必须，如需打开，注意修改33行的qrc文件名
set(CMAKE_AUTORCC ON)

#从anaconda中查找需要的Qt库文件
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Multimedia)
set(QRC_SOURCE_FILES resource.qrc)
#查找当前文件夹中的所有源代码文件，也可以通过Set命令将所有文件设置为一个变量
FILE(GLOB SRC_FILES "./*.cpp")
#查找设置当前文件夹中所有的头文件
FILE(GLOB HEAD_FILES "./*.h")
#查找设置当前文件夹中所有的ui文件
FILE(GLOB UI_FILES "./*.ui")
qt5_add_resources(QRC_FILES ${QRC_SOURCE_FILES})

SOURCE_GROUP("Resource Files" FILES ${QRC_SOURCE_FILES})
#通过Ui文件生成对应的头文件，一定要添加
qt5_wrap_ui(WRAP_FILES ${UI_FILES})
#添加资源文件，非必须，一旦采用，注意修改相应的qrc文件名
set(RCC_FILES resource.qrc)

#将ui文件和生成文件整理在一个文件夹中，非必须
source_group("Ui" FILES ${UI_FILES} ${WRAP_FILES} )
#创建工程文件
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})#ui文件生成的头文件（类似于ui_mainwindow.h） 自动生成在可执行程序的目录中
add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEAD_FILES} ${RCC_FILES} ${WRAP_FILES} ${QRC_FILES})
#添加Qt5依赖项
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Multimedia)
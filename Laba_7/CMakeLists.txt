cmake_minimum_required(VERSION 3.10)
project(Laba_7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Исходные файлы
set(SOURCES
    src/main.cpp
    src/FileReader.cpp
    src/function.cpp
)

# Заголовочные файлы
set(HEADERS
    hdr/FileReader.h
    hdr/function.h
)

# Создаем исполняемый файл
add_executable(file_reader ${SOURCES} ${HEADERS})

# Устанавливаем директорию для заголовочных файлов
target_include_directories(file_reader PRIVATE ${CMAKE_SOURCE_DIR})


# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/kimjw/esp/esp-idf-v5.1-rc2/components/bootloader/subproject"
  "C:/Users/kimjw/OneDrive/Work/Wizmik/esp-idf-example/blink/build/bootloader"
  "C:/Users/kimjw/OneDrive/Work/Wizmik/esp-idf-example/blink/build/bootloader-prefix"
  "C:/Users/kimjw/OneDrive/Work/Wizmik/esp-idf-example/blink/build/bootloader-prefix/tmp"
  "C:/Users/kimjw/OneDrive/Work/Wizmik/esp-idf-example/blink/build/bootloader-prefix/src/bootloader-stamp"
  "C:/Users/kimjw/OneDrive/Work/Wizmik/esp-idf-example/blink/build/bootloader-prefix/src"
  "C:/Users/kimjw/OneDrive/Work/Wizmik/esp-idf-example/blink/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/kimjw/OneDrive/Work/Wizmik/esp-idf-example/blink/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/kimjw/OneDrive/Work/Wizmik/esp-idf-example/blink/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()

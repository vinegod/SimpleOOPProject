add_library(Date
    include/date.hpp
    src/date.cpp
    )

add_library(Student
    include/human.hpp
    src/human.cpp
    include/student.hpp
    src/student.cpp
)

add_library(Research
    include/publication.hpp
    src/publication.cpp
    include/research.hpp
    src/research.cpp
)

target_include_directories(Date PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(Student PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(Research PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(Student PRIVATE Date)
target_link_libraries(Research PRIVATE Student)

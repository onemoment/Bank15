project(bank15)

add_executable(bank15 Tool.cpp Data.cpp main.cpp)

install(TARGETS bank15 RUNTIME DESTINATION bin)

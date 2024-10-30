foreach(target IN ITEMS Adapter Bridge Composite Decorator Filter Facade Flyweight Proxy )
    add_executable(${target}Test ${target}.cpp)
endforeach()
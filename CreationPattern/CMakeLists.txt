foreach(target IN ITEMS FactoryMethod AbstractFactory Builder Prototype Singleton)
    add_executable(${target}Test ${target}.cpp)
endforeach()

foreach(target IN ITEMS ChainOfResponsibility Command Interpreter Iterator Mediator Memento Observer State NullObject Strategy Template Visitor )
    add_executable(${target}Test ${target}.cpp)
endforeach()
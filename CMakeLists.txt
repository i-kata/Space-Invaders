cmake_minimum_required(VERSION 3.1)
# Proszę zmienić wymaganą wersję CMake na niższą - w zupełności wystarczy 3.1

project(test-sfml)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra)

# ustawienia SFML-a dla Linuksa/MacOS i Windows - proszę zostawić obie konfiguracje,
# CMake automatycznie użyje właściwej
if (UNIX)
    # proszę nie modyfkować pierwszego wpisu, można dopisać kolejne katalogi
    # pierwszy wpis powinien poprawnie skonfigurować SFML-a dla wszystkich
    # Debianopodobnych dystrybucji
    set ( CMAKE_MODULES_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})

    # czy ktoś używa MacOS ? Co tam trzeba wpisać ?

endif(UNIX)

if (WIN32)
    # próbujemy linkować statycznie (nie trzeba kopiować plików dll do katalogu projektu)
    set( SFML_STATIC_LIBRARIES TRUE )

    # można zmienić katalog na właściwy
    set ( SFML_DIR "C:\\CLion SFML\\SFML-2.5.1\\lib\\cmake\\SFML")
endif(WIN32)


# to polecenie się wywali, jeśli CMake nie znajdzie SFML-a w jednym ze wskazanych
# wcześniej katalogów - nie ma potrzeby robienia potem if-a dla target_link_libraries
find_package(SFML 2 COMPONENTS graphics audio REQUIRED)

add_executable(MyApp main.cpp SpaceShip.cpp SpaceShip.h Location.h GameController.cpp GameController.h Projectile.cpp Projectile.h Enemy.cpp Enemy.h Barier.cpp Barier.h FinalBoss.cpp FinalBoss.h)

target_link_libraries(MyApp sfml-graphics sfml-audio)

# ABSOLUTNIE I W ŻADNYM WYPADKU nie dodawać wpisu include_directories(${SFML_PATH}/include/SFML/) !!!
# po pierwsze - nie jest potrzebny, po drugie - "dzięki" takim wpisom utrudniacie mi życie
# W kodzie w dyrektywach #include należy obowiązkowo używać konwencji #include <SFML/...>
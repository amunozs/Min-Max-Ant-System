HEADERS     = myqtapp.h Ant.hpp Node.hpp SpaceInformation.hpp Solver.hpp
SOURCES     = myqtapp.cpp main.cpp
FORMS       = myqtapp.ui
QT += widgets
# install
target.path = myqtapp
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS *.pro
sources.path = .
INSTALLS += target sources

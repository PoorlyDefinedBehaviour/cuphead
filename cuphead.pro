TEMPLATE = app
CONFIG += console c++1z
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    entity/entity.cpp \
    util/vector2d/vector2d.cpp \
    animation/animation.cpp \
    game.cpp \
    skills/skill.cpp \
    image/image.cpp \
    skills/ray/ray.cpp \
    skills/boomerang/boomerang.cpp \
    skills/seedmissile/seedmissile.cpp \
    skills/pollen/pollen.cpp \
    skills/venus/venus.cpp \
    events/eventemitter.cpp \
    sdlcontroller/sdlcontroller.cpp

HEADERS += \
    entity/entity.h \
    util/vector2d/vector2d.h \
    animation/animation.h \
    game.h \
    skills/skill.h \
    util/debug/print.h \
    image/image.h \
    shared/animations.h \
    skills/ray/ray.h \
    skills/boomerang/boomerang.h \
    skills/seedmissile/seedmissile.h \
    skills/pollen/pollen.h \
    skills/venus/venus.h \
    events/eventemitter.h \
    sdlcontroller/sdlcontroller.h \
    collision/collision.h \
    shared/constants.h


unix|win32: LIBS += -L$$PWD/dependencies/SDL2-2.0.9/x86_64-w64-mingw32/lib/ -lSDL2

INCLUDEPATH += $$PWD/dependencies/SDL2-2.0.9/x86_64-w64-mingw32/include
DEPENDPATH += $$PWD/dependencies/SDL2-2.0.9/x86_64-w64-mingw32/include

unix|win32: LIBS += -L$$PWD/dependencies/SDL2_image-2.0.5/x86_64-w64-mingw32/lib/ -lSDL2_image

INCLUDEPATH += $$PWD/dependencies/SDL2_image-2.0.5/x86_64-w64-mingw32/include
DEPENDPATH += $$PWD/dependencies/SDL2_image-2.0.5/x86_64-w64-mingw32/include

unix|win32: LIBS += -L$$PWD/dependencies/SDL2_mixer-2.0.4/x86_64-w64-mingw32/lib/ -lSDL2_mixer

INCLUDEPATH += $$PWD/dependencies/SDL2_mixer-2.0.4/x86_64-w64-mingw32/include
DEPENDPATH += $$PWD/dependencies/SDL2_mixer-2.0.4/x86_64-w64-mingw32/include

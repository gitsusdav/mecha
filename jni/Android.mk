LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

# Biblioteca libsqlite3.so
# Prebuilt SQLite library
LOCAL_MODULE := sqlite3
LOCAL_SRC_FILES := /usr/lib/x86_64-linux-gnu/libsqlite3.so 
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
# Biblioteca libcrypto.so
LOCAL_MODULE := crypto
LOCAL_SRC_FILES := /usr/lib/x86_64-linux-gnu/libcrypto.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

# Tu módulo mecha
LOCAL_MODULE := mecha
LOCAL_SRC_FILES := \
    ../lib/src/Apunte.cpp \
    ../lib/src/BaseMecha.cpp \
    ../lib/src/Clase.cpp \
    ../lib/src/Comentario.cpp \
    ../lib/src/ManejoSqlite.cpp \
    ../lib/src/Mecha.cpp \
    ../lib/src/Materia.cpp \
    ../lib/src/NodoFuego.cpp \
    ../lib/src/NodoPadre.cpp \
    ../lib/src/Periodo.cpp \
    ../lib/src/TablaHash.cpp \
    ../lib/src/Usuario.cpp \
    ../lib/src/Utilidades.cpp

# Indica que tu módulo mecha depende de las bibliotecas crypto y sqlite3
LOCAL_SHARED_LIBRARIES := crypto sqlite3

# Incluye las rutas de inclusión necesarias
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../lib/include

# Opciones de compilación adicionales si las necesitas
LOCAL_CFLAGS := -DDEBUG -g -O0

# Esta línea indica al compilador que permita bibliotecas faltantes
APP_ALLOW_MISSING_DEPS=true

# Compila tu biblioteca compartida
include $(BUILD_SHARED_LIBRARY)
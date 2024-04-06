# Nombre del archivo ejecutable
TARGET = rush-02

# Compilador a utilizar
CC = cc

# Opciones de compilación
CFLAGS = -Wall -Wextra -Werror -g

# Archivos fuente
SOURCES = *.c

# Archivos objeto generados durante la compilación
OBJECTS = $(SOURCES:.c=.o)

# Regla principal para generar el ejecutable
$(TARGET): $(OBJECTS)
    $(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

# Regla para compilar cada archivo fuente en un archivo objeto
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los archivos objeto y el ejecutable
clean:
	rm -f $(OBJECTS) $(TARGET)


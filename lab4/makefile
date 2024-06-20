CC = g++
CFLAGS = -g -Wall
OBJS = main.o cliente.o comentario.o compra.o compraProducto.o \
       controladorFecha.o controladorProducto.o controladorUsuario.o \
       DT2Producto.o DTCliente.o DTCompra.o DTCompraProducto.o \
       DTFecha.o DTNotificacion.o DTProducto.o DTPromocion.o \
       DTUsuario.o DTVendedor.o manejadorProducto.o manejadorUsuario.o \
       producto.o productoPromocion.o promocion.o usuario.o vendedor.o

# Regla de compilación principal
program: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o program

# Regla genérica para compilar archivos .cpp a objetos .o
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar archivos generados
clean:
	rm -f *.o program
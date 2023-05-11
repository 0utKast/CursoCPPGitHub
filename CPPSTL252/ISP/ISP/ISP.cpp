#if 0
#include <iostream>

class IProducto {
public:
    virtual void agregarProducto() = 0;
    virtual void eliminarProducto() = 0;
    virtual void actualizarProducto() = 0;
    virtual void listarProductos() = 0;
    virtual void generarReporte() = 0;
};
#endif





#include <iostream>
// Clases abstractas (Interfaces)  definidas aquí.
class IProductoAdmin {
public:
    virtual void agregarProducto() = 0;
    virtual void eliminarProducto() = 0;
    virtual void actualizarProducto() = 0;
};

class IProductoUsuario {
public:
    virtual void listarProductos() = 0;
};

class IProductoReporte {
public:
    virtual void generarReporte() = 0;
};

// Clase que implementa IProductoAdmin
class ProductoAdmin : public IProductoAdmin {
public:
    void agregarProducto() override {
        std::cout << "Producto agregado." << std::endl;
    }

    void eliminarProducto() override {
        std::cout << "Producto eliminado." << std::endl;
    }

    void actualizarProducto() override {
        std::cout << "Producto actualizado." << std::endl;
    }
};

// Clase que implementa IProductoUsuario e IProductoReporte
class ProductoUsuarioReporte : public IProductoUsuario, public IProductoReporte {
public:
    void listarProductos() override {
        std::cout << "Listando productos." << std::endl;
    }

    void generarReporte() override {
        std::cout << "Generando reporte de productos." << std::endl;
    }
};

int main() {
    ProductoAdmin admin;
    admin.agregarProducto();
    admin.eliminarProducto();
    admin.actualizarProducto();

    ProductoUsuarioReporte usuarioReporte;
    usuarioReporte.listarProductos();
    usuarioReporte.generarReporte();

    return 0;
}


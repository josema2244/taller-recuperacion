//Desarrollar un programa que permita realizar las siguientes acciones sobre un inventario
//1. Listar los Productos (Se debe listar los productos con las columnas: 
//                          Numero, Nombre, Categoria, Marca y Precio)
//2. Buscar Productos
//   1.Por Marca (Se debe ingresar la marca a buscar y se debe imprimir todos los productos con esa marca)
//   2.Por Categoria (Se debe ingresar la categoria a buscar y se debe imprimir todos los productos con esa categoria)
//   3.Por precio menor de: (Ingresar el precio limite, se debe imprimir todos los productos con precio menor al ingresado)
//3. Editar Producto (Se debe ingresar el numero del producto y depues editar los campos:
//                      Nombre, categoria, marca y precio)

#include <stdio.h>
#include <string.h>

void listarProductos(char productos[][3][40],double precio[],int indice[]){
    printf("Numero\t Nombre\t     Categoria\t Marca \t Precio\n");
    for(int i = 0; i < 10 ;i++)
    {
        printf("%d\t %s     %s     %s     %.2f\t\n",indice[i],productos[i][0],productos[i][1],productos[i][2],precio[i]);
    }
}

void buscarXMarca(char productos[][3][40],double precio[]){
    char marca[30];
    int contador = 0, found = -1;
    printf("Ingrese el nombre de la marca\n");
    scanf("%s",marca);
    printf("Los productos encontrados son:\n");
    printf("Numero\t Nombre\t     Categoria\t Marca \t Precio\n");

    for(int k = 0; k <10; k++){
        if(strcmp(marca,productos[k][2])==0){
            printf("%d\t %s     %s     %s     %.2f\t\n",contador+1,productos[k][0],productos[k][1],productos[k][2],precio[k]);
            contador++;
            found = 1;
        }
    }

    if(found == -1){
        printf("No se econtro productos con esa Marca\n");
    }
}

void buscarXCategoria(char productos[][3][40],double precio[]){
    char categoria[30];
    int contador = 0, found = -1;
    printf("Ingrese el nombre de la categoria\n");
    scanf("%s",categoria);
    printf("Los productos encontrados son:\n");
    printf("Numero\t Nombre\t     Categoria\t Marca \t Precio\n");


    for(int k = 0; k <10; k++){
        if(strcmp(categoria,productos[k][1])==0){
            printf("%d\t %s     %s     %s     %.2f\t\n",contador+1,productos[k][0],productos[k][1],productos[k][2],precio[k]);
            contador++;
            found = 1;
        }
    }


    if(found == -1){
        printf("No se econtro productos con esa Categoria\n");
    }
}

void buscarXPrecioMenor(char productos[][3][40],double precio[]){
    int indice = 0, found = -1;
    float preciomenor;

    printf("Ingrese el precio limite a buscar\n");
    scanf("%f",&preciomenor);

    printf("El o los productos con menor precio encontrados son:\n");
    printf("Nombre\t     Categoria\t Marca \t Precio\n");
    
    for (int k = 0; k < 10; k++){
        if (precio[k]<preciomenor){
            printf("%d\t %s     %s     %s     %.2f\t\n",indice+1,productos[k][0],productos[k][1],productos[k][2],precio[k]);
            indice++;
            found = 1;
        }
    }

    if(found == -1){
        printf("No se econtro productos con ese limite de precio menor\n");
    }
    
}

void edicion(char productos[][3][40],double precio[],int indice[], int opcion, int opcionedit){
    char nombre[30];
    char categoria[30];
    char marca[30];

    switch (opcionedit)
    {
    case 1:
        printf("Ingrese el nuevo nombre: \n");
        scanf("%s",nombre);
        strcpy(productos[opcion][0],nombre);
        break;
    case 2:
        printf("Ingrese la nueva categoria: \n");
        scanf("%s",categoria);
        strcpy(productos[opcion][1],categoria);
        break;
    case 3: 
        printf("Ingrese la nueva marca: \n");
        scanf("%s",marca);
        strcpy(productos[opcion][2],marca);
        break;
    case 4: 
        getchar();
        float precios;
        printf("Ingrese el nuevo precio: \n");
        scanf("%f",&precios);
        if (precios > 0){
            precio[opcion] = precios;
        }
        else{
            printf("Ingrese valores mayores a 0\n");
        }
        break;
    case 5:
        break;
    default:
        printf("No esta en las opciones de edicion\n");
        break;
    }
    if(opcionedit<5){
        listarProductos(productos, precio, indice);}
}

void editarProducto(char productos[][3][40],double precio[], int indice[]){
    int opcion,opcionedit = 5;
    listarProductos(productos, precio, indice);

    printf("\n\nIngrese el numero del producto a editar\n");
    scanf("%d",&opcion);

    do{
        printf("Ingrese que quiere editar: \n");
        printf("1. Nombre\n");
        printf("2. Categoria\n");
        printf("3. Marca\n");
        printf("4. Precio\n");
        printf("5. Dejar de editar\n");
        scanf("%d", &opcionedit);
        edicion(productos, precio, indice,opcion-1, opcionedit);
    }while (opcionedit != 5);


}
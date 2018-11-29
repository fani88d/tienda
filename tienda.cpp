#include<iostream>
#include<conio.h>
#include<stdlib.h>


using namespace std;

struct Tienda{
	char clave[25];
	int cantidad;
	double precio;
	char nombreProducto[20];
};

struct Nodo{
	Tienda producto;
	Nodo *izquierda,*derecha;
};
struct Cliente{
	char nombre[20];
	int clave;
	double precio;
	double total;
};
struct Nodo2{
	Nodo2 *lista;
	Cliente carrito;
};

void menuprincipal();
void menuSecundario();
void agregarProducto(Tienda &);
void insertarProducto(Nodo *&,Tienda);
void venta(Nodo *&,int&);
void imprimirDatos(Nodo *&);
Nodo *NodoDinamico(Tienda);
//funciones de ahora 
Nodo *arbol=NULL;

int main(){
	
	
	Tienda producto;
	int opcion;
	double caja=0;
	char clave[25];
	int opcion2;
	double totalC;
	int cantidad;
	
	do{
		menuprincipal();
		cin>>opcion;
		switch(opcion){
			case 1:{
				agregarProducto(producto);
				insertarProducto(arbol,producto);
				
				break;
			}
			case 2:{
				do{
					menuSecundario();
					cin>>opcion2;
					switch(opcion2){
						case 1:{
							/*
								agregarProducto();
							}*/
							break;
							
						}
						case 2:{
							cout<<"ingresar la clave del producto: ";
							cin.getline(clave,25,'\n');
							fflush(stdin);
							cout<<"ingresar la cantidad que se le cobrara del producto\n";
							cin>>cantidad;
							break;
						}
					}
					
				}while(opcion2!=5&&opcion2!=6);
				
				break;
			}
			case 3:{
				cout<<"clave\t"<<"nombre\t\t"<<"precio\t\t"<<"cantidad"<<endl;
				imprimirDatos(arbol);
				cout<<"\ndinero en caja\n";
				cout<<caja;
				break;
			}
			default :{
				cout<<"saliendo...........";
				
				break;
			}
			
		}
		getch();
		system("cls");
		
		
	}while(opcion!=4);
	
	return 0;
}

void menuprincipal(){
		cout<<"\n BIENVENIDO A LA TIENDA QUE ELIGE UNA OPCION";
		cout<<"\n 1.-insertar nombres de productos\n";
		cout<<"\n 2.-comprar productos\n";
		cout<<"\n 3.-msotrar productos\n";
		cout<<"\n 4.-salir\n";
		cout<<"\n dijite alguna opcion: ";
		
}

void menuSecundario(){
	cout<<"\nmenu";
	cout<<"\n1.-agregar a mis compras. ";
	cout<<"\n2.-quitar compra";
	cout<<"\n3.-cancelar todo";
	cout<<"\ndijite alguna opcion: ";
	
}

Nodo *NodoDinamico(Tienda producto){
	Nodo *nNodo=new Nodo();
	nNodo->producto=producto;
	nNodo->derecha=NULL;
	nNodo->izquierda=NULL;
	return nNodo;
}


void agregarProducto(Tienda &producto){
	cout << "\ningresar la clave del producto: ";
	fflush(stdin);
	cin.getline(producto.clave,25,'\n');
	cout << "\ningresar el nombre del producto: ";
	fflush(stdin);
	cin.getline(producto.nombreProducto,25,'\n');
	cout << "\ningresar el precio que tendra su producto: ";
	cin >> producto.precio;
	cout << "\ningresar la cantidad de productos: ";
	cin >> producto.cantidad;
}

void insertarProducto(Nodo*& arbol,Tienda producto){
	
	if(arbol==NULL){
		Nodo *nNodo=NodoDinamico(producto);
		arbol=nNodo;
	}else{
		if(producto.precio<arbol->producto.precio){
			insertarProducto(arbol->izquierda,producto);
		}else{
			insertarProducto(arbol->derecha,producto);
		}
	}
}

void imprimirDatos(Nodo *&arbol){
	if(arbol==NULL){
		return;
	}else{
		imprimirDatos(arbol->derecha);
		cout<<arbol->producto.clave<<"\t"<<arbol->producto.nombreProducto<<"\t"<<arbol->producto.precio<<"\t\t"<<arbol->producto.cantidad;
		imprimirDatos(arbol->izquierda);
	}
}
bool stock();



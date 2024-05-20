#include <iostream>
//Creando mi propia estructura de listas -_-
using namespace std;

// Variar el tipo de datos que contenga la lista
template<typename T>
class Lista{
	private:
		struct Nodo{
			T data;
			Nodo* siguiente;
			Nodo(const T &valor) : data(valor), siguiente(nullptr) {} // constructor del Nodo
		};
		
		Nodo* cabeza;
	public:
		Lista() : cabeza(nullptr) {} // constructor de la clase Lista
		
		~Lista(){  // destructor de la clase Lista
			while(cabeza != nullptr){
				Nodo* temp = cabeza;
				cabeza = cabeza->siguiente;
				delete temp; // Utilizo delete para todos los objetos que fueron creados en memoria dinamicamente con el new
			}
		}
		
		void insertar(const T &valor){
			Nodo *nuevoNodo = new Nodo(valor); // Creo nuevo Nodos con la memoria dinámica
			nuevoNodo->siguiente = cabeza; // acceder a las variables miembro del puntero que apunta a un Nodo
			cabeza = nuevoNodo;
		}
			
		// Funcion que muestra en pantalla los elementos de la lista
		void imprimir(){
			Nodo *actual = cabeza;
			while(actual != nullptr){
				cout << actual->data << endl;
				actual = actual->siguiente;
			}
		}
			
		// Funcion que elimina los elementos de una lista segun el valor
		void eliminar(const T &valor){
			if (cabeza == nullptr){
				return;
			}
			
			if (cabeza->data == valor){
				cabeza = cabeza->siguiente;
				return;
			}
			
			Nodo* actual = cabeza;
			while(actual->siguiente->data != valor){
				actual = actual->siguiente;
			}
			
			if(actual->siguiente == nullptr){
				return;
			}
			Nodo* nodo_eliminar = actual->siguiente;
			actual->siguiente = actual->siguiente->siguiente;
			delete nodo_eliminar;
		}
			
		
};
	
int main(int argc, char *argv[]) {
	
	Lista<float> lista;  // Elijo el tipo de datos que mi lista va a soportar
	lista.insertar(2.5);
	lista.insertar(9);
	lista.insertar(10);
	lista.eliminar(2.5);
	lista.imprimir();
	
	return 0;
}


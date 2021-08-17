

#include <iostream>
#include <memory>
#include <thread>

				/*#include <stdio.h>*/

				/*typedef struct {
 					 int x,y;
					} coord, *Coord;

				  void coord_new(Coord c, int x, int y) {
  					c->x = x;
  					c->y = y;
					}
					*/

/*Começamos traduzindo as estruturas e funções do escopo para classes que incorporem nos seus parâmetros e métodos as propriedades definidas no código em C. Deixamos o trecho de código traduzido comentado acima do código em C++ por questão de estudo da linguagem e para observar melhor a "tradução" */

class Coordenada{
	private: 
		int x,y;
	public:
		void set_coordenada(int newx, int newy);	
		};

	void  Coordenada::set_coordenada(int newx, int newy){
		x = newx;
		y = newy;
		};

				/*typedef struct {
 					 int x,y,z;
					} cube, *Cube;

				void cube_new(Cube c, int x, int y, int z) {
  					c->x = x;
  					c->y = y;
 					c->z = z;
					}

				void cube_print_volume(Cube c) {
 					 printf("%d\n", c->x * c->y * c->z);
					}
				*/

class Cube{
	private:
		int x,y,z;
	public:
		void set_cube(int newx, int newy, int newz);
		void vol_show();
	};

	void Cube::set_cube(int newx, int newy, int newz){
		x = newx;
		y = newy;
		z = newz;
	};

	void  Cube::vol_show(){
		std::cout << x*y*z << "\n";
	};

int main() {
	
	/*Inicializa os ponteiros das classes definidas no escopo -- não usa variáveis alocadas na pilha.*/

 	//Coordenada c1;
	std::shared_ptr <Coordenada> c1 (new Coordenada);
 	//Cube c2;
	std::shared_ptr <Cube> c2 (new Cube);
        
        //c1.set_coordenada(50,10);
        //c2.set_cube(10,20,30);
        //c2.vol_show();


	/*Inserção das threads no programa,utilizando os métodos sobre os ponteiros(objetos).*/
	std::thread t1(&Coordenada::set_coordenada, c1, 50, 10);
	std::thread t2(&Cube::set_cube, c2, 10, 20, 30);
	std::thread t3(&Cube::vol_show, c2);

	t1.join();
	t2.join();
	t3.join();

 	 return 0;
}


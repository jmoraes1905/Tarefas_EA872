#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <math.h>

class Model{
	private:
		float m,b,k;
	
	public: 
		void set_parametros(float new_m, float new_b, float new_k);
	
};

	void Model::set_parametros(float new_m, float new_b, float new_k){

	m = new_m;
	b = new_b;
	k = new_k;
	};
	
class Controller{
	private:
	
	public:
		double solve(Model M, float new_m, float new_b, float new_k, int delta, double x_new, double x_old, double vx);
		};
		
double Controller::solve(Model M, float new_m,  float new_b, float new_k, int delta, double x_new, double x_old, double vx){
	
		
		float w, alpha, ww = new_k/new_m; 
		
		w = sqrt(ww);
		alpha = new_b/(new_m*2*w);
		
		if(alpha <1)
			printf("Oscilação subamortecida\n");
			
		else if(alpha ==1)
			printf("Oscilação criticamente amortecida\n");
			
		else
			printf("Oscilação superamortecida\n");
				
		float x, vx_new; // variaveis auxiliares
		
		M.set_parametros(new_m,new_b,new_k);
		// Atualiza a variavel auxiliar x antes de rodar o método	
		x = vx*delta + x_old;
		
		//Novos valores de posição e velocidade
		x_new = (x*(-ww*delta*delta +2) + x_old*(alpha*delta*w -1))/(1 + delta*alpha*w);
		vx_new = (x_new-x_old)/(2*delta);
		
		//Atualiza ponteiros	
		//x_old = x;
		//vx = vx_new;
		return x_new;
		};
			
			
int main(){

float m=1,k=0.5,b=1.0;
Model M;

double x_new, x_old, vx;

x_old = 0;
vx = 1.5;

float  T = 100;

int N = 100, delta, i;

delta = int(T/N);

Controller C;

for(i=0;i<N;i++){
	x_new = C.solve(M,m,b,k,delta,x_new,x_old,vx);
	vx = (x_new-x_old)/(2*delta);
	x_old = x_new;
	std::cout << x_new << "\n";
	}
	
	return 0;
	}




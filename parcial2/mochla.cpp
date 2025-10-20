#include <iostream>
#include <vector>
#include <algorithm> // Para std::max
#include <queue> 

#define MAXOBJ 11
#define MAXMOCH 101

using namespace std;

struct obj{
    int valor, peso;
    float valpeso;
};

bool my_comp(const obj &a, const obj &b){
    return a.valpeso > b.valpeso;
}

int MochilaDP(vector<obj> &datos, int &cantDP, int N, int PESO){
    cantDP = 0;
    int matDP[MAXOBJ][MAXMOCH] = {0};
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= PESO; j++){
            cantDP++; // Contando cada paso en la matriz como una operación
            // Si el peso del objeto actual es mayor que la capacidad de la mochila en esta iteración
            if(datos[i-1].peso > j){
                // No podemos incluir el objeto, así que tomamos el valor de la fila anterior
                matDP[i][j] = matDP[i-1][j];
            }
            else{
                // Comparamos el valor de no incluir el objeto vs. incluirlo
                matDP[i][j] = max(matDP[i-1][j], datos[i-1].valor + matDP[i-1][j-datos[i-1].peso]);
            }
        }
    }
    return matDP[N][PESO];
}
//Complejidad O(2^n)
int MochilaDyV(vector<obj> &datos, int &cantDyV, int N , int PESO){
    // Caso base: no hay más objetos o la capacidad de la mochila es 0 o menor.
    if (N == 0 || PESO <= 0){
        return 0;
    }
    cantDyV++; // Contando cada llamada recursiva como una operación

    // El objeto actual no cabe en la mochila.
    if(datos[N-1].peso > PESO){
        // Pasamos al siguiente objeto sin agregarlo.
        return MochilaDyV(datos, cantDyV, N-1, PESO);
    }
    // Si el objeto cabe, decidimos si es óptimo incluirlo.
    else{
        // Retornamos el máximo valor entre no incluir el objeto y sí incluirlo.
        return max(MochilaDyV(datos, cantDyV, N-1, PESO), // Opción 1: No incluir el objeto.
                    datos[N-1].valor + MochilaDyV(datos, cantDyV, N-1, PESO-datos[N-1].peso)); // Opción 2: Incluir el objeto.
    }
}

int calculaVP(vector<obj> &datos, int i, int valAux, int pesoAux, int N , int PESO){
    int k = i+1;
    // acumula los valores de lso obj siguientes que SI caben. 
    while (k < N && pesoAux+datos[k].peso <= PESO){
        valAux += datos[k].valor;
        pesoAux += datos[k].peso;
        k++;
    }
    // incluir el valor propocional del k-esimo obj si existe
    if (k<N){
        valAux += ((PESO-pesoAux)*datos[k].valpeso); 
    }
    return valAux;
}

//Complejidad O(2^n)
void bt_helper(vector<obj> &datos, int i, int valAcc, int pesoAcc, int valPos, int N, int PESO, int &valOptimo, int &cantBT){
    cantBT++;
    if(i < N && pesoAcc <= PESO && valPos > valOptimo){
        if(valAcc > valOptimo){
            valOptimo = valAcc;
        }
        if(i+1 < N){
            bt_helper(datos, i+1,valAcc+datos[i+1].valor, pesoAcc+datos[i+1].peso, valPos, N, PESO, valOptimo, cantBT);
            int vpAux = calculaVP(datos, i+1, valAcc, pesoAcc, N, PESO);
            bt_helper(datos, i+1, valAcc, pesoAcc, vpAux, N, PESO, valOptimo, cantBT);
        }
    }
}
//complejidad O(2^n)
int MochilaBT(vector<obj> &datos, int &cantBT, int N, int PESO){
    int valOptimo = 0;
    int vAux = calculaVP(datos, -1, 0,0, N, PESO);
    bt_helper(datos, -1, 0, 0, vAux, N, PESO, valOptimo, cantBT);
    return valOptimo;
}

struct node {
    int nivel, valAcc, pesoAcc, valPos;
    node(int nivel, int valAcc, int pesoAcc, int valPos){
        this->nivel = nivel;
        this-> valAcc = valAcc;
        this -> pesoAcc = pesoAcc;
        this -> valPos = valPos;
    }
    bool operator<(const node &otro){
        return this->valPos < otro.valPos;
    }
};

int MochilaBB(vector<obj> &datos, int &cantBB, int N, int PESO){
    priority_queue<node> pq;
    int valOptimo = 0;
    int valPos = calculaVP(datos, -1, 0,0, N, PESO);
    node arranque(-1, 0, 0, valPos);
    cantBB++;
    pq.push(arranque);
    while(!pq.empty()){
        node otro =  pq.top();
        pq.pop();
        if(otro.valAcc > valOptimo){
            valOptimo = otro.valAcc;
        }
        if (otro.valPos > valOptimo){
            if(otro.nivel < N){
                cantBB+=2;
                //no incluir al obj siguiente
                otro.valPos = calculaVP(datos, otro.nivel, otro.valAcc, otro.pesoAcc, N, PESO);
                if(otro.valPos > valOptimo && otro.pesoAcc <= PESO){
                    pq.push(otro);
                }
                //si incluir al obj siguinte
                otro.valAcc += datos[otro.nivel].valor;
                otro.pesoAcc += datos[otro.nivel].peso;
                otro.valPos = calculaVP(datos, otro.nivel, otro.valAcc, otro.pesoAcc, N, PESO);
            }

        }

    }

}

int main(){
    int v, p , N, PESO;

    cin >> N >> PESO;
    vector<obj> datos(N);
    for(int i = 0; i < N; i++){
        cin >> v >> p;
        datos[i].valor = v;
        datos[i].peso = p;
        datos[i].valpeso = v*(1.0)/p;
    }
    cout << "=====================" << endl;
    int cantDP = 0;
    cout << "mochila con DP: " << MochilaDP(datos, cantDP, N, PESO) << endl;
    cout << "Con " << cantDP << " operaciones" << endl;
    

    int cantDyV = 0;
    cout << "=====================" << endl;
    cout << "mochila con DyV: " << MochilaDyV(datos, cantDyV, N, PESO) << endl;
    cout << "Con " << cantDyV << " operaciones" << endl;
    
    // for(int i = 0; i<datos.size(); i++){
    //     cout << datos[i].valor << " " << datos[i].peso << " " << datos[i].valpeso << endl;
    // }
    int cantBT = 0;
    sort(datos.begin(), datos.end(), my_comp);
    cout << "=====================" << endl;
    cout << "mochila con BT: " << MochilaBT(datos, cantBT, N, PESO) << endl;
    cout << "Con " << cantBT << " operaciones" << endl;

    int cantBT = 0;
    sort(datos.begin(), datos.end(), my_comp);
    cout << "=====================" << endl;
    cout << "mochila con BT: " << MochilaBB(datos, cantBT, N, PESO) << endl;
    cout << "Con " << cantBT << " operaciones" << endl;
    
}

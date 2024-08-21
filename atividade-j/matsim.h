struct matsim { 
    int dim; 
    float* v; 
}; 

typedef struct matsim MatSim;

MatSim* criar_matsim(int n);
float acessar_matsim(MatSim* mat, int i, int j);
void atribuir_matsim(MatSim* mat, int i, int j, float v);
void listar_matsim(MatSim* mat);
void liberar_matsim(MatSim* mat);
int dimensao_matsim(MatSim* mat);

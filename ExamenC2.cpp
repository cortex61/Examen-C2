#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Estructura para almacenar un experimento
struct Experimento {
    string nombre;
    string fecha;
    string descripcion;

    Experimento(string n, string f, string d) 
        : nombre(n), fecha(f), descripcion(d) {}
};

// Función para agregar un experimento
void agregarExperimento(vector<Experimento>& experimentos) {
    string nombre, fecha, descripcion;
    cout << "Ingresa el nombre del experimento: ";
    cin.ignore(); // Limpiar el buffer
    getline(cin, nombre);
    cout << "Ingresa la fecha del experimento (YYYY-MM-DD): ";
    cin >> fecha;
    cout << "Ingresa la descripcion del experimento: ";
    cin.ignore(); // Limpiar el buffer
    getline(cin, descripcion);
    experimentos.push_back(Experimento(nombre, fecha, descripcion));
    cout << "Experimento agregado." << endl;
}

// Función para listar todos los experimentos
void listarExperimentos(const vector<Experimento>& experimentos) {
    cout << "Experimentos registrados:" << endl;
    for (size_t i = 0; i < experimentos.size(); i++) {
        cout << (i + 1) << ". " << experimentos[i].nombre 
             << " - " << experimentos[i].fecha << ": " << experimentos[i].descripcion << endl;
    }
}

// Función para buscar experimentos por fecha
void buscarExperimentosPorFecha(const vector<Experimento>& experimentos, const string& fecha) {
    cout << "Experimentos registrados para " << fecha << ":" << endl;
    bool found = false;
    for (size_t i = 0; i < experimentos.size(); i++) {
        if (experimentos[i].fecha == fecha) {
            cout << experimentos[i].nombre << ": " << experimentos[i].descripcion << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No hay experimentos para " << fecha << "." << endl;
    }
}

// Función para eliminar un experimento
void eliminarExperimento(vector<Experimento>& experimentos, int index) {
    if (index >= 0 && index < experimentos.size()) {
        experimentos.erase(experimentos.begin() + index);
        cout << "Experimento eliminado." << endl;
    } else {
        cout << "Indice no valido." << endl;
    }
}

// Función principal
int main() {
    vector<Experimento> experimentos;
    int opcion;

    do {
        cout << "\nSistema de Gestion de Experimentos\n";
        cout << "1. Agregar Experimento\n";
        cout << "2. Listar Experimentos\n";
        cout << "3. Buscar Experimentos por Fecha\n";
        cout << "4. Eliminar Experimento\n";
        cout << "5. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarExperimento(experimentos);
                break;
            case 2:
                listarExperimentos(experimentos);
                break;
            case 3: {
                string fecha;
                cout << "Ingresa la fecha para buscar experimentos: ";
                cin >> fecha;
                buscarExperimentosPorFecha(experimentos, fecha);
                break;
            }
            case 4: {
                int index;
                cout << "Ingresa el numero del experimento a eliminar: ";
                cin >> index;
                eliminarExperimento(experimentos, index - 1); // Ajustar a indice 0
                break;
            }
            case 5:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}

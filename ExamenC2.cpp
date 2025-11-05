#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Recordatorio {
    string descripcion;
    string fecha;
    string hora;

    Recordatorio(string desc, string f, string h) 
        : descripcion(desc), fecha(f), hora(h) {}
};

void agregarRecordatorio(vector<Recordatorio>& recordatorios) {
    string descripcion, fecha, hora;
    cout << "Ingresa la descripcion del recordatorio: ";
    cin.ignore(); // Limpiar el buffer
    getline(cin, descripcion);
    cout << "Ingresa la fecha del recordatorio (YYYY-MM-DD): ";
    cin >> fecha;
    cout << "Ingresa la hora del recordatorio (HH:MM): ";
    cin >> hora;
    recordatorios.push_back(Recordatorio(descripcion, fecha, hora));
    cout << "Recordatorio agregado." << endl;
}

void listarRecordatorios(const vector<Recordatorio>& recordatorios) {
    cout << "Recordatorios programados:" << endl;
    for (size_t i = 0; i < recordatorios.size(); i++) {
        cout << (i + 1) << ". " << recordatorios[i].descripcion 
             << " - " << recordatorios[i].fecha << " a las " << recordatorios[i].hora << endl;
    }
}

void buscarRecordatoriosPorFecha(const vector<Recordatorio>& recordatorios, const string& fecha) {
    cout << "Recordatorios programados para " << fecha << ":" << endl;
    bool found = false;
    for (size_t i = 0; i < recordatorios.size(); i++) {
        if (recordatorios[i].fecha == fecha) {
            cout << recordatorios[i].descripcion << " a las " << recordatorios[i].hora << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No hay recordatorios para " << fecha << "." << endl;
    }
}

void eliminarRecordatorio(vector<Recordatorio>& recordatorios, int index) {
    if (index >= 0 && index < recordatorios.size()) {
        recordatorios.erase(recordatorios.begin() + index);
        cout << "Recordatorio eliminado." << endl;
    } else {
        cout << "Indice no valido." << endl;
    }
}

int main() {
    vector<Recordatorio> recordatorios;
    int opcion;

    do {
        cout << "\nSistema de Gestion de Recordatorios\n";
        cout << "1. Agregar Recordatorio\n";
        cout << "2. Listar Recordatorios\n";
        cout << "3. Buscar Recordatorios por Fecha\n";
        cout << "4. Eliminar Recordatorio\n";
        cout << "5. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarRecordatorio(recordatorios);
                break;
            case 2:
                listarRecordatorios(recordatorios);
                break;
            case 3: {
                string fecha;
                cout << "Ingresa la fecha para buscar recordatorios: ";
                cin >> fecha;
                buscarRecordatoriosPorFecha(recordatorios, fecha);
                break;
            }
            case 4: {
                int index;
                cout << "Ingresa el numero del recordatorio a eliminar: ";
                cin >> index;
                eliminarRecordatorio(recordatorios, index - 1); // Ajustar a indice 0
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

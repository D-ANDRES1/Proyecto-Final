#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Estudiante {
	string nombre;
	string departamento;
	string municipio;
	
};

vector<Estudiante> estudiantes;
vector<vector<string>> departamentos = {
        {"Guatemala", "Guatemala", "Mixco", "Villa Nueva"},
        {"Alta Verapaz", "Cobán", "San Pedro Carchá", "Tucurú"},
        {"Baja Verapaz", "Salamá", "San Miguel Chicaj", "Rabinal"},
        {"Chimaltenango", "Chimaltenango", "San José Poaquil", "Tecuaco"},
        {"Escuintla", "Escuintla", "Santa Lucía Cotzumalguapa", "La Democracia"},
        {"Santa Rosa", "Cuilapa", "Barberena", "San Juan Tecuaco"},
        {"Solala", "Solala", "San José Chacaya", "Santa Catarina Palopo"},
        {"Totonicapán", "Totonicapán", "San Francisco El Alto", "Momostenango"},
        {"Quetzaltenango", "Quetzaltenango", "Colomba", "San Carlos Sija"},
        {"San Marcos", "San Marcos", "Tecoanapa", "San Miguel Ixtahuacán"},
        {"Huehuetenango", "Huehuetenango", "Chiantla", "Cuilco"},
        {"El Progreso", "Guastatoya", "San Antonio La Paz", "Sanarate"},
        {"Jalapa", "Jalapa", "Mataquescuintla", "San Pedro Pinula"},
        {"Zacapa", "Zacapa", "La Union", "Estanzuela"},
        {"Chiquimula", "Chiquimula", "Esquipulas", "San Jose La Arada"},
        {"Petén", "Flores", "San Benito", "Santa Elena"},
        {"Izabal", "Puerto Barrios", "Morales", "El Estor"},
        {"Baja Verapaz", "Salamá", "San Miguel Chicaj", "Rabinal"},
    }; 

void mostrarDyM(Estudiante &nuevoEstudiante){
	 int dptoIndice;
    cout << "Seleccione un departamento:\n";
    cout <<endl;
    for (size_t i = 0; i < departamentos.size(); i++) {
        cout << i + 1 << ". " << departamentos[i][0] << endl;
    }
    cin >> dptoIndice;
    
    if (dptoIndice > 0 && dptoIndice <= departamentos.size()) {
        nuevoEstudiante.departamento = departamentos[dptoIndice - 1][0];

	
	cout << "Municipios en " << nuevoEstudiante.departamento << ":\n";
        for (size_t i = 1; i < departamentos[dptoIndice - 1].size(); i++) {
            cout << i << ". " << departamentos[dptoIndice - 1][i] << endl;
        }
	
	int muniIndice;
        cout << "Seleccione un municipio:\n";
        cin >> muniIndice;
        
    if (muniIndice > 0 && muniIndice <= departamentos[dptoIndice -1].size()){
    	nuevoEstudiante.municipio = departamentos[dptoIndice - 1][muniIndice];
		}
	}else {
		 cout << "Indice de departamento no valido.\n";
	} 
}

void registroEstudiantes() {
	Estudiante nuevoEstudiante;
	
	cout << "Ingrese el nombres del estudiante: "<<endl;
    cin.ignore();
	getline(cin, nuevoEstudiante.nombre);
    
    cout << "Ingrese el departamento del estudiante: "<<endl;
    mostrarDyM(nuevoEstudiante);
    
    estudiantes.push_back(nuevoEstudiante);
	
}
void reportarEstudiantes() {
    if (estudiantes.empty()) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }

    cout << "\n--- Reporte de Estudiantes ---\n";
    for (const auto& estudiante : estudiantes) {
        cout << "Nombre: " << estudiante.nombre << endl;
        cout << "Departamento: " << estudiante.departamento << endl;
        cout << "Municipio: " << estudiante.municipio << endl;
    }
}

int main() {
    int opcion;
    do {
        cout << "\n--- Sistema de Gestion de Estudiantes ---\n";
        cout << "1. Registro de Estudiantes\n";
        cout << "2. Asignacion de cursos\n";
        cout << "3. Control de notas\n";
        cout << "4. Reportes Academicos\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
		cout <<endl; 
        
        switch (opcion) {
            case 1:
                registroEstudiantes();
                break;
            case 2:
                cout << "Funcion\n";
                break;
            case 3:
                cout << "Funcion";
                break;
            case 4:
                reportarEstudiantes();
                break;
            case 5:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opcion no válida.\n";
        }
    } while (opcion != 5);
    
    return 0;
}
 
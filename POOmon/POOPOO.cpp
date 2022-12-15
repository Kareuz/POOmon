#include <iostream>
#include <string>

using namespace std;

class Ataques
{
private:

	int turnos, daño;

public:

	Ataques(int, int);

};

Ataques::Ataques(int _turnos, int _daño)
{
	turnos = _turnos;
	daño = _daño;
}

class Jugador
{
private:

	string nombre;
	
public:

	Jugador(string, int);
	void decir();
	void Ganador(string);
};

Jugador::Jugador(string _nombre, int _exp) {

	nombre = _nombre;
	
}

void Jugador::decir()
{
	cout << "El jugador " << nombre << " elige a: " << endl;

}

void Jugador::Ganador(string _jugador)
{
	cout << _jugador << " gana el combate." << endl;
	
}

class POOmon
{
private:

	string nombre;
	int vida;
	bool muerto = false;
	int daño;
	int exp;

public:

	POOmon(string, int, int);
	int getVida();
	void invocar();
	bool derrotado();
	void Damage(int);
	int Placaje();
	int GolpesFuria();
	int AtqRapido();
	int Latigo();
	void POOganador(string);
};
void POOmon::POOganador(string _poomon) {
	cout << _poomon << " ha recibido 50 puntos de experiencia" << endl;
	exp += 50;
}

POOmon::POOmon(string _nombre, int _vida, int _exp) {

	nombre = _nombre;
	vida = _vida;
	exp = _exp;
}

int POOmon::getVida() {
	return vida;
}

void POOmon::invocar()
{
	cout << nombre << " que tiene " << vida << " puntos de vida" << endl;

}

void POOmon::Damage(int daño) {

	vida -= daño;

}

bool POOmon::derrotado()
{
	if (vida <= 0)
	{
		muerto = true;
	}

	return muerto;
}

int POOmon::Placaje()
{
	daño = 7;
	return daño;
}

int POOmon::GolpesFuria()
{
	daño = 15;
	return daño;

}
int POOmon::Latigo()
{
	daño = 6;
	return daño;
}
int POOmon::AtqRapido()
{
	daño = 10;
	return daño;
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	string nombre1;
	string nombre2;
	string POOname1;
	string POOname2;
	bool derrota = false;
	cout << "Entrenador 1 ingresa tu nombre: ";
	cin >> nombre1;
	cout << "Ingresa el nombre de tu POOmon: ";
	cin >> POOname1;

	cout << "\nEntrenador 2 ingresa tu nombre: ";
	cin >> nombre2;
	cout << "Ingresa el nombre de tu POOmon: ";
	cin >> POOname2;
	cout << "\n";

	Jugador Entrenador1 = Jugador(nombre1, 0);
	Jugador Entrenador2 = Jugador(nombre2, 0);
	POOmon POO1 = POOmon(POOname1, 75, 0);
	POOmon POO2 = POOmon(POOname2, 75, 0);
	Entrenador1.decir();
	POO1.invocar();
	Entrenador2.decir();
	POO2.invocar();

	int turno = rand() % 2 + 1;

	while (derrota == false) {

		if (turno == 1)
		{

			cout << nombre1 << " Escoge tu ataque \n 1.-Latigo  2.Placaje \n 3.-Ataque rapido  4.-Golpes Furia" << endl;
			int opt;
			cin >> opt;

			if (opt == 1)
			{
				POO2.Damage(POO1.Latigo());
			}
			else if (opt == 2)
			{
				POO2.Damage(POO1.Placaje());
			}
			else if (opt == 3)
			{
				POO2.Damage(POO1.AtqRapido());
			}
			else if (opt == 4)
			{
				POO2.Damage(POO1.GolpesFuria());
			}

			cout << POOname2 << " ha recibido el ataque y ahora tiene " << POO2.getVida() << " de vida" << endl;
			turno = 2;

		}

		else if (turno == 2)
		{

			cout << nombre2 << " Escoge tu ataque \n 1.-Latigo  2.Placaje \n 3.-Ataque rapido  4.-Golpes Furia" << endl;
			int opt;
			cin >> opt;

			if (opt == 1)
			{
				POO1.Damage(POO2.Latigo());
			}
			else if (opt == 2)
			{
				POO1.Damage(POO2.Placaje());
			}
			else if (opt == 3)
			{
				POO1.Damage(POO2.AtqRapido());
			}
			else if (opt == 4)
			{
				POO1.Damage(POO2.GolpesFuria());
			}

			cout << POOname1 << " ha recibido el ataque y ahora tiene " << POO1.getVida() << " de vida" << endl;
			turno = 1;
		}

		if (POO1.derrotado() == true)
		{
			cout << POOname1 << " ha sido derrotado ";
			Entrenador2.Ganador(nombre2);
			POO1.POOganador(POOname2);
			derrota = true;
		}
		else if (POO2.derrotado() == true)
		{
			cout << POOname2 << " ha sido derrotado ";
			Entrenador1.Ganador(nombre1);
			POO2.POOganador(POOname1);
			derrota = true;
		}

	}

}
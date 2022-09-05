#ifndef MENU_UTILS_H_
#define MENU_UTILS_H_

#include "../datatypes/DtFecha.h"
#include <string>

using namespace std;

class MenuUtils {
public:
	static void limpiarConsola();
	static int leerInt();
	static string leerString();
	static void esperarInput();
	static DtFecha* leerFecha();
	static bool leerOpcion(const string& msg);
};

#endif /* MENU_UTILS_H_ */

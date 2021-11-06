/*
 * App.h
 *
 *  Created on: 6 jun. 2021
 *      Author: Tester
 */

#ifndef APP_H_
#define APP_H_

class App {
private:
	static float obsoleto;
protected:
	char*nombre;
	float version;
public:
	App();
	App(char* nombre,float version);
	virtual ~App();
	App(const App &other);
	virtual void info();
	float getObsoleto();
	void setObsoleto(float);
	char* getNombre();
	float getVersion();
};

#endif /* APP_H_ */

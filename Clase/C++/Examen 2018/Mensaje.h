#ifndef MENSAJE_H
#define MENSAJE_H

class Mensaje
{
	char * emisor;
	char * texto;

public:
	Mensaje();
	Mensaje(const char *, const char *);
	virtual ~Mensaje();

	const char * getEmisor();
	const char * getMensaje();
	void imprimir();
};

#endif // MENSAJE_H
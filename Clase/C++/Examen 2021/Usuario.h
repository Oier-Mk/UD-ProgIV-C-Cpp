#ifndef USUARIO_H_
#define USUARIO_H_

class Usuario
{
private:
	char* nombre;
	int edad;
public:
	Usuario();
	Usuario(const char*, int);
	Usuario(const Usuario&);
	~Usuario();
	char* getNombre() const;
	void setNombre(const char*);
	int getEdad() const;
	void setEdad(int);
};

#endif /* USUARIO_H_ */
